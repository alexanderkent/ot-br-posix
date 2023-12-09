set(CMAKE_CXX_COMPILER "/usr/local/bin/clang++")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=fuzzer,address,undefined")

#// ComputePskc Fuzzer

add_executable(
    pskc-computepskc-fuzzer
    pskc_computepskc_fuzzer.cpp
)

target_link_libraries(pskc-computepskc-fuzzer PRIVATE
    otbr-config
    otbr-common
    otbr-utils
    mbedtls
   -fsanitize=fuzzer,address,undefined
)

target_include_directories(pskc-computepskc-fuzzer  PRIVATE ../../src/utils/)

#// ConvertOpenThreadUint64 Fuzzer

add_executable(
   convert-openthread-uint64-fuzzer 
   convert_openthread_uint64_fuzzer.cpp
)

target_link_libraries(convert-openthread-uint64-fuzzer PRIVATE
    otbr-common
    -fsanitize=fuzzer,address,undefined
)

target_include_directories(convert-openthread-uint64-fuzzer  PRIVATE ../../src/common/)

#// SplitFullDNSName Fuzzer

add_executable(
    split-full-dns-name-fuzzer 
    split_full_dns_name_fuzzer.cpp
)

target_link_libraries(split-full-dns-name-fuzzer PRIVATE
    otbr-common
    -fsanitize=fuzzer,address,undefined
)

target_include_directories(split-full-dns-name-fuzzer  PRIVATE ../../src/common/)

#// Steering-Data Fuzzer

add_executable(
    steering-data-fuzzer
    steering_data_fuzzer.cpp
)

target_link_libraries(steering-data-fuzzer PRIVATE
    otbr-config
    otbr-common
    otbr-utils
    mbedtls
    -fsanitize=fuzzer,address,undefined
)

target_include_directories(steering-data-fuzzer  PRIVATE ../../src/utils/)
