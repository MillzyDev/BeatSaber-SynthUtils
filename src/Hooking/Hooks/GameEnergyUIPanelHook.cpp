#include "main.hpp"

#include "Hooking/Hooks/GameEnergyUIPanelHook.hpp"
using namespace SynthUtils::Hooking::Hooks;

#include "GlobalNamespace/GameEnergyUIPanel.hpp"
using namespace GlobalNamespace;

#include "questui/shared/BeatSaberUI.hpp"
using namespace QuestUI::BeatSaberUI;

#include "UnityEngine/Vector3.hpp"
using namespace UnityEngine;

MAKE_HOOK_MATCH(GameEnergyUIPanel_Start, &GameEnergyUIPanel::Start, void,
    GameEnergyUIPanel *self
) {
    GameEnergyUIPanel_Start(self);

    getLogger().info("Creating EnergyPercentage Canvas...");

    GameObject *percentageCanvas = GameEnergyUIPanelHook::percentageCanvas;
    percentageCanvas = CreateCanvas();
    auto pos = self->get_transform()->get_position();
    percentageCanvas->get_transform()->set_position(pos);
    pos = percentageCanvas->get_transform()->get_position();
    pos.y -= 0.3f;
    percentageCanvas->get_transform()->set_position(pos);
    GameEnergyUIPanelHook::percentage = CreateText(percentageCanvas->get_transform(), "50%");
    GameEnergyUIPanelHook::percentage->set_fontSize(15.0f);
    GameEnergyUIPanelHook::percentage->set_alignment(TextAlignmentOptions::Center);
}

MAKE_HOOK_MATCH(GameEnergyUIPanel_HandleGameEnergyDidChange, &GameEnergyUIPanel::HandleGameEnergyDidChange, void,
    GameEnergyUIPanel *self, float energy
) {
    getLogger().info("Game energy changed to %.0f%%", energy * 100);

    GameEnergyUIPanelHook::percentage->set_text(il2cpp_utils::newcsstr(string_format("%.0f%%", energy * 100)));

    GameEnergyUIPanel_HandleGameEnergyDidChange(self, energy);
}

GameObject *GameEnergyUIPanelHook::percentageCanvas = nullptr;
TextMeshProUGUI *GameEnergyUIPanelHook::percentage = nullptr;

void GameEnergyUIPanelHook::installHooks() {
    INSTALL_HOOK(getLogger(), GameEnergyUIPanel_Start);
    INSTALL_HOOK(getLogger(), GameEnergyUIPanel_HandleGameEnergyDidChange);
}

std::string GameEnergyUIPanelHook::getName() { return "GameEnergyUIPanel"; }