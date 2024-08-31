#ifndef __TERREATECORE_MATH_HPP__
#define __TERREATECORE_MATH_HPP__

#include <glm/ext.hpp>
#include <glm/glm.hpp>

#include "defines.hpp"

namespace TerreateCore::Math {
using namespace TerreateCore::Defines;

// glm constants
const Float PI = glm::pi<Float>();
const Float HALF_PI = glm::half_pi<Float>();

// glm types
typedef glm::vec2 vec2;
typedef glm::vec3 vec3;
typedef glm::vec4 vec4;
typedef glm::mat2 mat2;
typedef glm::mat3 mat3;
typedef glm::mat4 mat4;
typedef glm::quat quat;

// glm functions
using glm::abs;
using glm::acos;
using glm::asin;
using glm::atan;
using glm::ceil;
using glm::clamp;
using glm::cos;
using glm::degrees;
using glm::distance;
using glm::exp;
using glm::floor;
using glm::fract;
using glm::inverse;
using glm::length;
using glm::lerp;
using glm::log;
using glm::max;
using glm::min;
using glm::mix;
using glm::mod;
using glm::pow;
using glm::radians;
using glm::reflect;
using glm::refract;
using glm::round;
using glm::sign;
using glm::sin;
using glm::smoothstep;
using glm::sqrt;
using glm::step;
using glm::tan;
using glm::transpose;

// glm matrix functions
using glm::determinant;
using glm::identity;
using glm::inverse;
using glm::lookAt;
using glm::ortho;
using glm::perspective;
using glm::rotate;
using glm::scale;
using glm::translate;

// glm vector functions
using glm::cross;
using glm::dot;
using glm::normalize;

// glm quaternion functions
using glm::angleAxis;
using glm::conjugate;
using glm::dot;
using glm::inverse;
using glm::length;
using glm::mix;
using glm::normalize;
using glm::slerp;

} // namespace TerreateCore::Math

#endif // __TERREATECORE_MATH_HPP__
