#include "IHook.hpp"
using namespace SynthUtils::Hooking;

#include <vector>

namespace SynthUtils::Hooking {
    class HookManager {
    private:
        std::vector<IHook *> _hooks;
        static HookManager *_instance;

        HookManager();

    public:

        static HookManager *GetInstance();

        std::vector<IHook *> RegisterHooks(std::vector<IHook *> hooks);

        IHook *RegisterHook(IHook *hook);

        void InstallHooks();
    };
}