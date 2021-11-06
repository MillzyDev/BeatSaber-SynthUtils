#pragma once

namespace GlobalNamespace {
    class GameplayModifiers;
    class PlayerSpecificSettings;
    struct EnvironmentEffectsFilterPreset;
}
using namespace GlobalNamespace;

namespace SynthUtils::ModifierPreset {
    class GameplayModifiersBuilder {
    private:
        GameplayModifiers *_gameplayModifiers;
    public:
        GameplayModifiersBuilder *set_noFailOn0Energy(bool value);
        GameplayModifiersBuilder *set_demoNoFail(bool value);
        GameplayModifiersBuilder *set_instaFail(bool value);
        GameplayModifiersBuilder *set_failOnSaberClash(bool value);
        GameplayModifiersBuilder *set_demoNoObstacles(bool value);
        GameplayModifiersBuilder *set_fastNotes(bool value);
        GameplayModifiersBuilder *set_strictAngles(bool value);
        GameplayModifiersBuilder *set_disappearingArrows(bool value);
        GameplayModifiersBuilder *set_ghostNotes(bool value);
        GameplayModifiersBuilder *set_noBombs(bool value);
        GameplayModifiersBuilder *set_noArrows(bool value);
        GameplayModifiersBuilder *set_proMode(bool value);
        GameplayModifiersBuilder *set_zenMode(bool value);
        GameplayModifiersBuilder *set_smallCubes(bool value);

        GameplayModifiers *Build();

        GameplayModifiersBuilder();
        GameplayModifiersBuilder(GameplayModifiers *gameplayModifiers);
    };

    class PlayerSpecificSettingsBuilder {
    private:
        PlayerSpecificSettings *_playerSpecificSettings;
    public:
        PlayerSpecificSettingsBuilder *set_leftHanded(bool value);
        PlayerSpecificSettingsBuilder *set_playerHeight(float value);
        PlayerSpecificSettingsBuilder *set_automaticPlayerHeight(bool value);
        PlayerSpecificSettingsBuilder *set_sfxVolume(float value);
        PlayerSpecificSettingsBuilder *set_reduceDebris(bool value);
        PlayerSpecificSettingsBuilder *set_noTextsAndHuds(bool value);
        PlayerSpecificSettingsBuilder *set_noFailEffects(bool value);
        PlayerSpecificSettingsBuilder *set_advancedHud(bool value);
        PlayerSpecificSettingsBuilder *set_autoRestart(bool value);
        PlayerSpecificSettingsBuilder *set_saberTrailIntensity(float value);
        PlayerSpecificSettingsBuilder *set_noteJumpStartBeatOffset(float value);
        PlayerSpecificSettingsBuilder *set_hideNoteSpawnEffect(bool value);
        PlayerSpecificSettingsBuilder *set_adaptiveSfx(bool value);
        PlayerSpecificSettingsBuilder *set_environmentEffectsFilterDefaultPreset(EnvironmentEffectsFilterPreset value);
        PlayerSpecificSettingsBuilder *set_environmentEffectsFilterExpertPlusPreset(EnvironmentEffectsFilterPreset value);

        PlayerSpecificSettings *Build();

        PlayerSpecificSettingsBuilder();
        PlayerSpecificSettingsBuilder(PlayerSpecificSettings *playerSpecificSettings);
    };
}