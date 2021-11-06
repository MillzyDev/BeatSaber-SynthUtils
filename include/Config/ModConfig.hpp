#pragma once

#include "config-utils/shared/config-utils.hpp"

#include "UnityEngine/Vector2.hpp"
using namespace UnityEngine;

DECLARE_CONFIG(ModConfig,
    CONFIG_VALUE(sp_enabled, bool, "ScorePercentageEnabled", false);
    CONFIG_VALUE(sp_redbarSync, bool, "ScorePercentageSyncToRedbar", false);
    CONFIG_VALUE(sp_fontSize, float, "ScorePercentageFontSize", 15.0f);
    CONFIG_VALUE(sp_positionOffset, Vector2, "ScorePercentagePositionOffset", Vector2(0.0f, -0.3f));

    CONFIG_VALUE(vm_enabled, bool, "VisualModeEnabled", false);

    CONFIG_INIT_FUNCTION(
        CONFIG_INIT_VALUE(sp_enabled);
        CONFIG_INIT_VALUE(sp_redbarSync);
        CONFIG_INIT_VALUE(sp_fontSize);
        CONFIG_INIT_VALUE(sp_positionOffset);
    )
)