#pragma once
#include <cmath>

//------------------------------------------------------------------------
// EnvelopeFollower
// Dual time-constant envelope follower.
// Two instances are used in the saturation engine:
//   - "fast"  (~5-20ms)  : responds to transients
//   - "slow"  (~100-500ms): models thermal / bias drift
//------------------------------------------------------------------------
class EnvelopeFollower
{
public:
    EnvelopeFollower() = default;

    // Call once when sample rate is known / changes
    void prepare(double sampleRate, float attackMs, float releaseMs)
    {
        mSampleRate = sampleRate;
        setTimes(attackMs, releaseMs);
    }

    void setTimes(float attackMs, float releaseMs)
    {
        mAttackCoeff  = std::exp(-1.0f / (mSampleRate * attackMs  * 0.001f));
        mReleaseCoeff = std::exp(-1.0f / (mSampleRate * releaseMs * 0.001f));
    }

    // Process one sample, returns smoothed envelope level (0..1)
    float process(float input)
    {
        float rectified = std::fabs(input);
        float coeff = (rectified > mEnvelope) ? mAttackCoeff : mReleaseCoeff;
        mEnvelope = coeff * mEnvelope + (1.0f - coeff) * rectified;
        return mEnvelope;
    }

    void reset() { mEnvelope = 0.0f; }

private:
    double mSampleRate  = 44100.0;
    float  mAttackCoeff  = 0.0f;
    float  mReleaseCoeff = 0.0f;
    float  mEnvelope     = 0.0f;
};
