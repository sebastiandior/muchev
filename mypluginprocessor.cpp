#pragma once

class VstMath
{
public:
    // Returns -1 for negative, +1 for zero or positive
    static int sign(float x);

    // Two-segment rescaler.
    // If maxX > 2: maps [0, 0.5] linearly to [0, 1]
    //              and  [0.5, 1] linearly to [1, maxX]
    // Otherwise:   simple linear scale to [0, maxX]
    static float rescale(float x, float maxX);

    // Clamp x to [-1, 1]  (needed before Chebyshev evaluation)
    static float clamp(float x, float lo = -1.0f, float hi = 1.0f);
};
