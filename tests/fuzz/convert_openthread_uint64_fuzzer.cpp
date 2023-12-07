#include "code_utils.hpp"

extern "C" int LLVMFuzzerTestOneInput(const uint8_t *Data, size_t Size)
{
    if (Size >= sizeof(uint64_t))
    {
        uint64_t result = ConvertOpenThreadUint64(Data);

        // Check: sum the bytes in Data and compare against result
        uint64_t sum = 0;
        for (size_t i = 0; i < sizeof(uint64_t); ++i)
        {
            sum += Data[i];
        }

        if (result > sum)
        {
            return 1;
        }
    }
    return 0;
}
