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

  const float sinTheta = std::sin(theta);
  return Vec3(R * std::cos(phi) * sinTheta, R * std::cos(theta),
              R * std::sin(phi) * sinTheta);
}

// sample points on hemisphere uniformly
inline Vec3 sampleHemisphere(float u, float v, float R, float& pdf) {
  pdf = 1.0f / (2.0f * PI * R * R);
  const float theta = std::acos(std::max(1.0f - u, 0.0f));
  const float phi = 2.0f * PI * v;

  const float sinTheta = std::sin(theta);
  return Vec3(R * std::cos(phi) * sinTheta, R * std::cos(theta),
              R * std::sin(phi) * sinTheta);
}

// sample points on hemisphere propotional to cosine theta
inline Vec3 sampleCosineHemisphere(float u, float v, float R, float& pdf) {
  const float theta = 0.5f * std::acos(std::max(1.0f - 2.0f * u, 0.0f));
  const float phi = 2.0f * PI * v;

  const float sinTheta = std::sin(theta);
  const float cosTheta = std::cos(theta);
  pdf = 1.0f / (PI * R * R) * cosTheta;

  return Vec3(R * std::cos(phi) * sinTheta, R * cosTheta,
              R * std::sin(phi) * sinTheta);
}

#endif