#include "ModifierPreset/Builders.hpp"
using namespace SynthUtils::ModifierPreset;

#include "GlobalNamespace/GameplayModifiers.hpp"
#include "GlobalNamespace/PlayerSpecificSettings.hpp"

/*
 * Easy GameplayModifiers wrapper, allowing easy creation of a GameplayModifiers object
 */
GameplayModifiersBuilder *GameplayModifiersBuilder::set_demoNoFail(bool value) {
    this->_gameplayModifiers->demoNoFail = value;
    return this;
}

GameplayModifiersBuilder *GameplayModifiersBuilder::set_demoNoObstacles(bool value) {
    this->_gameplayModifiers->demoNoObstacles = value;
    return this;
}

GameplayModifiersBuilder *GameplayModifiersBuilder::set_disappearingArrows(bool value) {
    this->_gameplayModifiers->disappearingArrows = value;
    return this;
}

GameplayModifiersBuilder *GameplayModifiersBuilder::set_failOnSaberClash(bool value) {
    this->_gameplayModifiers->failOnSaberClash = value;
    return this;
}

GameplayModifiersBuilder *GameplayModifiersBuilder::set_fastNotes(bool value) {
    this->_gameplayModifiers->fastNotes = value;
    return this;
}

GameplayModifiersBuilder *GameplayModifiersBuilder::set_ghostNotes(bool value) {
    this->_gameplayModifiers->ghostNotes = value;
    return this;
}

GameplayModifiersBuilder *GameplayModifiersBuilder::set_instaFail(bool value) {
    this->_gameplayModifiers->instaFail = value;
    return this;
}

GameplayModifiersBuilder *GameplayModifiersBuilder::set_noArrows(bool value) {
    this->_gameplayModifiers->noArrows = value;
    return this;
}

GameplayModifiersBuilder *GameplayModifiersBuilder::set_noBombs(bool value) {
    this->_gameplayModifiers->noBombs = value;
    return this;
}

GameplayModifiersBuilder *GameplayModifiersBuilder::set_noFailOn0Energy(bool value) {
    this->_gameplayModifiers->noFailOn0Energy = value;
    return this;
}

GameplayModifiersBuilder *GameplayModifiersBuilder::set_proMode(bool value) {
    this->_gameplayModifiers->proMode = value;
    return this;
}

GameplayModifiersBuilder *GameplayModifiersBuilder::set_smallCubes(bool value) {
    this->_gameplayModifiers->smallCubes = value;
    return this;
}

GameplayModifiersBuilder *GameplayModifiersBuilder::set_strictAngles(bool value) {
    this->_gameplayModifiers->strictAngles = value;
    return this;
}

GameplayModifiersBuilder *GameplayModifiersBuilder::set_zenMode(bool value) {
    this->_gameplayModifiers->zenMode = value;
    return this;
}

GameplayModifiers *GameplayModifiersBuilder::Build() { return this->_gameplayModifiers; }

GameplayModifiersBuilder::GameplayModifiersBuilder() {}
GameplayModifiersBuilder::GameplayModifiersBuilder(GameplayModifiers *gameplayModifiers) { this->_gameplayModifiers = gameplayModifiers; }

/*
 * Easy PlayerSpecificSettings wrapper, allowing easy creation of a PlayerSpecificSettings object
 */
PlayerSpecificSettingsBuilder *PlayerSpecificSettingsBuilder::set_adaptiveSfx(bool value) {
    this->_playerSpecificSettings->adaptiveSfx = value;
    return this;
}

PlayerSpecificSettingsBuilder *PlayerSpecificSettingsBuilder::set_advancedHud(bool value) {
    this->_playerSpecificSettings->advancedHud = value;
    return this;
}

PlayerSpecificSettingsBuilder *PlayerSpecificSettingsBuilder::set_autoRestart(bool value) {
    this->_playerSpecificSettings->autoRestart = value;
    return this;
}

PlayerSpecificSettingsBuilder *PlayerSpecificSettingsBuilder::set_automaticPlayerHeight(bool value) {
    this->_playerSpecificSettings->automaticPlayerHeight = value;
    return this;
}

PlayerSpecificSettingsBuilder *
PlayerSpecificSettingsBuilder::set_environmentEffectsFilterDefaultPreset(EnvironmentEffectsFilterPreset value) {
    this->_playerSpecificSettings->environmentEffectsFilterDefaultPreset = value;
    return this;
}

PlayerSpecificSettingsBuilder *
PlayerSpecificSettingsBuilder::set_environmentEffectsFilterExpertPlusPreset(EnvironmentEffectsFilterPreset value) {
    this->_playerSpecificSettings->environmentEffectsFilterExpertPlusPreset = value;
    return this;
}

PlayerSpecificSettingsBuilder *PlayerSpecificSettingsBuilder::set_hideNoteSpawnEffect(bool value) {
    this->_playerSpecificSettings->hideNoteSpawnEffect = value;
    return this;
}

PlayerSpecificSettingsBuilder *PlayerSpecificSettingsBuilder::set_leftHanded(bool value) {
    this->_playerSpecificSettings->leftHanded = value;
    return this;
}

PlayerSpecificSettingsBuilder *PlayerSpecificSettingsBuilder::set_noFailEffects(bool value) {
    this->_playerSpecificSettings->noFailEffects = value;
    return this;
}

PlayerSpecificSettingsBuilder *PlayerSpecificSettingsBuilder::set_noTextsAndHuds(bool value) {
    this->_playerSpecificSettings->noTextsAndHuds = value;
    return this;
}

PlayerSpecificSettingsBuilder *PlayerSpecificSettingsBuilder::set_noteJumpStartBeatOffset(float value) {
    this->_playerSpecificSettings->noteJumpStartBeatOffset = value;
    return this;
}

PlayerSpecificSettingsBuilder *PlayerSpecificSettingsBuilder::set_playerHeight(float value) {
    this->_playerSpecificSettings->playerHeight = value;
    return this;
}

PlayerSpecificSettingsBuilder *PlayerSpecificSettingsBuilder::set_reduceDebris(bool value) {
    this->_playerSpecificSettings->reduceDebris = value;
    return this;
}

PlayerSpecificSettingsBuilder *PlayerSpecificSettingsBuilder::set_saberTrailIntensity(float value) {
    this->_playerSpecificSettings->saberTrailIntensity = value;
    return this;
}

PlayerSpecificSettingsBuilder *PlayerSpecificSettingsBuilder::set_sfxVolume(float value) {
    this->_playerSpecificSettings->sfxVolume = value;
    return this;
}

PlayerSpecificSettings *PlayerSpecificSettingsBuilder::Build() { return this->_playerSpecificSettings; }

PlayerSpecificSettingsBuilder::PlayerSpecificSettingsBuilder() {}
PlayerSpecificSettingsBuilder::PlayerSpecificSettingsBuilder(PlayerSpecificSettings *playerSpecificSettings) { this->_playerSpecificSettings = playerSpecificSettings; }