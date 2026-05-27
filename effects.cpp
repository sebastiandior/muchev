//------------------------------------------------------------------------
// Copyright(c) 2024 Hikari Audio.
//------------------------------------------------------------------------

#pragma once

#include "public.sdk/source/vst/vstaudioeffect.h"
#include "effects.h"

namespace MyCompanyName {

class muLawProcessor : public Steinberg::Vst::AudioEffect
{
public:
    muLawProcessor();
    ~muLawProcessor() SMTG_OVERRIDE;

    static Steinberg::FUnknown* createInstance(void* /*context*/)
    {
        return (Steinberg::Vst::IAudioProcessor*)new muLawProcessor();
    }

    Steinberg::tresult PLUGIN_API initialize(Steinberg::FUnknown* context) SMTG_OVERRIDE;
    Steinberg::tresult PLUGIN_API terminate()  SMTG_OVERRIDE;
    Steinberg::tresult PLUGIN_API setActive(Steinberg::TBool state) SMTG_OVERRIDE;
    Steinberg::tresult PLUGIN_API setupProcessing(Steinberg::Vst::ProcessSetup& newSetup) SMTG_OVERRIDE;
    Steinberg::tresult PLUGIN_API canProcessSampleSize(Steinberg::int32 symbolicSampleSize) SMTG_OVERRIDE;
    Steinberg::tresult PLUGIN_API process(Steinberg::Vst::ProcessData& data) SMTG_OVERRIDE;
    Steinberg::tresult PLUGIN_API setState(Steinberg::IBStream* state) SMTG_OVERRIDE;
    Steinberg::tresult PLUGIN_API getState(Steinberg::IBStream* state) SMTG_OVERRIDE;

protected:
    Steinberg::Vst::ParamValue mInputDrive = 0.25;
    Steinberg::Vst::ParamValue mOutputGain = 0.5;
    Steinberg::Vst::ParamValue mMu         = 0.5;
    Steinberg::Vst::ParamValue mCharacter  = 0.0;
    Steinberg::Vst::ParamValue mSpeed      = 0.5;
    Steinberg::Vst::ParamValue mBypass     = 0.0;

    static constexpr int kMaxChannels = 2;
    Effects mEffects[kMaxChannels];
};

} // namespace MyCompanyName
