#include "Hooking/HookManager.hpp"
using namespace SynthUtils::Hooking;

#include "main.hpp"

HookManager *HookManager::_instance = nullptr;

HookManager::HookManager() {}

HookManager *HookManager::GetInstance() {
    if (_instance == nullptr) {
        _instance = new HookManager();
    }

    return _instance;
}

std::vector<IHook *> HookManager::RegisterHooks(std::vector<IHook *> hooks) {
    for (IHook *hook : hooks) {
        RegisterHook(hook);
    }

    return this->_hooks;
}

IHook *HookManager::RegisterHook(IHook *hook) {
    this->_hooks.push_back(hook);
    return hook;
}

void HookManager::InstallHooks() {
    for (IHook *hook : this->_hooks) {
        hook->installHooks();
        getLogger().info("Installing Hook %s", hook->getName().c_str());
    }
}