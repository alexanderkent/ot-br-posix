set(CMAKE_CXX_COMPILER "/usr/local/bin/clang++")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=fuzzer")

#// ComputePskc Fuzzer

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

#// ConvertOpenThreadUint64 Fuzzer

add_executable(
   convert_openthread_uint64_fuzzer 
   convert_openthread_uint64_fuzzer.cpp
)

target_link_libraries(convert_openthread_uint64_fuzzer PRIVATE
    otbr-common
)

target_include_directories(convert_openthread_uint64_fuzzer  PRIVATE ../../src/common/)

#// split_full_dns_name_fuzzer Fuzzer

add_executable(
    split_full_dns_name_fuzzer 
    split_full_dns_name_fuzzer.cpp
)

target_link_libraries(split_full_dns_name_fuzzer PRIVATE
    otbr-common
)

target_include_directories(split_full_dns_name_fuzzer  PRIVATE ../../src/common/)
