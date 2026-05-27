#include "effects.h"
#include "vstmath.h"
#include <cmath>

void Effects::prepare(double sampleRate)
{
    mSampleRate = sampleRate;
    mFastEnv.prepare(sampleRate, 5.0f,  50.0f);
    mSlowEnv.prepare(sampleRate, 80.0f, 400.0f);
}

void Effects::reset()
{
    mFastEnv.reset();
    mSlowEnv.reset();
}

void Effects::setEnvelopeSpeeds(float n)
{
    // n=0: slowest  fast=(20ms/200ms)  slow=(320ms/1600ms)
    // n=0.5: medium fast=(5ms/50ms)    slow=(80ms/400ms)
    // n=1: fastest  fast=(1ms/10ms)    slow=(20ms/100ms)
    float fastAtk  = 20.0f  - n * 19.0f;
    float fastRel  = 200.0f - n * 190.0f;
    float slowAtk  = 320.0f - n * 300.0f;
    float slowRel  = 1600.0f- n * 1500.0f;
    mFastEnv.prepare(mSampleRate, fastAtk, fastRel);
    mSlowEnv.prepare(mSampleRate, slowAtk, slowRel);
}

float Effects::convertMu(float normalizedMu, float maxMu)
{
    return 1.0f + normalizedMu * maxMu;
}

float Effects::muLawImpl(float input, float mu)
{
    return VstMath::sign(input) * (std::log(1.0f + mu * std::fabs(input))
                                   / std::log(1.0f + mu));
}

float Effects::chebyshev(float x, float t2w, float t3w, float t4w)
{
    float T2 = 2.0f*x*x - 1.0f;
    float T3 = 4.0f*x*x*x - 3.0f*x;
    float T4 = 8.0f*x*x*x*x - 8.0f*x*x + 1.0f;
    float harmonics = t2w*T2 + t3w*T3 + t4w*T4;
    float harmonicMix = t2w + t3w + t4w;
    return x + harmonicMix * harmonics;
}

float Effects::applyGain(float input, float normalizedGain, float gainMax)
{
    return input * VstMath::rescale(normalizedGain, gainMax);
}

float Effects::process(float input, float inputDrive, float outputGain,
                       float mu, float character)
{
    float driven    = applyGain(input, inputDrive, 4.0f);
    float fastLevel = mFastEnv.process(driven);
    float slowLevel = mSlowEnv.process(driven);

    float clamped  = VstMath::clamp(driven, -1.0f, 1.0f);
    float muShaped = muLawImpl(clamped, convertMu(mu));

    float t2Base = 0.30f*(1.0f-character) + 0.05f*character;
    float t3Base = 0.05f*(1.0f-character) + 0.30f*character;

    float slowShift = slowLevel * 0.25f;
    float t2w = VstMath::clamp(t2Base - slowShift, 0.0f, 0.5f);
    float t3w = VstMath::clamp(t3Base + slowShift, 0.0f, 0.5f);
    float t4w = VstMath::clamp(fastLevel * 0.08f,  0.0f, 0.15f);
    t2w = VstMath::clamp(t2w + fastLevel*0.1f,     0.0f, 0.5f);

    float chebyInput = VstMath::clamp(muShaped, -1.0f, 1.0f);
    float harmonicOut = chebyshev(chebyInput, t2w, t3w, t4w);

    float shaped = VstMath::clamp(harmonicOut, -1.5f, 1.5f);
    shaped = shaped / (1.0f + std::fabs(shaped) * 0.5f);

    return applyGain(shaped, outputGain, 8.0f);
}
