set(CMAKE_CXX_COMPILER "/usr/local/bin/clang++")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=fuzzer")


add_executable(
    pskc_computepskc_fuzzer
    pskc_computepskc_fuzzer.cpp
)

target_link_libraries(pskc_computepskc_fuzzer PRIVATE
    otbr-config
    otbr-common
    otbr-utils
    mbedtls
)


target_include_directories(pskc_computepskc_fuzzer  PRIVATE ../../src/utils/)
