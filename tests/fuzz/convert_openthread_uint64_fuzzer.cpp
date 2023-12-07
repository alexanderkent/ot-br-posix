#include "code_utils.hpp"
#include <fuzzer/FuzzedDataProvider.h>

extern "C" int LLVMFuzzerTestOneInput(const uint8_t *Data, size_t Size)
{
    FuzzedDataProvider stream(Data, Size);

    // Use FuzzedDataProvider to ensure that we always have enough data
    std::vector<uint8_t> fuzzedData = stream.ConsumeBytes<uint8_t>(sizeof(uint64_t));

    // Ensure that we have exactly sizeof(uint64_t) bytes
    if (fuzzedData.size() < sizeof(uint64_t))
    {
        return 0;
    }

    uint64_t result = ConvertOpenThreadUint64(fuzzedData.data());

    // Check: sum the bytes in fuzzedData and compare against result
    uint64_t sum = 0;
    for (size_t i = 0; i < sizeof(uint64_t); ++i)
    {
        sum += fuzzedData[i];
    }

    // Perform more comprehensive checks
    if (result != sum)
    {
        // Potentially interesting case: result should equal sum for valid conversions
        return 1;
    }

    return 0;
}
