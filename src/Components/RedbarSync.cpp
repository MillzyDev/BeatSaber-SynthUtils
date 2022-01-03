#include "Components/RedbarSync.hpp"
using namespace SynthUtils::Components;

#include "UnityEngine/GameObject.hpp"
#include "UnityEngine/Material.hpp"
using namespace UnityEngine;

#include "main.hpp"

DEFINE_TYPE(SynthUtils::Components, RedbarSync);

void RedbarSync::Start() {
    energyBar = GetComponent<ImageView *>();
    percentage = GameObject::Find(il2cpp_utils::newcsstr("EnergyPercentage"))->GetComponent<TextMeshProUGUI *>();
}

void RedbarSync::Update() {
    percentage->set_color(energyBar->get_color());
}