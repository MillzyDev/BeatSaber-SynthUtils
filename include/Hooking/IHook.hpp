#pragma once

#include <string>

namespace SynthUtils::Hooking {
    class IHook {
    public:
        IHook();
        virtual void installHooks();
        virtual std::string getName();
    };
}