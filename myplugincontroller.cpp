#pragma once
#include "envelope.h"

class Effects
{
public:
    void prepare(double sampleRate);
    void reset();

    // Called when the Speed knob changes (normalised 0..1)
    // 0 = slowest envelopes, 1 = fastest
    void setEnvelopeSpeeds(float normalizedSpeed);

    float process(float input,
                  float inputDrive,
                  float outputGain,
                  float mu,
                  float character);

private:
    static float convertMu(float normalizedMu, float maxMu = 512.0f);
    static float muLawImpl(float input, float mu);
    static float chebyshev(float x, float t2w, float t3w, float t4w);
    static float applyGain(float input, float normalizedGain, float gainMax);

    EnvelopeFollower mFastEnv;
    EnvelopeFollower mSlowEnv;
    double mSampleRate = 44100.0;
};
