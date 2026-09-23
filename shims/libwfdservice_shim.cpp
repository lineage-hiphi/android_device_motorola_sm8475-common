#include <utils/Log.h>
#include <utils/Errors.h>
#include <utils/String8.h>
#include <string>

extern "C" {
    // android::AudioSystem::setParameters(int, android::String8 const&)
    int _ZN7android11AudioSystem13setParametersEiRKNS_7String8E(int ioHandle, const android::String8& keyValuePairs) {
        ALOGI("wfdservice_motorola_shim: Intercepted legacy setParameters (ioHandle: %d, kv: %s)", ioHandle, keyValuePairs.c_str());
        return 0; // OK
    }

    // android::AudioSystem::addErrorCallback(void (*)(int))
    void _ZN7android11AudioSystem16addErrorCallbackEPFviE(void (*cb)(int)) {
        ALOGI("wfdservice_motorola_shim: Intercepted legacy addErrorCallback");
    }

    // android::AudioSystem::removeErrorCallback(unsigned long)
    void _ZN7android11AudioSystem19removeErrorCallbackEm(unsigned long cb) {
        ALOGI("wfdservice_motorola_shim: Intercepted legacy removeErrorCallback");
    }

    // android::SurfaceComposerClient::createVirtualDisplay(std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char>> const&, bool, bool, std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char>> const&, float)
    // Note: Older A12-A14 vendor components expect an IBinder StrongPointer back, or a token handle. We return a null/empty IBinder equivalent pointer wrapper.
    void* _ZN7android21SurfaceComposerClient20createVirtualDisplayERKNSt3__112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEEbbS9_f(
        const std::string& name, bool secure, bool publicDisplay, const std::string& displayName, float density) {
        ALOGI("wfdservice_motorola_shim: Intercepted legacy createVirtualDisplay (name: %s)", name.c_str());
        return nullptr;
    }
}


namespace android {
    class String8;
}

// Declare it as a standard C++ function symbol
extern android::String8 _ZN7android11AudioSystem13getParametersEiRKNS_7String8E(int ioHandle, const android::String8& keys);
