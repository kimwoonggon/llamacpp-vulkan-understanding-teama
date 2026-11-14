#include "inspect.h"
#include <iomanip>
#include <initializer_list>
#include <ostream>
#include <sstream>

namespace {
std::string text(const std::string &s, bool html) {
    std::ostringstream out;
    for (unsigned char c : s) {
        if (c < 32 || c == 127) {
            out << "\\x" << std::hex << std::setw(2) << std::setfill('0') << +c;
        } else if (html && c == '&') out << "&amp;";
        else if (html && c == '<') out << "&lt;";
        else if (html && c == '>') out << "&gt;";
        else out << static_cast<char>(c);
    }
    return out.str();
}

class Table {
    std::ostream &out;
    bool html;
    void cells(std::initializer_list<std::string> values, bool header) {
        if (html) out << "<tr>";
        bool first = true;
        for (const auto &v : values) {
            if (html) out << (header ? "<th scope=col>" : "<td>");
            else if (!first) out << " | ";
            out << text(v, html);
            if (html) out << (header ? "</th>" : "</td>");
            first = false;
        }
        out << (html ? "</tr>\n" : "\n");
    }
public:
    Table(std::ostream &o, bool h, const char *title, std::initializer_list<std::string> headings, const char *id = "")
        : out(o), html(h) {
        if (html) out << "<section" << id << "><h2>" << title << "</h2><div class=scroll><table><thead>";
        else out << "\n" << title << "\n";
        cells(headings, true);
        if (html) out << "</thead><tbody>\n";
    }
    void row(std::initializer_list<std::string> values) { cells(values, false); }
    ~Table() { if (html) out << "</tbody></table></div></section>\n"; }
};
}

void report(std::ostream &out, const Inspection &m, bool html) {
    using std::to_string;
    const std::string summary = "GGUF v" + to_string(m.version) + "  ·  " + to_string(m.file_size)
        + " B  ·  정렬 " + to_string(m.alignment) + " B  ·  KV " + to_string(m.metadata.size())
        + "  ·  텐서 " + to_string(m.tensors.size());
    if (html) {
        out << R"(<!doctype html><html lang="ko"><meta charset="utf-8"><meta name="viewport" content="width=device-width,initial-scale=1">
<title>GGUF 파일 분석</title>
<style>
*{box-sizing:border-box}body{margin:0;background:#f3f5f3;color:#183027;font:15px/1.55 "Segoe UI","Malgun Gothic",sans-serif}
header{background:#133b32;color:white;padding:36px max(5vw,20px)}header p{color:#cde7dc}h1{font-size:clamp(22px,3vw,40px);margin:0;overflow-wrap:anywhere}
main{max-width:1520px;margin:auto;padding:20px max(3vw,12px) 50px}section{margin:24px 0}h2{font-size:20px;margin:12px 0}
.scroll{overflow:auto;border:1px solid #ced9d2;border-radius:8px;background:white}table{width:100%;border-collapse:collapse;font-size:14px}
td,th{text-align:left;padding:9px 12px;vertical-align:top;border-bottom:1px solid #e3e9e4}td{font-family:Consolas,"Malgun Gothic",monospace;overflow-wrap:anywhere}
th{background:#e4eee8;white-space:nowrap}tbody tr:hover{background:#f2f8f4}
input{font:inherit;padding:8px 12px;border:1px solid #769487;border-radius:5px;width:min(29em,100%)}code{white-space:normal}
</style><header><h1>)" << text(m.filename,true) << "</h1><p>" << summary << "</p></header><main>";
        qwen2_map(out, m);
    } else out << text(m.filename,false) << "\n" << summary << "\n";
    {
        Table t(out,html,"파일 구획",{"구획","시작 (B)","끝 · 미포함 (B)","길이 (B)","저장 순서"});
        auto section = [&](const char *name, uint64_t start, uint64_t end, const char *layout) {
            t.row({name,to_string(start),to_string(end),to_string(end-start),layout});
        };
        section("Header",0,24,"magic[4] · u32 version · u64 tensor_count · u64 metadata_count");
        section("Metadata KV",24,m.metadata_end,"string key · u32 type · value (string = u64 길이 + 바이트)");
        section("Tensor Info",m.metadata_end,m.info_end,"string name · u32 rank · u64 dims[rank] · u32 type · u64 relative_offset");
        section("Padding",m.info_end,m.data_start,"Tensor Data 시작 전 정렬 바이트");
        section("Tensor Data",m.data_start,m.file_size-m.trailing,"각 텐서의 데이터와 정렬 패딩");
        if (m.trailing) section("추가 바이트",m.file_size-m.trailing,m.file_size,"마지막 구획 뒤의 바이트");
    }
    if (html) out << "<p><strong>헤더 원본</strong> <code>" << m.header_hex << "</code></p>"
        "<label>메타데이터·텐서 검색 <input type=search id=q placeholder=\"이름, 타입, 값\"></label> "
        "<span id=count role=status></span><div id=records>";
    else out << "헤더 원본  " << m.header_hex << "\n";
    {
        Table t(out,html,"메타데이터",{"시작 (B)","끝 · 미포함 (B)","키","타입 · 원소 수","값 · 배열 앞 4개"});
        for (const auto &k : m.metadata)
            t.row({to_string(k.begin),to_string(k.end),k.key,k.type,k.value});
    }
    {
        Table t(out,html,"텐서",{"이름","Shape (ne 순서)","GGML 타입","기술자 위치","상대 위치","파일 위치","데이터 (B)","뒤 패딩 (B)","앞 16 B · hex"}," id='tensor-records'");
        for (const auto &v : m.tensors)
            t.row({v.name,v.shape,v.type,to_string(v.descriptor),to_string(v.relative),to_string(v.absolute),
                   to_string(v.bytes),to_string(v.padding),v.hex});
    }
    if (html) out << R"(</div></main><script>
const rows=Array.from(document.querySelectorAll("#records tbody tr"));
const search=document.querySelector("#q");
function filter(){
 const term=search.value.trim().toLowerCase();
 let visible=0;
 for(const row of rows){row.hidden=!row.textContent.toLowerCase().includes(term);if(!row.hidden)visible++;}
 document.querySelector("#count").textContent=visible+" / "+rows.length+"개";
}
search.addEventListener("input",filter);filter();
</script></html>)";
}
