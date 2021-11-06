#pragma once

#include <vector>
#include <string>

namespace SynthUtils::ModifierPreset {
    class ModifierPreset;

    class ModifierPresetManager {
    private:
        std::vector<ModifierPreset *> _modifierPresets;
        static ModifierPresetManager *_instance;

        ModifierPresetManager();

    public:
        static ModifierPresetManager *GetInstance();

        std::vector<ModifierPreset *> RegisterModifierPresets(std::vector<ModifierPreset *> modifierPresets);

        ModifierPreset *RegisterModifierPreset(ModifierPreset *modifierPreset);

        bool RefreshModifierPresetUI();

        ModifierPreset *FindModifierPreset(std::string query);
    };
}