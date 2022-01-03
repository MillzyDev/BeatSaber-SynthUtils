#pragma once

#include "config-utils/shared/config-utils.hpp"

#include "UnityEngine/Vector2.hpp"
using namespace UnityEngine;

DECLARE_CONFIG(ModConfig,
    CONFIG_VALUE(ep_enabled, bool, "EnergyPercentageEnabled", true);
    CONFIG_VALUE(ep_redbarSync, bool, "EnergyPercentageSyncToRedbar", false);
    CONFIG_VALUE(ep_fontSize, float, "EnergyPercentageFontSize", 15.0f);
    CONFIG_VALUE(ep_positionOffset, Vector2, "EnergyPercentagePositionOffset", Vector2(0.0f, -0.4f));
    CONFIG_VALUE(ep_decimalPlaces, int, "EnergyPercentageDecimalPlaces", 0);

    CONFIG_INIT_FUNCTION(
        CONFIG_INIT_VALUE(ep_enabled);
        CONFIG_INIT_VALUE(ep_redbarSync);
        CONFIG_INIT_VALUE(ep_fontSize);
        CONFIG_INIT_VALUE(ep_positionOffset);
        CONFIG_INIT_VALUE(ep_decimalPlaces);
    )
)