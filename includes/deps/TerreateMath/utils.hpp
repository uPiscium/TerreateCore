#ifndef __TC_MATH_UTILS_HPP__
#define __TC_MATH_UTILS_HPP__

#include <cmath>

#include "defines.hpp"
#include "matrixNxM.hpp"
#include "quaternion.hpp"
#include "vectorColumn.hpp"
#include "vectorRow.hpp"

namespace TerreateMath::Utils {
using namespace TerreateMath::Defines;
using namespace TerreateMath::Core;
using namespace TerreateMath::Vector;
using namespace TerreateMath::Matrix;

template <typename T> T Radian(T const &degree) {
  return degree * static_cast<T>(TM_PI) / static_cast<T>(180);
}
template <typename T> T Degree(T const &radian) {
  return radian * static_cast<T>(180) / static_cast<T>(TM_PI);
}

template <typename T> Matrix4x4<T> Scale(T const &x, T const &y, T const &z);
template <typename T> Matrix4x4<T> Scale(RowVector3D<T> const &scale) {
  return Scale(scale[0], scale[1], scale[2]);
}
template <typename T> Matrix4x4<T> Scale(ColumnVector3D<T> const &scale) {
  return Scale(scale[0], scale[1], scale[2]);
}
template <typename T> Matrix4x4<T> Scale(T const &scale) {
  return Scale(scale, scale, scale);
}

template <typename T>
Matrix4x4<T> Translate(T const &x, T const &y, T const &z);
template <typename T> Matrix4x4<T> Translate(RowVector3D<T> const &position) {
  return Translate(position[0], position[1], position[2]);
}
template <typename T>
Matrix4x4<T> Translate(ColumnVector3D<T> const &position) {
  return Translate(position[0], position[1], position[2]);
}

template <typename T>
Quaternion::Quaternion<T> Rotate(T const &angle, T const &x, T const &y,
                                 T const &z);
template <typename T>
Quaternion::Quaternion<T> Rotate(T const &angle, RowVector3D<T> const &axis) {
  return Rotate(angle, axis[0], axis[1], axis[2]);
}
template <typename T>
Quaternion::Quaternion<T> Rotate(T const &angle,
                                 ColumnVector3D<T> const &axis) {
  return Rotate(angle, axis[0], axis[1], axis[2]);
}

template <typename T> Quaternion::Quaternion<T> RotateX(T const &angle) {
  return Rotate(angle, static_cast<T>(1), static_cast<T>(0), static_cast<T>(0));
}
template <typename T> Quaternion::Quaternion<T> RotateY(T const &angle) {
  return Rotate(angle, static_cast<T>(0), static_cast<T>(1), static_cast<T>(0));
}
template <typename T> Quaternion::Quaternion<T> RotateZ(T const &angle) {
  return Rotate(angle, static_cast<T>(0), static_cast<T>(0), static_cast<T>(1));
}

template <typename T>
Quaternion::Quaternion<T> Rotate(T const &angX, T const &angY, T const &angZ) {
  return RotateX(angX) * RotateY(angY) * RotateZ(angZ);
}

template <typename T>
Matrix4x4<T> LookAt(ColumnVector3D<T> const &eye,
                    ColumnVector3D<T> const &center,
                    ColumnVector3D<T> const &up);
template <typename T>
Matrix4x4<T> LookAt(RowVector3D<T> const &eye, RowVector3D<T> const &center,
                    RowVector3D<T> const &up) {
  return LookAt(eye.AcquireTransposed(), center.AcquireTransposed(),
                up.AcquireTransposed());
}
template <typename T>
Matrix4x4<T> LookAt(T const &eyeX, T const &eyeY, T const &eyeZ,
                    T const &centerX, T const &centerY, T const &centerZ,
                    T const &upX, T const &upY, T const &upZ) {
  return LookAt(RowVector3D<T>(eyeX, eyeY, eyeZ),
                RowVector3D<T>(centerX, centerY, centerZ),
                RowVector3D<T>(upX, upY, upZ));
}

template <typename T>
Matrix4x4<T> Perspective(T const &fov, T const &near, T const &far);
template <typename T>
Matrix4x4<T> Orthographic(T const &left, T const &right, T const &bottom,
                          T const &top, T const &near, T const &far);
template <typename T>
Matrix4x4<T> Orthographic(T const &left, T const &right, T const &top,
                          T const &bottom) {
  return Orthographic(left, right, top, bottom, static_cast<T>(-1),
                      static_cast<T>(1));
}

template <typename T>
MatrixBase<T> Lerp(MatrixBase<T> const &a, MatrixBase<T> const &b, T const &t) {
  return a * (static_cast<T>(1) - t) + b * t;
}
template <typename T>
Quaternion::Quaternion<T> Lerp(Quaternion::Quaternion<T> const &a,
                               Quaternion::Quaternion<T> const &b, T const &t) {
  return a * (static_cast<T>(1) - t) + b * t;
}
} // namespace TerreateMath::Utils

// Implementation
namespace TerreateMath::Utils {
template <typename T> Matrix4x4<T> Scale(T const &x, T const &y, T const &z) {
  Matrix4x4<T> result = Eye<T>(4);
  result(0, 0) = x;
  result(1, 1) = y;
  result(2, 2) = z;
  return result;
}

template <typename T>
Matrix4x4<T> Translate(T const &x, T const &y, T const &z) {
  Matrix4x4<T> result = Eye<T>(4);
  result(0, 3) = x;
  result(1, 3) = y;
  result(2, 3) = z;
  return result;
}

template <typename T>
Quaternion::Quaternion<T> Rotate(T const &angle, T const &x, T const &y,
                                 T const &z) {
  T const halfAngle = angle / static_cast<T>(2);
  T const s = sin(halfAngle);
  return Quaternion::Quaternion<T>(x * s, y * s, z * s, cos(halfAngle));
}

template <typename T>
Matrix4x4<T> LookAt(ColumnVector3D<T> const &eye,
                    ColumnVector3D<T> const &center,
                    ColumnVector3D<T> const &up) {
  ColumnVector3D<T> front = Normalize(center - eye);
  ColumnVector3D<T> right = Normalize(Cross(front, up));
  ColumnVector3D<T> upper = Cross(right, front);

  Matrix4x4<T> result = Eye<T>(4);
  result(0, 0) = right[0];
  result(0, 1) = right[1];
  result(0, 2) = right[2];
  result(1, 0) = upper[0];
  result(1, 1) = upper[1];
  result(1, 2) = upper[2];
  result(2, 0) = front[0];
  result(2, 1) = front[1];
  result(2, 2) = front[2];
  result(0, 3) = -(eye * right);
  result(1, 3) = -(eye * upper);
  result(2, 3) = -(eye * front);
  return result;
}

template <typename T>
Matrix4x4<T> Perspective(T const &fov, T const &near, T const &far) {
  T const cot = static_cast<T>(1) / tan(fov / static_cast<T>(2));
  Matrix4x4<T> result = Eye<T>(4);
  result(0, 0) = cot;
  result(1, 1) = cot;
  result(2, 2) = far / (far - near);
  result(2, 3) = -far * near / (far - near);
  result(3, 2) = static_cast<T>(1);
  return result;
}

template <typename T>
Matrix4x4<T> Orthographic(T const &left, T const &right, T const &bottom,
                          T const &top, T const &near, T const &far) {
  Matrix4x4<T> result = Eye<T>(4);
  result(0, 0) = static_cast<T>(2) / (right - left);
  result(1, 1) = static_cast<T>(2) / (top - bottom);
  result(2, 2) = static_cast<T>(2) / (near - far);
  result(0, 3) = -(right + left) / (right - left);
  result(1, 3) = -(top + bottom) / (top - bottom);
  result(2, 3) = -(far + near) / (far - near);
  return result;
}
} // namespace TerreateMath::Utils
#endif // __TC_MATH_UTILS_HPP__
