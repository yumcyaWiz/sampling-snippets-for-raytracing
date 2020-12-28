#ifndef _SAMPLING_H
#define _SAMPLING_H
#include <algorithm>
#include <cmath>

#include "constant.h"
#include "vec.h"

// sample point on circle uniformly
inline Vec2 sampleCircle(float u, float v, float R, float& pdf) {
  pdf = 1.0f / (PI * R * R);
  const float r = std::sqrt(u);
  const float theta = 2.0f * PI * v;
  return Vec2(r * std::cos(theta), r * std::sin(theta));
}

// sample points on sphere uniformly
inline Vec3 sampleSphere(float u, float v, float R, float& pdf) {
  pdf = 1.0f / (4.0f * PI * R * R);
  const float theta = std::acos(std::max(1.0f - 2.0f * u, 0.0f));
  const float phi = 2.0f * PI * v;
  return Vec3(R * std::cos(phi) * std::sin(theta), R * std::cos(theta),
              R * std::sin(phi) * std::sin(theta));
}

// sample points on hemisphere uniformly
inline Vec3 sampleHemisphere(float u, float v, float R, float& pdf) {
  pdf = 1.0f / (2.0f * PI * R * R);
  const float theta = std::acos(std::max(1.0f - u, 0.0f));
  const float phi = 2.0f * PI * v;
  return Vec3(R * std::cos(phi) * std::sin(theta), R * std::cos(theta),
              R * std::sin(phi) * std::sin(theta));
}

#endif