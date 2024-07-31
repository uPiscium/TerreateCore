#ifndef __TC_MATH_MATRIXNXM_HPP__
#define __TC_MATH_MATRIXNXM_HPP__

#include "core.hpp"
#include "defines.hpp"
#include "matrixNxN.hpp"

namespace TerreateMath::Matrix {
using namespace TerreateMath::Defines;
using namespace TerreateMath::Core;
using namespace TerreateMath::Vector;

template <typename T> class MatrixNxM : public MatrixBase<T> {
public:
  MatrixNxM() : MatrixBase<T>() {}
  MatrixNxM(Uint const &row, Uint const &column) : MatrixBase<T>(row, column) {}
  MatrixNxM(Uint const &row, Uint const &column, T const *array)
      : MatrixBase<T>(row, column, array) {}
  MatrixNxM(Uint const &row, Uint const &column, T const &value)
      : MatrixBase<T>(row, column, value) {}
  MatrixNxM(Uint const &row, Uint const &column, Vec<T> const &value)
      : MatrixBase<T>(row, column, value) {}
  MatrixNxM(Vec<Vec<T>> const &value) : MatrixBase<T>(value) {}
  MatrixNxM(MatrixNxM<T> const &other) : MatrixBase<T>(other) {}
  MatrixNxM(MatrixNxM<T> &&other) noexcept : MatrixBase<T>(std::move(other)) {}
  MatrixNxM(MatrixBase<T> const &other) : MatrixBase<T>(other) {}
  template <typename U>
  MatrixNxM(Uint const &row, Uint const &column, U const *array)
      : MatrixBase<T>(row, column, array) {}
  template <typename U>
  MatrixNxM(Uint const &row, Uint const &column, U const &value)
      : MatrixBase<T>(row, column, value) {}
  template <typename U>
  MatrixNxM(Uint const &row, Uint const &column, Vec<U> const &value)
      : MatrixBase<T>(row, column, value) {}
  template <typename U>
  MatrixNxM(Vec<Vec<U>> const &value) : MatrixBase<T>(value) {}
  template <typename U>
  MatrixNxM(MatrixNxM<U> const &other) : MatrixBase<T>(other) {}
  template <typename U>
  MatrixNxM(MatrixBase<U> const &other) : MatrixBase<T>(other) {}

  MatrixNxM<T> &operator=(T const &value);
  MatrixNxM<T> &operator=(Vec<T> const &value);
  MatrixNxM<T> &operator=(Vec<Vec<T>> const &value);
  MatrixNxM<T> &operator=(MatrixNxM<T> const &other);
  MatrixNxM<T> &operator=(MatrixNxM<T> &&other);
  MatrixNxM<T> &operator=(MatrixBase<T> const &other);
  MatrixNxM<T> &operator=(MatrixBase<T> &&other);
};

template <typename T> class Matrix2x3 : public MatrixNxM<T> {
public:
  Matrix2x3() : MatrixNxM<T>(2, 3) {}
  Matrix2x3(T const *array) : MatrixNxM<T>(2, 3, array) {}
  Matrix2x3(T const &value) : MatrixNxM<T>(2, 3, value) {}
  Matrix2x3(Vec<T> const &value) : MatrixNxM<T>(2, 3, value) {}
  Matrix2x3(Vec<Vec<T>> const &value) : MatrixNxM<T>(value) {}
  Matrix2x3(Matrix2x3<T> const &other) : MatrixNxM<T>(other) {}
  Matrix2x3(MatrixBase<T> const &other) : MatrixNxM<T>(other) {}
  Matrix2x3(Matrix2x3<T> &&other) noexcept : MatrixNxM<T>(std::move(other)) {}
  template <typename U> Matrix2x3(U const *array) : MatrixNxM<T>(2, 3, array) {}
  template <typename U> Matrix2x3(U const &value) : MatrixNxM<T>(2, 3, value) {}
  template <typename U>
  Matrix2x3(Vec<U> const &value) : MatrixNxM<T>(2, 3, value) {}
  template <typename U>
  Matrix2x3(Vec<Vec<U>> const &value) : MatrixNxM<T>(value) {}
  template <typename U>
  Matrix2x3(Matrix2x3<U> const &other) : MatrixNxM<T>(other) {}
  template <typename U>
  Matrix2x3(MatrixBase<U> const &other) : MatrixNxM<T>(other) {}

  Matrix2x3<T> &operator=(T const &value);
  Matrix2x3<T> &operator=(Vec<T> const &value);
  Matrix2x3<T> &operator=(Vec<Vec<T>> const &value);
  Matrix2x3<T> &operator=(Matrix2x3<T> const &other);
  Matrix2x3<T> &operator=(Matrix2x3<T> &&other);
  Matrix2x3<T> &operator=(MatrixBase<T> const &other);
  Matrix2x3<T> &operator=(MatrixBase<T> &&other);
};

template <typename T> class Matrix2x4 : public MatrixNxM<T> {
public:
  Matrix2x4() : MatrixNxM<T>(3, 2) {}
  Matrix2x4(T const *array) : MatrixNxM<T>(3, 2, array) {}
  Matrix2x4(T const &value) : MatrixNxM<T>(3, 2, value) {}
  Matrix2x4(Vec<T> const &value) : MatrixNxM<T>(3, 2, value) {}
  Matrix2x4(Vec<Vec<T>> const &value) : MatrixNxM<T>(value) {}
  Matrix2x4(Matrix2x4<T> const &other) : MatrixNxM<T>(other) {}
  Matrix2x4(MatrixBase<T> const &other) : MatrixNxM<T>(other) {}
  Matrix2x4(Matrix2x4<T> &&other) noexcept : MatrixNxM<T>(std::move(other)) {}
  template <typename U> Matrix2x4(U const *array) : MatrixNxM<T>(3, 2, array) {}
  template <typename U> Matrix2x4(U const &value) : MatrixNxM<T>(3, 2, value) {}
  template <typename U>
  Matrix2x4(Vec<U> const &value) : MatrixNxM<T>(3, 2, value) {}
  template <typename U>
  Matrix2x4(Vec<Vec<U>> const &value) : MatrixNxM<T>(value) {}
  template <typename U>
  Matrix2x4(Matrix2x4<U> const &other) : MatrixNxM<T>(other) {}
  template <typename U>
  Matrix2x4(MatrixBase<U> const &other) : MatrixNxM<T>(other) {}

  Matrix2x4<T> &operator=(T const &value);
  Matrix2x4<T> &operator=(Vec<T> const &value);
  Matrix2x4<T> &operator=(Vec<Vec<T>> const &value);
  Matrix2x4<T> &operator=(Matrix2x4<T> const &other);
  Matrix2x4<T> &operator=(Matrix2x4<T> &&other);
  Matrix2x4<T> &operator=(MatrixBase<T> const &other);
  Matrix2x4<T> &operator=(MatrixBase<T> &&other);
};

template <typename T> class Matrix3x2 : public MatrixNxM<T> {
public:
  Matrix3x2() : MatrixNxM<T>(3, 2) {}
  Matrix3x2(T const *array) : MatrixNxM<T>(3, 2, array) {}
  Matrix3x2(T const &value) : MatrixNxM<T>(3, 2, value) {}
  Matrix3x2(Vec<T> const &value) : MatrixNxM<T>(3, 2, value) {}
  Matrix3x2(Vec<Vec<T>> const &value) : MatrixNxM<T>(value) {}
  Matrix3x2(Matrix3x2<T> const &other) : MatrixNxM<T>(other) {}
  Matrix3x2(MatrixBase<T> const &other) : MatrixNxM<T>(other) {}
  Matrix3x2(Matrix3x2<T> &&other) noexcept : MatrixNxM<T>(std::move(other)) {}
  template <typename U> Matrix3x2(U const *array) : MatrixNxM<T>(3, 2, array) {}
  template <typename U> Matrix3x2(U const &value) : MatrixNxM<T>(3, 2, value) {}
  template <typename U>
  Matrix3x2(Vec<U> const &value) : MatrixNxM<T>(3, 2, value) {}
  template <typename U>
  Matrix3x2(Vec<Vec<U>> const &value) : MatrixNxM<T>(value) {}
  template <typename U>
  Matrix3x2(Matrix3x2<U> const &other) : MatrixNxM<T>(other) {}
  template <typename U>
  Matrix3x2(MatrixBase<U> const &other) : MatrixNxM<T>(other) {}

  Matrix3x2<T> &operator=(T const &value);
  Matrix3x2<T> &operator=(Vec<T> const &value);
  Matrix3x2<T> &operator=(Vec<Vec<T>> const &value);
  Matrix3x2<T> &operator=(Matrix3x2<T> const &other);
  Matrix3x2<T> &operator=(Matrix3x2<T> &&other);
  Matrix3x2<T> &operator=(MatrixBase<T> const &other);
  Matrix3x2<T> &operator=(MatrixBase<T> &&other);
};

template <typename T> class Matrix3x4 : public MatrixNxM<T> {
public:
  Matrix3x4() : MatrixNxM<T>(3, 4) {}
  Matrix3x4(T const *array) : MatrixNxM<T>(3, 4, array) {}
  Matrix3x4(T const &value) : MatrixNxM<T>(3, 4, value) {}
  Matrix3x4(Vec<T> const &value) : MatrixNxM<T>(3, 4, value) {}
  Matrix3x4(Vec<Vec<T>> const &value) : MatrixNxM<T>(value) {}
  Matrix3x4(Matrix3x4<T> const &other) : MatrixNxM<T>(other) {}
  Matrix3x4(MatrixBase<T> const &other) : MatrixNxM<T>(other) {}
  Matrix3x4(Matrix3x4<T> &&other) noexcept : MatrixNxM<T>(std::move(other)) {}
  template <typename U> Matrix3x4(U const *array) : MatrixNxM<T>(3, 4, array) {}
  template <typename U> Matrix3x4(U const &value) : MatrixNxM<T>(3, 4, value) {}
  template <typename U>
  Matrix3x4(Vec<U> const &value) : MatrixNxM<T>(3, 4, value) {}
  template <typename U>
  Matrix3x4(Vec<Vec<U>> const &value) : MatrixNxM<T>(value) {}
  template <typename U>
  Matrix3x4(Matrix3x4<U> const &other) : MatrixNxM<T>(other) {}
  template <typename U>
  Matrix3x4(MatrixBase<U> const &other) : MatrixNxM<T>(other) {}

  Matrix3x4<T> &operator=(T const &value);
  Matrix3x4<T> &operator=(Vec<T> const &value);
  Matrix3x4<T> &operator=(Vec<Vec<T>> const &value);
  Matrix3x4<T> &operator=(Matrix3x4<T> const &other);
  Matrix3x4<T> &operator=(Matrix3x4<T> &&other);
  Matrix3x4<T> &operator=(MatrixBase<T> const &other);
  Matrix3x4<T> &operator=(MatrixBase<T> &&other);
};

template <typename T> class Matrix4x2 : public MatrixNxM<T> {
public:
  Matrix4x2() : MatrixNxM<T>(4, 2) {}
  Matrix4x2(T const *array) : MatrixNxM<T>(4, 2, array) {}
  Matrix4x2(T const &value) : MatrixNxM<T>(4, 2, value) {}
  Matrix4x2(Vec<T> const &value) : MatrixNxM<T>(4, 2, value) {}
  Matrix4x2(Vec<Vec<T>> const &value) : MatrixNxM<T>(value) {}
  Matrix4x2(Matrix4x2<T> const &other) : MatrixNxM<T>(other) {}
  Matrix4x2(MatrixBase<T> const &other) : MatrixNxM<T>(other) {}
  Matrix4x2(Matrix4x2<T> &&other) noexcept : MatrixNxM<T>(std::move(other)) {}
  template <typename U> Matrix4x2(U const *array) : MatrixNxM<T>(4, 2, array) {}
  template <typename U> Matrix4x2(U const &value) : MatrixNxM<T>(4, 2, value) {}
  template <typename U>
  Matrix4x2(Vec<U> const &value) : MatrixNxM<T>(4, 2, value) {}
  template <typename U>
  Matrix4x2(Vec<Vec<U>> const &value) : MatrixNxM<T>(value) {}
  template <typename U>
  Matrix4x2(Matrix4x2<U> const &other) : MatrixNxM<T>(other) {}
  template <typename U>
  Matrix4x2(MatrixBase<U> const &other) : MatrixNxM<T>(other) {}

  Matrix4x2<T> &operator=(T const &value);
  Matrix4x2<T> &operator=(Vec<T> const &value);
  Matrix4x2<T> &operator=(Vec<Vec<T>> const &value);
  Matrix4x2<T> &operator=(Matrix4x2<T> const &other);
  Matrix4x2<T> &operator=(Matrix4x2<T> &&other);
  Matrix4x2<T> &operator=(MatrixBase<T> const &other);
  Matrix4x2<T> &operator=(MatrixBase<T> &&other);
};

template <typename T> class Matrix4x3 : public MatrixNxM<T> {
public:
  Matrix4x3() : MatrixNxM<T>(4, 3) {}
  Matrix4x3(T const *array) : MatrixNxM<T>(4, 3, array) {}
  Matrix4x3(T const &value) : MatrixNxM<T>(4, 3, value) {}
  Matrix4x3(Vec<T> const &value) : MatrixNxM<T>(4, 3, value) {}
  Matrix4x3(Vec<Vec<T>> const &value) : MatrixNxM<T>(value) {}
  Matrix4x3(Matrix4x3<T> const &other) : MatrixNxM<T>(other) {}
  Matrix4x3(MatrixBase<T> const &other) : MatrixNxM<T>(other) {}
  Matrix4x3(Matrix4x3<T> &&other) noexcept : MatrixNxM<T>(std::move(other)) {}
  template <typename U> Matrix4x3(U const *array) : MatrixNxM<T>(4, 3, array) {}
  template <typename U> Matrix4x3(U const &value) : MatrixNxM<T>(4, 3, value) {}
  template <typename U>
  Matrix4x3(Vec<U> const &value) : MatrixNxM<T>(4, 3, value) {}
  template <typename U>
  Matrix4x3(Vec<Vec<U>> const &value) : MatrixNxM<T>(value) {}
  template <typename U>
  Matrix4x3(Matrix4x3<U> const &other) : MatrixNxM<T>(other) {}
  template <typename U>
  Matrix4x3(MatrixBase<U> const &other) : MatrixNxM<T>(other) {}

  Matrix4x3<T> &operator=(T const &value);
  Matrix4x3<T> &operator=(Vec<T> const &value);
  Matrix4x3<T> &operator=(Vec<Vec<T>> const &value);
  Matrix4x3<T> &operator=(Matrix4x3<T> const &other);
  Matrix4x3<T> &operator=(Matrix4x3<T> &&other);
  Matrix4x3<T> &operator=(MatrixBase<T> const &other);
  Matrix4x3<T> &operator=(MatrixBase<T> &&other);
};

template <typename T>
MatrixNxM<T> Dot(MatrixNxM<T> const &lhs, MatrixNxM<T> const &rhs) {
  MatrixNxM<T>(static_cast<MatrixBase<T>>(lhs) *
               static_cast<MatrixBase<T>>(rhs));
}
template <typename T>
MatrixNxM<T> Hadamard(MatrixNxM<T> const &lhs, MatrixNxM<T> const &rhs) {
  MatrixNxM<T>(Hadamard((MatrixBase<T>)lhs, (MatrixBase<T>)rhs));
}
template <typename T> MatrixNxM<T> Transpose(MatrixNxM<T> const &matrix) {
  return MatrixNxM<T>(matrix.AcquireTransposed());
}

template <typename T>
MatrixNxM<T> operator+(MatrixNxM<T> const &lhs, MatrixNxM<T> const &rhs) {
  return MatrixNxM<T>(static_cast<MatrixBase<T>>(lhs) +
                      static_cast<MatrixBase<T>>(rhs));
}
template <typename T>
MatrixNxM<T> operator-(MatrixNxM<T> const &lhs, MatrixNxM<T> const &rhs) {
  return MatrixNxM<T>(static_cast<MatrixBase<T>>(lhs) -
                      static_cast<MatrixBase<T>>(rhs));
}
template <typename T>
MatrixNxM<T> operator*(MatrixNxM<T> const &lhs, MatrixNxM<T> const &rhs) {
  return MatrixNxM<T>(static_cast<MatrixBase<T>>(lhs) *
                      static_cast<MatrixBase<T>>(rhs));
}
template <typename T>
MatrixNxM<T> operator+(MatrixNxM<T> const &lhs, T const &rhs) {
  return MatrixNxM<T>(static_cast<MatrixBase<T>>(lhs) + rhs);
}
template <typename T>
MatrixNxM<T> operator-(MatrixNxM<T> const &lhs, T const &rhs) {
  return MatrixNxM<T>(static_cast<MatrixBase<T>>(lhs) - rhs);
}
template <typename T>
MatrixNxM<T> operator*(MatrixNxM<T> const &lhs, T const &rhs) {
  return MatrixNxM<T>(static_cast<MatrixBase<T>>(lhs) * rhs);
}
template <typename T>
MatrixNxM<T> operator/(MatrixNxM<T> const &lhs, T const &rhs) {
  return MatrixNxM<T>(static_cast<MatrixBase<T>>(lhs) / rhs);
}
template <typename T>
MatrixNxM<T> operator+(T const &lhs, MatrixNxM<T> const &rhs) {
  return MatrixNxM<T>(lhs + static_cast<MatrixBase<T>>(rhs));
}
template <typename T>
MatrixNxM<T> operator-(T const &lhs, MatrixNxM<T> const &rhs) {
  return MatrixNxM<T>(lhs - static_cast<MatrixBase<T>>(rhs));
}
template <typename T>
MatrixNxM<T> operator*(T const &lhs, MatrixNxM<T> const &rhs) {
  return MatrixNxM<T>(lhs * static_cast<MatrixBase<T>>(rhs));
}

template <typename T>
Matrix2x2<T> Dot(Matrix2x3<T> const &lhs, Matrix3x2<T> const &rhs) {
  return Matrix2x2<T>(static_cast<MatrixBase<T>>(lhs) *
                      static_cast<MatrixBase<T>>(rhs));
}
template <typename T>
Matrix2x2<T> Dot(Matrix2x4<T> const &lhs, Matrix4x2<T> const &rhs) {
  return Matrix2x2<T>(static_cast<MatrixBase<T>>(lhs) *
                      static_cast<MatrixBase<T>>(rhs));
}
template <typename T>
Matrix2x3<T> Dot(Matrix2x2<T> const &lhs, Matrix2x3<T> const &rhs) {
  return Matrix2x3<T>(static_cast<MatrixBase<T>>(lhs) *
                      static_cast<MatrixBase<T>>(rhs));
}
template <typename T>
Matrix2x3<T> Dot(Matrix2x3<T> const &lhs, Matrix3x3<T> const &rhs) {
  return Matrix2x3<T>(static_cast<MatrixBase<T>>(lhs) *
                      static_cast<MatrixBase<T>>(rhs));
}
template <typename T>
Matrix2x3<T> Dot(Matrix2x4<T> const &lhs, Matrix4x3<T> const &rhs) {
  return Matrix2x3<T>(static_cast<MatrixBase<T>>(lhs) *
                      static_cast<MatrixBase<T>>(rhs));
}
template <typename T>
Matrix2x4<T> Dot(Matrix2x2<T> const &lhs, Matrix2x4<T> const &rhs) {
  return Matrix2x4<T>(static_cast<MatrixBase<T>>(lhs) *
                      static_cast<MatrixBase<T>>(rhs));
}
template <typename T>
Matrix2x4<T> Dot(Matrix2x3<T> const &lhs, Matrix3x4<T> const &rhs) {
  return Matrix2x4<T>(static_cast<MatrixBase<T>>(lhs) *
                      static_cast<MatrixBase<T>>(rhs));
}
template <typename T>
Matrix2x4<T> Dot(Matrix2x4<T> const &lhs, Matrix4x4<T> const &rhs) {
  return Matrix2x4<T>(static_cast<MatrixBase<T>>(lhs) *
                      static_cast<MatrixBase<T>>(rhs));
}
template <typename T>
Matrix3x2<T> Dot(Matrix3x2<T> const &lhs, Matrix2x2<T> const &rhs) {
  return Matrix3x2<T>(static_cast<MatrixBase<T>>(lhs) *
                      static_cast<MatrixBase<T>>(rhs));
}
template <typename T>
Matrix3x2<T> Dot(Matrix3x3<T> const &lhs, Matrix3x2<T> const &rhs) {
  return Matrix3x2<T>(static_cast<MatrixBase<T>>(lhs) *
                      static_cast<MatrixBase<T>>(rhs));
}
template <typename T>
Matrix3x2<T> Dot(Matrix3x4<T> const &lhs, Matrix4x2<T> const &rhs) {
  return Matrix3x2<T>(static_cast<MatrixBase<T>>(lhs) *
                      static_cast<MatrixBase<T>>(rhs));
}
template <typename T>
Matrix3x3<T> Dot(Matrix3x2<T> const &lhs, Matrix2x3<T> const &rhs) {
  return Matrix3x3<T>(static_cast<MatrixBase<T>>(lhs) *
                      static_cast<MatrixBase<T>>(rhs));
}
template <typename T>
Matrix3x3<T> Dot(Matrix3x4<T> const &lhs, Matrix4x3<T> const &rhs) {
  return Matrix3x3<T>(static_cast<MatrixBase<T>>(lhs) *
                      static_cast<MatrixBase<T>>(rhs));
}
template <typename T>
Matrix3x4<T> Dot(Matrix3x2<T> const &lhs, Matrix2x4<T> const &rhs) {
  return Matrix3x4<T>(static_cast<MatrixBase<T>>(lhs) *
                      static_cast<MatrixBase<T>>(rhs));
}
template <typename T>
Matrix3x4<T> Dot(Matrix3x3<T> const &lhs, Matrix3x4<T> const &rhs) {
  return Matrix3x4<T>(static_cast<MatrixBase<T>>(lhs) *
                      static_cast<MatrixBase<T>>(rhs));
}
template <typename T>
Matrix3x4<T> Dot(Matrix3x4<T> const &lhs, Matrix4x4<T> const &rhs) {
  return Matrix3x4<T>(static_cast<MatrixBase<T>>(lhs) *
                      static_cast<MatrixBase<T>>(rhs));
}
template <typename T>
Matrix4x2<T> Dot(Matrix4x2<T> const &lhs, Matrix2x2<T> const &rhs) {
  return Matrix4x2<T>(static_cast<MatrixBase<T>>(lhs) *
                      static_cast<MatrixBase<T>>(rhs));
}
template <typename T>
Matrix4x2<T> Dot(Matrix4x3<T> const &lhs, Matrix3x2<T> const &rhs) {
  return Matrix4x2<T>(static_cast<MatrixBase<T>>(lhs) *
                      static_cast<MatrixBase<T>>(rhs));
}
template <typename T>
Matrix4x2<T> Dot(Matrix4x4<T> const &lhs, Matrix4x2<T> const &rhs) {
  return Matrix4x2<T>(static_cast<MatrixBase<T>>(lhs) *
                      static_cast<MatrixBase<T>>(rhs));
}
template <typename T>
Matrix4x3<T> Dot(Matrix4x2<T> const &lhs, Matrix2x3<T> const &rhs) {
  return Matrix4x3<T>(static_cast<MatrixBase<T>>(lhs) *
                      static_cast<MatrixBase<T>>(rhs));
}
template <typename T>
Matrix4x3<T> Dot(Matrix4x3<T> const &lhs, Matrix3x3<T> const &rhs) {
  return Matrix4x3<T>(static_cast<MatrixBase<T>>(lhs) *
                      static_cast<MatrixBase<T>>(rhs));
}
template <typename T>
Matrix4x4<T> Dot(Matrix4x2<T> const &lhs, Matrix2x4<T> const &rhs) {
  return Matrix4x4<T>(static_cast<MatrixBase<T>>(lhs) *
                      static_cast<MatrixBase<T>>(rhs));
}
template <typename T>
Matrix4x4<T> Dot(Matrix4x3<T> const &lhs, Matrix3x4<T> const &rhs) {
  return Matrix4x4<T>(static_cast<MatrixBase<T>>(lhs) *
                      static_cast<MatrixBase<T>>(rhs));
}

template <typename T>
Matrix2x3<T> Hadamard(Matrix2x3<T> const &lhs, Matrix2x3<T> const &rhs) {
  return Matrix2x3<T>(Hadamard((MatrixBase<T>)lhs, (MatrixBase<T>)rhs));
}
template <typename T>
Matrix2x4<T> Hadamard(Matrix2x4<T> const &lhs, Matrix2x4<T> const &rhs) {
  return Matrix2x4<T>(Hadamard((MatrixBase<T>)lhs, (MatrixBase<T>)rhs));
}
template <typename T>
Matrix3x2<T> Hadamard(Matrix3x2<T> const &lhs, Matrix3x2<T> const &rhs) {
  return Matrix3x2<T>(Hadamard((MatrixBase<T>)lhs, (MatrixBase<T>)rhs));
}
template <typename T>
Matrix3x4<T> Hadamard(Matrix3x4<T> const &lhs, Matrix3x4<T> const &rhs) {
  return Matrix3x4<T>(Hadamard((MatrixBase<T>)lhs, (MatrixBase<T>)rhs));
}
template <typename T>
Matrix4x2<T> Hadamard(Matrix4x2<T> const &lhs, Matrix4x2<T> const &rhs) {
  return Matrix4x2<T>(Hadamard((MatrixBase<T>)lhs, (MatrixBase<T>)rhs));
}
template <typename T>
Matrix4x3<T> Hadamard(Matrix4x3<T> const &lhs, Matrix4x3<T> const &rhs) {
  return Matrix4x3<T>(Hadamard((MatrixBase<T>)lhs, (MatrixBase<T>)rhs));
}

template <typename T> Matrix2x3<T> Transpose(Matrix3x2<T> const &matrix) {
  return Matrix2x3<T>(matrix.AcquireTransposed());
}
template <typename T> Matrix2x4<T> Transpose(Matrix4x2<T> const &matrix) {
  return Matrix2x4<T>(matrix.AcquireTransposed());
}
template <typename T> Matrix3x2<T> Transpose(Matrix2x3<T> const &matrix) {
  return Matrix3x2<T>(matrix.AcquireTransposed());
}
template <typename T> Matrix3x4<T> Transpose(Matrix4x3<T> const &matrix) {
  return Matrix3x4<T>(matrix.AcquireTransposed());
}
template <typename T> Matrix4x2<T> Transpose(Matrix2x4<T> const &matrix) {
  return Matrix4x2<T>(matrix.AcquireTransposed());
}
template <typename T> Matrix4x3<T> Transpose(Matrix3x4<T> const &matrix) {
  return Matrix4x3<T>(matrix.AcquireTransposed());
}

template <typename T>
Matrix2x2<T> operator*(Matrix2x3<T> const &lhs, Matrix3x2<T> const &rhs) {
  return Matrix2x2<T>(static_cast<MatrixBase<T>>(lhs) *
                      static_cast<MatrixBase<T>>(rhs));
}
template <typename T>
Matrix2x2<T> operator*(Matrix2x4<T> const &lhs, Matrix4x2<T> const &rhs) {
  return Matrix2x2<T>(static_cast<MatrixBase<T>>(lhs) *
                      static_cast<MatrixBase<T>>(rhs));
}
template <typename T>
Matrix2x3<T> operator*(Matrix2x2<T> const &lhs, Matrix2x3<T> const &rhs) {
  return Matrix2x3<T>(static_cast<MatrixBase<T>>(lhs) *
                      static_cast<MatrixBase<T>>(rhs));
}
template <typename T>
Matrix2x3<T> operator*(Matrix2x3<T> const &lhs, Matrix3x3<T> const &rhs) {
  return Matrix2x3<T>(static_cast<MatrixBase<T>>(lhs) *
                      static_cast<MatrixBase<T>>(rhs));
}
template <typename T>
Matrix2x3<T> operator*(Matrix2x4<T> const &lhs, Matrix4x3<T> const &rhs) {
  return Matrix2x3<T>(static_cast<MatrixBase<T>>(lhs) *
                      static_cast<MatrixBase<T>>(rhs));
}
template <typename T>
Matrix2x4<T> operator*(Matrix2x2<T> const &lhs, Matrix2x4<T> const &rhs) {
  return Matrix2x4<T>(static_cast<MatrixBase<T>>(lhs) *
                      static_cast<MatrixBase<T>>(rhs));
}
template <typename T>
Matrix2x4<T> operator*(Matrix2x3<T> const &lhs, Matrix3x4<T> const &rhs) {
  return Matrix2x4<T>(static_cast<MatrixBase<T>>(lhs) *
                      static_cast<MatrixBase<T>>(rhs));
}
template <typename T>
Matrix2x4<T> operator*(Matrix2x4<T> const &lhs, Matrix4x4<T> const &rhs) {
  return Matrix2x4<T>(static_cast<MatrixBase<T>>(lhs) *
                      static_cast<MatrixBase<T>>(rhs));
}
template <typename T>
Matrix3x2<T> operator*(Matrix3x2<T> const &lhs, Matrix2x2<T> const &rhs) {
  return Matrix3x2<T>(static_cast<MatrixBase<T>>(lhs) *
                      static_cast<MatrixBase<T>>(rhs));
}
template <typename T>
Matrix3x2<T> operator*(Matrix3x3<T> const &lhs, Matrix3x2<T> const &rhs) {
  return Matrix3x2<T>(static_cast<MatrixBase<T>>(lhs) *
                      static_cast<MatrixBase<T>>(rhs));
}
template <typename T>
Matrix3x2<T> operator*(Matrix3x4<T> const &lhs, Matrix4x2<T> const &rhs) {
  return Matrix3x2<T>(static_cast<MatrixBase<T>>(lhs) *
                      static_cast<MatrixBase<T>>(rhs));
}
template <typename T>
Matrix3x3<T> operator*(Matrix3x2<T> const &lhs, Matrix2x3<T> const &rhs) {
  return Matrix3x3<T>(static_cast<MatrixBase<T>>(lhs) *
                      static_cast<MatrixBase<T>>(rhs));
}
template <typename T>
Matrix3x3<T> operator*(Matrix3x4<T> const &lhs, Matrix4x3<T> const &rhs) {
  return Matrix3x3<T>(static_cast<MatrixBase<T>>(lhs) *
                      static_cast<MatrixBase<T>>(rhs));
}
template <typename T>
Matrix3x4<T> operator*(Matrix3x2<T> const &lhs, Matrix2x4<T> const &rhs) {
  return Matrix3x4<T>(static_cast<MatrixBase<T>>(lhs) *
                      static_cast<MatrixBase<T>>(rhs));
}
template <typename T>
Matrix3x4<T> operator*(Matrix3x3<T> const &lhs, Matrix3x4<T> const &rhs) {
  return Matrix3x4<T>(static_cast<MatrixBase<T>>(lhs) *
                      static_cast<MatrixBase<T>>(rhs));
}
template <typename T>
Matrix3x4<T> operator*(Matrix3x4<T> const &lhs, Matrix4x4<T> const &rhs) {
  return Matrix3x4<T>(static_cast<MatrixBase<T>>(lhs) *
                      static_cast<MatrixBase<T>>(rhs));
}
template <typename T>
Matrix4x2<T> operator*(Matrix4x2<T> const &lhs, Matrix2x2<T> const &rhs) {
  return Matrix4x2<T>(static_cast<MatrixBase<T>>(lhs) *
                      static_cast<MatrixBase<T>>(rhs));
}
template <typename T>
Matrix4x2<T> operator*(Matrix4x3<T> const &lhs, Matrix3x2<T> const &rhs) {
  return Matrix4x2<T>(static_cast<MatrixBase<T>>(lhs) *
                      static_cast<MatrixBase<T>>(rhs));
}
template <typename T>
Matrix4x2<T> operator*(Matrix4x4<T> const &lhs, Matrix4x2<T> const &rhs) {
  return Matrix4x2<T>(static_cast<MatrixBase<T>>(lhs) *
                      static_cast<MatrixBase<T>>(rhs));
}
template <typename T>
Matrix4x3<T> operator*(Matrix4x2<T> const &lhs, Matrix2x3<T> const &rhs) {
  return Matrix4x3<T>(static_cast<MatrixBase<T>>(lhs) *
                      static_cast<MatrixBase<T>>(rhs));
}
template <typename T>
Matrix4x3<T> operator*(Matrix4x3<T> const &lhs, Matrix3x3<T> const &rhs) {
  return Matrix4x3<T>(static_cast<MatrixBase<T>>(lhs) *
                      static_cast<MatrixBase<T>>(rhs));
}
template <typename T>
Matrix4x4<T> operator*(Matrix4x2<T> const &lhs, Matrix2x4<T> const &rhs) {
  return Matrix4x4<T>(static_cast<MatrixBase<T>>(lhs) *
                      static_cast<MatrixBase<T>>(rhs));
}
template <typename T>
Matrix4x4<T> operator*(Matrix4x3<T> const &lhs, Matrix3x4<T> const &rhs) {
  return Matrix4x4<T>(static_cast<MatrixBase<T>>(lhs) *
                      static_cast<MatrixBase<T>>(rhs));
}

template <typename T>
Matrix2x3<T> operator+(Matrix2x3<T> const &lhs, Matrix2x3<T> const &rhs) {
  return Matrix2x3<T>(static_cast<MatrixBase<T>>(lhs) +
                      static_cast<MatrixBase<T>>(rhs));
}
template <typename T>
Matrix2x3<T> operator-(Matrix2x3<T> const &lhs, Matrix2x3<T> const &rhs) {
  return Matrix2x3<T>(static_cast<MatrixBase<T>>(lhs) -
                      static_cast<MatrixBase<T>>(rhs));
}
template <typename T>
Matrix2x3<T> operator+(Matrix2x3<T> const &lhs, T const &rhs) {
  return Matrix2x3<T>(static_cast<MatrixBase<T>>(lhs) + rhs);
}
template <typename T>
Matrix2x3<T> operator-(Matrix2x3<T> const &lhs, T const &rhs) {
  return Matrix2x3<T>(static_cast<MatrixBase<T>>(lhs) - rhs);
}
template <typename T>
Matrix2x3<T> operator*(Matrix2x3<T> const &lhs, T const &rhs) {
  return Matrix2x3<T>(static_cast<MatrixBase<T>>(lhs) * rhs);
}
template <typename T>
Matrix2x3<T> operator/(Matrix2x3<T> const &lhs, T const &rhs) {
  return Matrix2x3<T>(static_cast<MatrixBase<T>>(lhs) / rhs);
}
template <typename T>
Matrix2x3<T> operator+(T const &lhs, Matrix2x3<T> const &rhs) {
  return Matrix2x3<T>(lhs + static_cast<MatrixBase<T>>(rhs));
}
template <typename T>
Matrix2x3<T> operator-(T const &lhs, Matrix2x3<T> const &rhs) {
  return Matrix2x3<T>(lhs - static_cast<MatrixBase<T>>(rhs));
}
template <typename T>
Matrix2x3<T> operator*(T const &lhs, Matrix2x3<T> const &rhs) {
  return Matrix2x3<T>(lhs * static_cast<MatrixBase<T>>(rhs));
}

template <typename T>
Matrix2x4<T> operator+(Matrix2x4<T> const &lhs, Matrix2x4<T> const &rhs) {
  return Matrix2x4<T>(static_cast<MatrixBase<T>>(lhs) +
                      static_cast<MatrixBase<T>>(rhs));
}
template <typename T>
Matrix2x4<T> operator-(Matrix2x4<T> const &lhs, Matrix2x4<T> const &rhs) {
  return Matrix2x4<T>(static_cast<MatrixBase<T>>(lhs) -
                      static_cast<MatrixBase<T>>(rhs));
}
template <typename T>
Matrix2x4<T> operator+(Matrix2x4<T> const &lhs, T const &rhs) {
  return Matrix2x4<T>(static_cast<MatrixBase<T>>(lhs) + rhs);
}
template <typename T>
Matrix2x4<T> operator-(Matrix2x4<T> const &lhs, T const &rhs) {
  return Matrix2x4<T>(static_cast<MatrixBase<T>>(lhs) - rhs);
}
template <typename T>
Matrix2x4<T> operator*(Matrix2x4<T> const &lhs, T const &rhs) {
  return Matrix2x4<T>(static_cast<MatrixBase<T>>(lhs) * rhs);
}
template <typename T>
Matrix2x4<T> operator/(Matrix2x4<T> const &lhs, T const &rhs) {
  return Matrix2x4<T>(static_cast<MatrixBase<T>>(lhs) / rhs);
}
template <typename T>
Matrix2x4<T> operator+(T const &lhs, Matrix2x4<T> const &rhs) {
  return Matrix2x4<T>(lhs + static_cast<MatrixBase<T>>(rhs));
}
template <typename T>
Matrix2x4<T> operator-(T const &lhs, Matrix2x4<T> const &rhs) {
  return Matrix2x4<T>(lhs - static_cast<MatrixBase<T>>(rhs));
}
template <typename T>
Matrix2x4<T> operator*(T const &lhs, Matrix2x4<T> const &rhs) {
  return Matrix2x4<T>(lhs * static_cast<MatrixBase<T>>(rhs));
}

template <typename T>
Matrix3x2<T> operator+(Matrix3x2<T> const &lhs, Matrix3x2<T> const &rhs) {
  return Matrix3x2<T>(static_cast<MatrixBase<T>>(lhs) +
                      static_cast<MatrixBase<T>>(rhs));
}
template <typename T>
Matrix3x2<T> operator-(Matrix3x2<T> const &lhs, Matrix3x2<T> const &rhs) {
  return Matrix3x2<T>(static_cast<MatrixBase<T>>(lhs) -
                      static_cast<MatrixBase<T>>(rhs));
}
template <typename T>
Matrix3x2<T> operator+(Matrix3x2<T> const &lhs, T const &rhs) {
  return Matrix3x2<T>(static_cast<MatrixBase<T>>(lhs) + rhs);
}
template <typename T>
Matrix3x2<T> operator-(Matrix3x2<T> const &lhs, T const &rhs) {
  return Matrix3x2<T>(static_cast<MatrixBase<T>>(lhs) - rhs);
}
template <typename T>
Matrix3x2<T> operator*(Matrix3x2<T> const &lhs, T const &rhs) {
  return Matrix3x2<T>(static_cast<MatrixBase<T>>(lhs) * rhs);
}
template <typename T>
Matrix3x2<T> operator/(Matrix3x2<T> const &lhs, T const &rhs) {
  return Matrix3x2<T>(static_cast<MatrixBase<T>>(lhs) / rhs);
}
template <typename T>
Matrix3x2<T> operator+(T const &lhs, Matrix3x2<T> const &rhs) {
  return Matrix3x2<T>(lhs + static_cast<MatrixBase<T>>(rhs));
}
template <typename T>
Matrix3x2<T> operator-(T const &lhs, Matrix3x2<T> const &rhs) {
  return Matrix3x2<T>(lhs - static_cast<MatrixBase<T>>(rhs));
}
template <typename T>
Matrix3x2<T> operator*(T const &lhs, Matrix3x2<T> const &rhs) {
  return Matrix3x2<T>(lhs * static_cast<MatrixBase<T>>(rhs));
}

template <typename T>
Matrix3x4<T> operator+(Matrix3x4<T> const &lhs, Matrix3x4<T> const &rhs) {
  return Matrix3x4<T>(static_cast<MatrixBase<T>>(lhs) +
                      static_cast<MatrixBase<T>>(rhs));
}
template <typename T>
Matrix3x4<T> operator-(Matrix3x4<T> const &lhs, Matrix3x4<T> const &rhs) {
  return Matrix3x4<T>(static_cast<MatrixBase<T>>(lhs) -
                      static_cast<MatrixBase<T>>(rhs));
}
template <typename T>
Matrix3x4<T> operator+(Matrix3x4<T> const &lhs, T const &rhs) {
  return Matrix3x4<T>(static_cast<MatrixBase<T>>(lhs) + rhs);
}
template <typename T>
Matrix3x4<T> operator-(Matrix3x4<T> const &lhs, T const &rhs) {
  return Matrix3x4<T>(static_cast<MatrixBase<T>>(lhs) - rhs);
}
template <typename T>
Matrix3x4<T> operator*(Matrix3x4<T> const &lhs, T const &rhs) {
  return Matrix3x4<T>(static_cast<MatrixBase<T>>(lhs) * rhs);
}
template <typename T>
Matrix3x4<T> operator/(Matrix3x4<T> const &lhs, T const &rhs) {
  return Matrix3x4<T>(static_cast<MatrixBase<T>>(lhs) / rhs);
}
template <typename T>
Matrix3x4<T> operator+(T const &lhs, Matrix3x4<T> const &rhs) {
  return Matrix3x4<T>(lhs + static_cast<MatrixBase<T>>(rhs));
}
template <typename T>
Matrix3x4<T> operator-(T const &lhs, Matrix3x4<T> const &rhs) {
  return Matrix3x4<T>(lhs - static_cast<MatrixBase<T>>(rhs));
}
template <typename T>
Matrix3x4<T> operator*(T const &lhs, Matrix3x4<T> const &rhs) {
  return Matrix3x4<T>(lhs * static_cast<MatrixBase<T>>(rhs));
}

template <typename T>
Matrix4x2<T> operator+(Matrix4x2<T> const &lhs, Matrix4x2<T> const &rhs) {
  return Matrix4x2<T>(static_cast<MatrixBase<T>>(lhs) +
                      static_cast<MatrixBase<T>>(rhs));
}
template <typename T>
Matrix4x2<T> operator-(Matrix4x2<T> const &lhs, Matrix4x2<T> const &rhs) {
  return Matrix4x2<T>(static_cast<MatrixBase<T>>(lhs) -
                      static_cast<MatrixBase<T>>(rhs));
}
template <typename T>
Matrix4x2<T> operator+(Matrix4x2<T> const &lhs, T const &rhs) {
  return Matrix4x2<T>(static_cast<MatrixBase<T>>(lhs) + rhs);
}
template <typename T>
Matrix4x2<T> operator-(Matrix4x2<T> const &lhs, T const &rhs) {
  return Matrix4x2<T>(static_cast<MatrixBase<T>>(lhs) - rhs);
}
template <typename T>
Matrix4x2<T> operator*(Matrix4x2<T> const &lhs, T const &rhs) {
  return Matrix4x2<T>(static_cast<MatrixBase<T>>(lhs) * rhs);
}
template <typename T>
Matrix4x2<T> operator/(Matrix4x2<T> const &lhs, T const &rhs) {
  return Matrix4x2<T>(static_cast<MatrixBase<T>>(lhs) / rhs);
}
template <typename T>
Matrix4x2<T> operator+(T const &lhs, Matrix4x2<T> const &rhs) {
  return Matrix4x2<T>(lhs + static_cast<MatrixBase<T>>(rhs));
}
template <typename T>
Matrix4x2<T> operator-(T const &lhs, Matrix4x2<T> const &rhs) {
  return Matrix4x2<T>(lhs - static_cast<MatrixBase<T>>(rhs));
}
template <typename T>
Matrix4x2<T> operator*(T const &lhs, Matrix4x2<T> const &rhs) {
  return Matrix4x2<T>(lhs * static_cast<MatrixBase<T>>(rhs));
}

template <typename T>
Matrix4x3<T> operator+(Matrix4x3<T> const &lhs, Matrix4x3<T> const &rhs) {
  return Matrix4x3<T>(static_cast<MatrixBase<T>>(lhs) +
                      static_cast<MatrixBase<T>>(rhs));
}
template <typename T>
Matrix4x3<T> operator-(Matrix4x3<T> const &lhs, Matrix4x3<T> const &rhs) {
  return Matrix4x3<T>(static_cast<MatrixBase<T>>(lhs) -
                      static_cast<MatrixBase<T>>(rhs));
}
template <typename T>
Matrix4x3<T> operator+(Matrix4x3<T> const &lhs, T const &rhs) {
  return Matrix4x3<T>(static_cast<MatrixBase<T>>(lhs) + rhs);
}
template <typename T>
Matrix4x3<T> operator-(Matrix4x3<T> const &lhs, T const &rhs) {
  return Matrix4x3<T>(static_cast<MatrixBase<T>>(lhs) - rhs);
}
template <typename T>
Matrix4x3<T> operator*(Matrix4x3<T> const &lhs, T const &rhs) {
  return Matrix4x3<T>(static_cast<MatrixBase<T>>(lhs) * rhs);
}
template <typename T>
Matrix4x3<T> operator/(Matrix4x3<T> const &lhs, T const &rhs) {
  return Matrix4x3<T>(static_cast<MatrixBase<T>>(lhs) / rhs);
}
template <typename T>
Matrix4x3<T> operator+(T const &lhs, Matrix4x3<T> const &rhs) {
  return Matrix4x3<T>(lhs + static_cast<MatrixBase<T>>(rhs));
}
template <typename T>
Matrix4x3<T> operator-(T const &lhs, Matrix4x3<T> const &rhs) {
  return Matrix4x3<T>(lhs - static_cast<MatrixBase<T>>(rhs));
}
template <typename T>
Matrix4x3<T> operator*(T const &lhs, Matrix4x3<T> const &rhs) {
  return Matrix4x3<T>(lhs * static_cast<MatrixBase<T>>(rhs));
}
} // namespace TerreateMath::Matrix

// Implementation
namespace TerreateMath::Matrix {
using namespace TerreateMath::Defines;

template <typename T> MatrixNxM<T> &MatrixNxM<T>::operator=(T const &value) {
  MatrixBase<T>::operator=(value);
  return *this;
}

template <typename T>
MatrixNxM<T> &MatrixNxM<T>::operator=(Vec<T> const &value) {
  MatrixBase<T>::operator=(value);
  return *this;
}

template <typename T>
MatrixNxM<T> &MatrixNxM<T>::operator=(Vec<Vec<T>> const &value) {
  MatrixBase<T>::operator=(value);
  return *this;
}

template <typename T>
MatrixNxM<T> &MatrixNxM<T>::operator=(MatrixNxM<T> const &other) {
  MatrixBase<T>::operator=(other);
  return *this;
}

template <typename T>
MatrixNxM<T> &MatrixNxM<T>::operator=(MatrixNxM<T> &&other) {
  MatrixBase<T>::operator=(std::move(other));
  return *this;
}

template <typename T>
MatrixNxM<T> &MatrixNxM<T>::operator=(MatrixBase<T> const &other) {
  MatrixBase<T>::operator=(other);
  return *this;
}

template <typename T>
MatrixNxM<T> &MatrixNxM<T>::operator=(MatrixBase<T> &&other) {
  MatrixBase<T>::operator=(std::move(other));
  return *this;
}

template <typename T> Matrix2x3<T> &Matrix2x3<T>::operator=(T const &value) {
  MatrixNxM<T>::operator=(value);
  return *this;
}

template <typename T>
Matrix2x3<T> &Matrix2x3<T>::operator=(Vec<T> const &value) {
  MatrixNxM<T>::operator=(value);
  return *this;
}

template <typename T>
Matrix2x3<T> &Matrix2x3<T>::operator=(Vec<Vec<T>> const &value) {
  MatrixNxM<T>::operator=(value);
  return *this;
}

template <typename T>
Matrix2x3<T> &Matrix2x3<T>::operator=(Matrix2x3<T> const &other) {
  MatrixNxM<T>::operator=(other);
  return *this;
}

template <typename T>
Matrix2x3<T> &Matrix2x3<T>::operator=(Matrix2x3<T> &&other) {
  MatrixNxM<T>::operator=(std::move(other));
  return *this;
}

template <typename T>
Matrix2x3<T> &Matrix2x3<T>::operator=(MatrixBase<T> const &other) {
  MatrixNxM<T>::operator=(other);
  return *this;
}

template <typename T>
Matrix2x3<T> &Matrix2x3<T>::operator=(MatrixBase<T> &&other) {
  MatrixNxM<T>::operator=(std::move(other));
  return *this;
}

template <typename T> Matrix2x4<T> &Matrix2x4<T>::operator=(T const &value) {
  MatrixNxM<T>::operator=(value);
  return *this;
}

template <typename T>
Matrix2x4<T> &Matrix2x4<T>::operator=(Vec<T> const &value) {
  MatrixNxM<T>::operator=(value);
  return *this;
}

template <typename T>
Matrix2x4<T> &Matrix2x4<T>::operator=(Vec<Vec<T>> const &value) {
  MatrixNxM<T>::operator=(value);
  return *this;
}

template <typename T>
Matrix2x4<T> &Matrix2x4<T>::operator=(Matrix2x4<T> const &other) {
  MatrixNxM<T>::operator=(other);
  return *this;
}

template <typename T>
Matrix2x4<T> &Matrix2x4<T>::operator=(Matrix2x4<T> &&other) {
  MatrixNxM<T>::operator=(std::move(other));
  return *this;
}

template <typename T>
Matrix2x4<T> &Matrix2x4<T>::operator=(MatrixBase<T> const &other) {
  MatrixNxM<T>::operator=(other);
  return *this;
}

template <typename T>
Matrix2x4<T> &Matrix2x4<T>::operator=(MatrixBase<T> &&other) {
  MatrixNxM<T>::operator=(std::move(other));
  return *this;
}

template <typename T> Matrix3x2<T> &Matrix3x2<T>::operator=(T const &value) {
  MatrixNxM<T>::operator=(value);
  return *this;
}

template <typename T>
Matrix3x2<T> &Matrix3x2<T>::operator=(Vec<T> const &value) {
  MatrixNxM<T>::operator=(value);
  return *this;
}

template <typename T>
Matrix3x2<T> &Matrix3x2<T>::operator=(Vec<Vec<T>> const &value) {
  MatrixNxM<T>::operator=(value);
  return *this;
}

template <typename T>
Matrix3x2<T> &Matrix3x2<T>::operator=(Matrix3x2<T> const &other) {
  MatrixNxM<T>::operator=(other);
  return *this;
}

template <typename T>
Matrix3x2<T> &Matrix3x2<T>::operator=(Matrix3x2<T> &&other) {
  MatrixNxM<T>::operator=(std::move(other));
  return *this;
}

template <typename T>
Matrix3x2<T> &Matrix3x2<T>::operator=(MatrixBase<T> const &other) {
  MatrixNxM<T>::operator=(other);
  return *this;
}

template <typename T>
Matrix3x2<T> &Matrix3x2<T>::operator=(MatrixBase<T> &&other) {
  MatrixNxM<T>::operator=(std::move(other));
  return *this;
}

template <typename T> Matrix3x4<T> &Matrix3x4<T>::operator=(T const &value) {
  MatrixNxM<T>::operator=(value);
  return *this;
}

template <typename T>
Matrix3x4<T> &Matrix3x4<T>::operator=(Vec<T> const &value) {
  MatrixNxM<T>::operator=(value);
  return *this;
}

template <typename T>
Matrix3x4<T> &Matrix3x4<T>::operator=(Vec<Vec<T>> const &value) {
  MatrixNxM<T>::operator=(value);
  return *this;
}

template <typename T>
Matrix3x4<T> &Matrix3x4<T>::operator=(Matrix3x4<T> const &other) {
  MatrixNxM<T>::operator=(other);
  return *this;
}

template <typename T>
Matrix3x4<T> &Matrix3x4<T>::operator=(Matrix3x4<T> &&other) {
  MatrixNxM<T>::operator=(std::move(other));
  return *this;
}

template <typename T>
Matrix3x4<T> &Matrix3x4<T>::operator=(MatrixBase<T> const &other) {
  MatrixNxM<T>::operator=(other);
  return *this;
}

template <typename T>
Matrix3x4<T> &Matrix3x4<T>::operator=(MatrixBase<T> &&other) {
  MatrixNxM<T>::operator=(std::move(other));
  return *this;
}

template <typename T> Matrix4x2<T> &Matrix4x2<T>::operator=(T const &value) {
  MatrixNxM<T>::operator=(value);
  return *this;
}

template <typename T>
Matrix4x2<T> &Matrix4x2<T>::operator=(Vec<T> const &value) {
  MatrixNxM<T>::operator=(value);
  return *this;
}

template <typename T>
Matrix4x2<T> &Matrix4x2<T>::operator=(Vec<Vec<T>> const &value) {
  MatrixNxM<T>::operator=(value);
  return *this;
}

template <typename T>
Matrix4x2<T> &Matrix4x2<T>::operator=(Matrix4x2<T> const &other) {
  MatrixNxM<T>::operator=(other);
  return *this;
}

template <typename T>
Matrix4x2<T> &Matrix4x2<T>::operator=(Matrix4x2<T> &&other) {
  MatrixNxM<T>::operator=(std::move(other));
  return *this;
}

template <typename T>
Matrix4x2<T> &Matrix4x2<T>::operator=(MatrixBase<T> const &other) {
  MatrixNxM<T>::operator=(other);
  return *this;
}

template <typename T>
Matrix4x2<T> &Matrix4x2<T>::operator=(MatrixBase<T> &&other) {
  MatrixNxM<T>::operator=(std::move(other));
  return *this;
}

template <typename T> Matrix4x3<T> &Matrix4x3<T>::operator=(T const &value) {
  MatrixNxM<T>::operator=(value);
  return *this;
}

template <typename T>
Matrix4x3<T> &Matrix4x3<T>::operator=(Vec<T> const &value) {
  MatrixNxM<T>::operator=(value);
  return *this;
}

template <typename T>
Matrix4x3<T> &Matrix4x3<T>::operator=(Vec<Vec<T>> const &value) {
  MatrixNxM<T>::operator=(value);
  return *this;
}

template <typename T>
Matrix4x3<T> &Matrix4x3<T>::operator=(Matrix4x3<T> const &other) {
  MatrixNxM<T>::operator=(other);
  return *this;
}

template <typename T>
Matrix4x3<T> &Matrix4x3<T>::operator=(Matrix4x3<T> &&other) {
  MatrixNxM<T>::operator=(std::move(other));
  return *this;
}

template <typename T>
Matrix4x3<T> &Matrix4x3<T>::operator=(MatrixBase<T> const &other) {
  MatrixNxM<T>::operator=(other);
  return *this;
}

template <typename T>
Matrix4x3<T> &Matrix4x3<T>::operator=(MatrixBase<T> &&other) {
  MatrixNxM<T>::operator=(std::move(other));
  return *this;
}
} // namespace TerreateMath::Matrix

#endif // __TC_MATH_MATRIXNXM_HPP__
