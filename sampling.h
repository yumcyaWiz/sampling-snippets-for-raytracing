#ifndef _SAMPLING_H
#define _SAMPLING_H
#include <cmath>

#include "constant.h"
#include "vec.h"

// sample point on circle
inline Vec2 sampleCircle(float u, float v, float R, float& pdf) {
  pdf = 1.0f / (4.0f * PI * R * R);
  const float r = std::sqrt(u);
  const float theta = 2.0f * PI * v;
  return Vec2(r * std::cos(theta), r * std::sin(theta));
}

#endif