#include "main.hpp"

#include "Hooking/SUHooks.hpp"

#include "GlobalNamespace/GameEnergyUIPanel.hpp"
using namespace GlobalNamespace;

#include "questui/shared/BeatSaberUI.hpp"
using namespace QuestUI::BeatSaberUI;

#include "UnityEngine/Vector3.hpp"
using namespace UnityEngine;

#include "TMPro/TextAlignmentOptions.hpp"
#include "TMPro/TextMeshProUGUI.hpp"
using namespace TMPro;

GameObject *percentageCanvas;
TextMeshProUGUI *percentage;

std::string baseFormat = "%%.%if%%%%";
std::string finalFormat;

MAKE_HOOK_MATCH(GameEnergyUIPanel_Start, &GameEnergyUIPanel::Start, void,
    GameEnergyUIPanel *self
) {
    GameEnergyUIPanel_Start(self);

    getLogger().info("%s", to_utf8(csstrtostr(self->energyBar->get_gameObject()->get_name())).c_str());

     if (getModConfig().ep_enabled.GetValue()) {
         getLogger().info("Creating format");
         finalFormat = string_format(baseFormat.c_str(), getModConfig().ep_decimalPlaces.GetValue());

        getLogger().info("Creating EnergyPercentage canvas...");

        percentageCanvas = CreateCanvas();

        getLogger().info("Applying position offset to EnergyPercentage canvas...");
        auto pos = self->get_transform()->get_position();

        pos.x += getModConfig().ep_positionOffset.GetValue().x;
        pos.y += getModConfig().ep_positionOffset.GetValue().y;

        percentageCanvas->get_transform()->set_position(pos);

        getLogger().info("Creating Percentage text...");
        percentage = CreateText(percentageCanvas->get_transform(), string_format(finalFormat.c_str(), 50.0f));
        percentage->set_alignment(TextAlignmentOptions::Center);

        getLogger().info("Setting fontSize...");
        percentage->set_fontSize(getModConfig().ep_fontSize.GetValue());
        getLogger().info("Finished creating EnergyPercentage");
    }
}

MAKE_HOOK_MATCH(GameEnergyUIPanel_HandleGameEnergyDidChange, &GameEnergyUIPanel::HandleGameEnergyDidChange, void,
    GameEnergyUIPanel *self, float energy
) {
    getLogger().info("Game energy changed to %f", energy);

    if (percentage != nullptr)
        percentage->set_text(il2cpp_utils::newcsstr(string_format(finalFormat.c_str(), energy * 100)));

    GameEnergyUIPanel_HandleGameEnergyDidChange(self, energy);
}

void GameEnergyUIPanelHook(Logger &logger) {
    INSTALL_HOOK(logger, GameEnergyUIPanel_Start);
    INSTALL_HOOK(logger, GameEnergyUIPanel_HandleGameEnergyDidChange);
}

InstallHooks(GameEnergyUIPanelHook);