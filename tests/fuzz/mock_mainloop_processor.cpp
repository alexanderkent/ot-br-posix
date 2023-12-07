#include "common/mainloop_processor.hpp"

class MockMainloopProcessor : public otbr::MainloopProcessor {
public:
    MockMainloopProcessor() = default;
    virtual ~MockMainloopProcessor() = default;

void MockMainloopProcessor::Update(otbr::MainloopContext &aMainloop) override {
    // Example: Set a file descriptor in aMainloop.mReadFdSet
    FD_SET(someFd, &aMainloop.mReadFdSet);
    aMainloop.mMaxFd = std::max(aMainloop.mMaxFd, someFd);
}

void MockMainloopProcessor::Process(const otbr::MainloopContext &aMainloop) override {
    // Example: Check if a file descriptor is set and perform an action
    if (FD_ISSET(someFd, &aMainloop.mReadFdSet)) {
        // Perform some mock processing
    }
    }
};
