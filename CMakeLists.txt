cmake_minimum_required(VERSION 3.24)
project(llama-vulkan-lab LANGUAGES C CXX)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

set(GGML_VULKAN ON CACHE BOOL "Build Vulkan backend")
set(LLAMA_BUILD_COMMON ON CACHE BOOL "Build common helpers")
set(LLAMA_BUILD_EXAMPLES OFF CACHE BOOL "Only add the study example")
set(LLAMA_BUILD_TESTS OFF CACHE BOOL "Study build")
set(LLAMA_BUILD_TOOLS OFF CACHE BOOL "Study build")
set(LLAMA_BUILD_SERVER OFF CACHE BOOL "Study build")
set(LLAMA_BUILD_APP OFF CACHE BOOL "Study build")
set(LLAMA_OPENSSL OFF CACHE BOOL "Local model only")
add_subdirectory(llama.cpp)
add_subdirectory(llama.cpp/examples/simple study-simple)
if(MSVC)
    target_compile_options(llama-simple PRIVATE /utf-8)
endif()

set_property(DIRECTORY PROPERTY VS_STARTUP_PROJECT llama-simple)
set_target_properties(llama-simple PROPERTIES
    VS_DEBUGGER_COMMAND_ARGUMENTS "-m \"${CMAKE_SOURCE_DIR}/models/qwen2.5-1.5b-instruct-fp16.gguf\" -ngl 99 -n 48 \"The capital of South Korea is\""
    VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}"
    VS_DEBUGGER_ENVIRONMENT "GGML_VK_VISIBLE_DEVICES=0")

add_custom_target(study-map SOURCES
    README-KO.md
    llama.cpp/src/models/qwen2.cpp
    llama.cpp/src/llama-graph.cpp
    llama.cpp/src/llama-context.cpp
    llama.cpp/ggml/src/ggml-backend.cpp
    llama.cpp/ggml/src/ggml-vulkan/ggml-vulkan.cpp
    llama.cpp/ggml/src/ggml-vulkan/vulkan-shaders/mul_mat_vec.comp)
add_subdirectory(gguf-inspector)
