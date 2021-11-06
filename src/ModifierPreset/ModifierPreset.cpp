#include "ModifierPreset/ModifierPreset.hpp"
using namespace SynthUtils::ModifierPreset;

ModifierPreset::ModifierPreset(std::string name, std::function<void(bool)> onToggle) {
    this->_name = name;
    this->_onToggle = onToggle;
}

ModifierPreset::ModifierPreset(std::string name, GameplayModifiers *modifiers, PlayerSpecificSettings *playerSettings,
    std::function<void(bool)> onToggle) {
    this->_name = name;
    this->gameplayModifiers = modifiers;
    this->playerSpecificSettings = playerSettings;
    this->_onToggle = onToggle;
}

std::function<void(bool)> ModifierPreset::getOnToggle() { return this->_onToggle; }

std::string ModifierPreset::getName() { return this->_name; }