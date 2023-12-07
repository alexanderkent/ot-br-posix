#include "pskc.hpp"
#include <cstddef>
#include <cstdint>
#include <string>

extern "C" int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size)
{
    // Ensure there's enough data to create meaningful inputs
    if (size < 20)
    {
        return 0;
    }

    // Split the input data into three parts for aExtPanId, aNetworkName, and aPassphrase
    size_t         third_size   = size / 3;
    const uint8_t *aExtPanId    = data; // First part for aExtPanId
    const char    *aNetworkName = reinterpret_cast<const char *>(data + third_size);
    const char    *aPassphrase  = reinterpret_cast<const char *>(data + 2 * third_size);

    // Call the function under test
    otbr::Psk::Pskc pskc;
    const uint8_t  *comp_pskc = pskc.ComputePskc(aExtPanId, aNetworkName, aPassphrase);
    if (comp_pskc == nullptr)
    {
        return 1;
    }

    return 0;
}
