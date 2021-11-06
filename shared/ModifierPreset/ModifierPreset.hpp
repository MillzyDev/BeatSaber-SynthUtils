#pragma once

#include "GlobalNamespace/GameplayModifiers.hpp"
#include "GlobalNamespace/PlayerSpecificSettings.hpp"
using namespace GlobalNamespace;

#include <string>
#include <functional>

namespace SynthUtils::ModifierPreset {
    class ModifierPreset {
    private:
        std::function<void(bool)> _onToggle;
        std::string _name;
    public:
        GameplayModifiers *gameplayModifiers = GameplayModifiers::New_ctor();
        PlayerSpecificSettings *playerSpecificSettings = PlayerSpecificSettings::New_ctor();

        std::function<void(bool)> getOnToggle();
        std::string getName();

        ModifierPreset(std::string name, std::function<void(bool)> onToggle = nullptr);
        ModifierPreset(std::string name, GameplayModifiers *modifiers, PlayerSpecificSettings *playerSettings, std::function<void(bool)> onToggle = nullptr);
    };
}