#include "custom-types/shared/macros.hpp"

#include "UnityEngine/MonoBehaviour.hpp"
using namespace UnityEngine;

#include "HMUI/ImageView.hpp"
using namespace HMUI;

DECLARE_CLASS_CODEGEN(SynthUtils::Components, RedbarSync, MonoBehaviour,
    DECLARE_INSTANCE_FIELD(ImageView *, energyBar);

    DECLARE_INSTANCE_METHOD(void, Start);
    DECLARE_INSTANCE_METHOD(void, Update);
)