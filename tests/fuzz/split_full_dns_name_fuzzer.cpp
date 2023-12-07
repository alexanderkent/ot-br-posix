#include <cassert>
#include <cstddef>
#include <cstdint>
#include <fuzzer/FuzzedDataProvider.h>
#include <string>
#include "common/dns_utils.hpp"

extern "C" int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size)
{
    FuzzedDataProvider stream(data, size);

    // Generate a base DNS name string
    std::string baseDnsName = stream.ConsumeRandomLengthString();

    // Ensure the string contains at least one dot for valid DNS formatting
    if (baseDnsName.find('.') == std::string::npos)
    {
        baseDnsName.insert(stream.ConsumeIntegralInRange<size_t>(0, baseDnsName.length()), ".");
    }

    // Optionally add transport protocols to some of the inputs
    if (stream.ConsumeBool())
    {
        std::string protocol = stream.ConsumeBool() ? "._udp." : "._tcp.";
        baseDnsName.insert(stream.ConsumeIntegralInRange<size_t>(0, baseDnsName.length()), protocol);
    }

    // Call the target function with the fuzzed DNS name
    DnsNameInfo result = SplitFullDnsName(baseDnsName);

    return 0;
}
