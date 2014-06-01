#ifndef CONVERT_HPP_INCLUDED
#define CONVERT_HPP_INCLUDED

#include <cmath>

static inline float rad_to_deg(float rad)
{
    return rad * 180 / M_PI;
}

static inline float deg_to_rad(float deg)
{
    return deg * M_PI / 180;
}

#endif
