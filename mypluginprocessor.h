#include "vstmath.h"
#include <algorithm>

int VstMath::sign(float x)
{
    return (x >= 0.0f) ? 1 : -1;
}

float VstMath::rescale(float x, float maxX)
{
    if (maxX > 2.0f)
    {
        if (x <= 0.5f)
            return 2.0f * x;
        else
            return 2.0f * (maxX - 1.0f) * (x - 0.5f) + 1.0f;
    }
    return x * maxX;
}

float VstMath::clamp(float x, float lo, float hi)
{
    return std::max(lo, std::min(hi, x));
}
