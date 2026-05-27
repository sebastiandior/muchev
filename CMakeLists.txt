//------------------------------------------------------------------------
// Copyright(c) 2024 Hikari Audio.
//------------------------------------------------------------------------

#pragma once

#include "public.sdk/source/vst/vsteditcontroller.h"
#include "vstgui/plugin-bindings/vst3editor.h"

namespace MyCompanyName {

//------------------------------------------------------------------------
//  muLawController
//------------------------------------------------------------------------
class muLawController : public Steinberg::Vst::EditControllerEx1,
                        public VSTGUI::VST3EditorDelegate
{
public:
    muLawController()  = default;
    ~muLawController() SMTG_OVERRIDE = default;

    static Steinberg::FUnknown* createInstance(void* /*context*/)
    {
        return (Steinberg::Vst::IEditController*)new muLawController;
    }

    //--- IPluginBase ----------------------------------------------------
    Steinberg::tresult PLUGIN_API initialize(Steinberg::FUnknown* context) SMTG_OVERRIDE;
    Steinberg::tresult PLUGIN_API terminate()  SMTG_OVERRIDE;

    //--- EditController -------------------------------------------------
    Steinberg::tresult PLUGIN_API setComponentState(Steinberg::IBStream* state) SMTG_OVERRIDE;
    Steinberg::IPlugView* PLUGIN_API createView(Steinberg::FIDString name) SMTG_OVERRIDE;
    Steinberg::tresult PLUGIN_API setState(Steinberg::IBStream* state) SMTG_OVERRIDE;
    Steinberg::tresult PLUGIN_API getState(Steinberg::IBStream* state) SMTG_OVERRIDE;

    DEFINE_INTERFACES
    END_DEFINE_INTERFACES(EditController)
    DELEGATE_REFCOUNT(EditController)
};

//------------------------------------------------------------------------
} // namespace MyCompanyName
