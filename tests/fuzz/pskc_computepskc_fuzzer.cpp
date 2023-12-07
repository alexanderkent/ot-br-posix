#include "pskc.hpp"
#include <cstddef>
#include <cstdint>
#include <fuzzer/FuzzedDataProvider.h>
#include <string>

/**
 * Constants.
 */
enum
{
    kMaxNetworkName = 16,
    kMaxPassphrase  = 255,
    kSizeExtPanId   = 8,
};

extern "C" int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size)
{
    FuzzedDataProvider stream(data, size);

    // Generate aExtPanId
    std::vector<uint8_t> aExtPanId = stream.ConsumeBytes<uint8_t>(kSizeExtPanId);
    if (aExtPanId.size() != kSizeExtPanId)
    {
        return 0;
    }

    // Generate aNetworkName
    std::string aNetworkName = stream.ConsumeRandomLengthString(kMaxNetworkName);

    // Generate aPassphrase
    std::string aPassphrase = stream.ConsumeRandomLengthString(kMaxPassphrase);

    // Call the function under test
    otbr::Psk::Pskc pskc;
    const uint8_t  *comp_pskc = pskc.ComputePskc(aExtPanId.data(), aNetworkName.c_str(), aPassphrase.c_str());
    if (comp_pskc == nullptr)
    {
        return 1;
    }

    return 0;
}
