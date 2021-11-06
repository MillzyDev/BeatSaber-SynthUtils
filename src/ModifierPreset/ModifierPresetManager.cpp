#include "ModifierPreset/ModifierPresetManager.hpp"
#include "ModifierPreset/ModifierPreset.hpp"
using namespace SynthUtils::ModifierPreset;

ModifierPresetManager *ModifierPresetManager::_instance;

ModifierPresetManager *ModifierPresetManager::GetInstance() {
    if (ModifierPresetManager::_instance == nullptr)
        ModifierPresetManager::_instance = new ModifierPresetManager();

    return ModifierPresetManager::_instance;
}

// TODO: below
bool ModifierPresetManager::RefreshModifierPresetUI() {
    return false;
}

std::vector<ModifierPreset *>
ModifierPresetManager::RegisterModifierPresets(std::vector<ModifierPreset *> modifierPresets) {
    for (auto modifierPreset : modifierPresets) {
        RegisterModifierPreset(modifierPreset);
    }
    return modifierPresets;
}

ModifierPreset *ModifierPresetManager::RegisterModifierPreset(ModifierPreset *modifierPreset) {
    this->_modifierPresets.push_back(modifierPreset);
    return modifierPreset;
}

ModifierPreset *find(std::string query, std::vector<ModifierPreset *> library) {
    for (ModifierPreset *modifierPreset : library) {
        if (modifierPreset->getName() == query)
                return modifierPreset;

    }

    return nullptr;
}

ModifierPreset *ModifierPresetManager::FindModifierPreset(std::string query) {
    return find(query, this->_modifierPresets);
}

ModifierPresetManager::ModifierPresetManager() {}