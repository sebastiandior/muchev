//------------------------------------------------------------------------
// Copyright(c) 2024 Hikari Audio.
//------------------------------------------------------------------------

#include "mypluginprocessor.h"
#include "myplugincids.h"
#include "base/source/fstreamer.h"
#include "pluginterfaces/vst/ivstparameterchanges.h"
#include "public.sdk/source/vst/vstaudioprocessoralgo.h"

using namespace Steinberg;

namespace MyCompanyName {

muLawProcessor::muLawProcessor()
{
    setControllerClass(kmuLawControllerUID);
}

muLawProcessor::~muLawProcessor() {}

tresult PLUGIN_API muLawProcessor::initialize(FUnknown* context)
{
    tresult result = AudioEffect::initialize(context);
    if (result != kResultOk)
        return result;

    addAudioInput (STR16("Stereo In"),  Steinberg::Vst::SpeakerArr::kStereo);
    addAudioOutput(STR16("Stereo Out"), Steinberg::Vst::SpeakerArr::kStereo);
    return kResultOk;
}

tresult PLUGIN_API muLawProcessor::terminate()
{
    return AudioEffect::terminate();
}

tresult PLUGIN_API muLawProcessor::setActive(TBool state)
{
    if (state)
        for (auto& fx : mEffects) fx.reset();
    return AudioEffect::setActive(state);
}

tresult PLUGIN_API muLawProcessor::setupProcessing(Vst::ProcessSetup& newSetup)
{
    for (auto& fx : mEffects)
        fx.prepare(newSetup.sampleRate);
    return AudioEffect::setupProcessing(newSetup);
}

tresult PLUGIN_API muLawProcessor::canProcessSampleSize(int32 symbolicSampleSize)
{
    return (symbolicSampleSize == Vst::kSample32) ? kResultTrue : kResultFalse;
}

tresult PLUGIN_API muLawProcessor::process(Vst::ProcessData& data)
{
    if (data.inputParameterChanges)
    {
        int32 numParams = data.inputParameterChanges->getParameterCount();
        for (int32 i = 0; i < numParams; i++)
        {
            auto* q = data.inputParameterChanges->getParameterData(i);
            if (!q) continue;
            Vst::ParamValue v;
            int32 offset;
            int32 n = q->getPointCount();
            if (q->getPoint(n - 1, offset, v) != kResultTrue) continue;
            switch (q->getParameterId())
            {
                case kParamInputDrive: mInputDrive = v; break;
                case kParamOutputGain: mOutputGain = v; break;
                case kParamMu:         mMu         = v; break;
                case kParamCharacter:  mCharacter  = v; break;
                case kParamSpeed:      mSpeed      = v;
                    // Re-scale envelope times based on speed knob:
                    // speed=0 -> slow (attack 160ms / 800ms release)
                    // speed=0.5 -> medium (80ms / 400ms)
                    // speed=1 -> fast (20ms / 100ms)
                    for (auto& fx : mEffects)
                        fx.setEnvelopeSpeeds((float)mSpeed);
                    break;
                case kParamBypass:     mBypass     = v; break;
                default: break;
            }
        }
    }

    if (data.numInputs == 0 || data.numSamples == 0)
        return kResultOk;

    if (data.inputs[0].silenceFlags != 0)
    {
        data.outputs[0].silenceFlags = data.inputs[0].silenceFlags;
        uint32 sz = getSampleFramesSizeInBytes(processSetup, data.numSamples);
        void** in  = getChannelBuffersPointer(processSetup, data.inputs[0]);
        void** out = getChannelBuffersPointer(processSetup, data.outputs[0]);
        int32 numCh = data.inputs[0].numChannels;
        for (int32 ch = 0; ch < numCh; ch++)
            if (in[ch] != out[ch]) memset(out[ch], 0, sz);
        return kResultOk;
    }

    data.outputs[0].silenceFlags = 0;

    int32 numCh = data.inputs[0].numChannels;
    void** in  = getChannelBuffersPointer(processSetup, data.inputs[0]);
    void** out = getChannelBuffersPointer(processSetup, data.outputs[0]);

    bool bypassed = (mBypass >= 0.5);

    for (int32 ch = 0; ch < numCh && ch < kMaxChannels; ch++)
    {
        Vst::Sample32* pIn  = (Vst::Sample32*)in[ch];
        Vst::Sample32* pOut = (Vst::Sample32*)out[ch];
        int32 samples = data.numSamples;

        if (bypassed)
        {
            // Pass through — still tick the envelope followers so they
            // don't pop when bypass is disengaged
            while (--samples >= 0)
                *pOut++ = *pIn++;
        }
        else
        {
            while (--samples >= 0)
            {
                *pOut++ = mEffects[ch].process(
                    *pIn++,
                    (float)mInputDrive,
                    (float)mOutputGain,
                    (float)mMu,
                    (float)mCharacter
                );
            }
        }
    }

    return kResultOk;
}

// getState: HOST pulls state OUT — we WRITE
tresult PLUGIN_API muLawProcessor::getState(IBStream* state)
{
    if (!state) return kResultFalse;
    IBStreamer s(state, kLittleEndian);
    s.writeFloat((float)mInputDrive);
    s.writeFloat((float)mOutputGain);
    s.writeFloat((float)mMu);
    s.writeFloat((float)mCharacter);
    s.writeFloat((float)mSpeed);
    s.writeFloat((float)mBypass);
    return kResultOk;
}

// setState: HOST pushes saved state IN — we READ
tresult PLUGIN_API muLawProcessor::setState(IBStream* state)
{
    if (!state) return kResultFalse;
    IBStreamer s(state, kLittleEndian);
    float v = 0.f;
    if (!s.readFloat(v)) return kResultFalse; mInputDrive = v;
    if (!s.readFloat(v)) return kResultFalse; mOutputGain = v;
    if (!s.readFloat(v)) return kResultFalse; mMu         = v;
    if (!s.readFloat(v)) return kResultFalse; mCharacter  = v;
    if (!s.readFloat(v)) return kResultFalse; mSpeed      = v;
    if (!s.readFloat(v)) return kResultFalse; mBypass     = v;
    return kResultOk;
}

} // namespace MyCompanyName
