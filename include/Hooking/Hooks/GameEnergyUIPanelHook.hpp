#pragma once

#include <string>

#include "Hooking/IHook.hpp"
using namespace SynthUtils::Hooking;

#include "UnityEngine/GameObject.hpp"
using namespace UnityEngine;

#include "TMPro/TextMeshProUGUI.hpp"
using namespace TMPro;

namespace SynthUtils::Hooking::Hooks {
    class GameEnergyUIPanelHook : public IHook {
    public:
        static GameObject *percentageCanvas;
        static TextMeshProUGUI *percentage;

        void installHooks() override;
        std::string getName() override;
    };
}