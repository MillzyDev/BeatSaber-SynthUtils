#include "Hooking/IHook.hpp"
using namespace SynthUtils::Hooking;

IHook::IHook() {}

void IHook::installHooks() {}
std::string IHook::getName() { return this.name; }