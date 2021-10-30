#include <string>

namespace SynthUtils::Hooking {
    class IHook {
    protected:
        std::string name;
    public:
        IHook();
        virtual void installHooks();
        std::string getName();
    };
}

