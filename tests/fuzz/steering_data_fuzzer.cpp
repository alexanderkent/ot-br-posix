#include "steering_data.hpp"
#include <fuzzer/FuzzedDataProvider.h>
#include <string>
#include <vector>

//#define VERBOSE 1

using namespace otbr;

extern "C" int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size)
{
    FuzzedDataProvider stream(data, size);

    SteeringData computer;
    int          length = stream.ConsumeIntegralInRange<int>(1, SteeringData::kMaxSizeOfBloomFilter);

    computer.Init(static_cast<uint8_t>(length));

    while (stream.remaining_bytes() > 0)
    {
        // Generate a string that mimics EUI64 input
        std::string eui64 = stream.ConsumeRandomLengthString(SteeringData::kSizeJoinerId * 2);
        uint8_t     joinerId[SteeringData::kSizeJoinerId];

        // Call ComputeJoinerId
        SteeringData::ComputeJoinerId(reinterpret_cast<const uint8_t *>(eui64.c_str()), joinerId);

        // Compute bloom filter with the joinerId
        computer.ComputeBloomFilter(joinerId);
    }

// Log the bloom filter for analysis
#ifdef VERBOSE
    for (int i = 0; i < length; i++)
    {
        printf("%02x", computer.GetBloomFilter()[i]);
    }
    printf("\n");
#endif

    return 0;
}
