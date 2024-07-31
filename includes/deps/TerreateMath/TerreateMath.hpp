#ifndef __TC_MATH_MATH_HPP__
#define __TC_MATH_MATH_HPP__

#include "complex.hpp"
#include "core.hpp"
#include "fraction.hpp"
#include "matrixNxM.hpp"
#include "quaternion.hpp"
#include "utils.hpp"
#include "vectorColumn.hpp"
#include "vectorRow.hpp"

namespace TerreateMath::Math {
using namespace TerreateMath::Defines;

template <typename T> using complexT = Complex::Complex<T>;
template <typename T> using fractionT = Fraction::Fraction<T>;
template <typename T> using matrixT = Core::MatrixBase<T>;

template <typename T> using vec2T = Vector::ColumnVector2D<T>;
template <typename T> using vec3T = Vector::ColumnVector3D<T>;
template <typename T> using vec4T = Vector::ColumnVector4D<T>;

template <typename T> using mat2T = Matrix::Matrix2x2<T>;
template <typename T> using mat2x3T = Matrix::Matrix2x3<T>;
template <typename T> using mat2x4T = Matrix::Matrix2x4<T>;
template <typename T> using mat3x2T = Matrix::Matrix3x2<T>;
template <typename T> using mat3T = Matrix::Matrix3x3<T>;
template <typename T> using mat3x4T = Matrix::Matrix3x4<T>;
template <typename T> using mat4x2T = Matrix::Matrix4x2<T>;
template <typename T> using mat4x3T = Matrix::Matrix4x3<T>;
template <typename T> using mat4T = Matrix::Matrix4x4<T>;

template <typename T> using quaternionT = Quaternion::Quaternion<T>;

using complex = complexT<Float>;
using fraction = fractionT<Int>;
using matrix = matrixT<Float>;

using vec2 = vec2T<Float>;
using vec3 = vec3T<Float>;
using vec4 = vec4T<Float>;

using mat2 = mat2T<Float>;
using mat2x3 = mat2x3T<Float>;
using mat2x4 = mat2x4T<Float>;
using mat3x2 = mat3x2T<Float>;
using mat3 = mat3T<Float>;
using mat3x4 = mat3x4T<Float>;
using mat4x2 = mat4x2T<Float>;
using mat4x3 = mat4x3T<Float>;
using mat4 = mat4T<Float>;

using quat = quaternionT<Float>;
} // namespace TerreateMath::Math

#endif // __TC_MATH_MATH_HPP__
