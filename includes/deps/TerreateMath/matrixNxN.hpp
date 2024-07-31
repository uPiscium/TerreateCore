#ifndef __TC_MATH_MATRIXNXN_HPP__
#define __TC_MATH_MATRIXNXN_HPP__

#include "core.hpp"
#include "defines.hpp"
#include "vectorColumn.hpp"
#include "vectorRow.hpp"

namespace TerreateMath::Matrix {
using namespace TerreateMath::Defines;
using namespace TerreateMath::Core;
using namespace TerreateMath::Vector;

template <typename T> class MatrixNxN : public MatrixBase<T> {
public:
  MatrixNxN() : MatrixBase<T>() {}
  MatrixNxN(Uint const &row) : MatrixBase<T>(row, row) {}
  MatrixNxN(Uint const &row, T const *array) : MatrixBase<T>(row, row, array) {}
  MatrixNxN(Uint const &row, T const &value) : MatrixBase<T>(row, row, value) {}
  MatrixNxN(Uint const &row, Vec<T> const &value)
      : MatrixBase<T>(row, row, value) {}
  MatrixNxN(Vec<Vec<T>> const &value) : MatrixBase<T>(value) {}
  MatrixNxN(MatrixNxN<T> const &other) : MatrixBase<T>(other) {}
  MatrixNxN(MatrixBase<T> const &other) : MatrixBase<T>(other) {}
  MatrixNxN(MatrixNxN<T> &&other) noexcept : MatrixBase<T>(std::move(other)) {}
  template <typename U>
  MatrixNxN(Uint const &row, U const *array) : MatrixBase<T>(row, row, array) {}
  template <typename U>
  MatrixNxN(Uint const &row, U const &value) : MatrixBase<T>(row, row, value) {}
  template <typename U>
  MatrixNxN(Uint const &row, Vec<U> const &value)
      : MatrixBase<T>(row, row, value) {}
  template <typename U>
  MatrixNxN(Vec<Vec<U>> const &value) : MatrixBase<T>(value) {}
  template <typename U>
  MatrixNxN(MatrixNxN<U> const &other) : MatrixBase<T>(other) {}
  template <typename U>
  MatrixNxN(MatrixBase<U> const &other) : MatrixBase<T>(other) {}

  MatrixNxN<T> &operator=(T const &value);
  MatrixNxN<T> &operator=(Vec<T> const &value);
  MatrixNxN<T> &operator=(Vec<Vec<T>> const &value);
  MatrixNxN<T> &operator=(MatrixNxN<T> const &other);
  MatrixNxN<T> &operator=(MatrixNxN<T> &&other);
  MatrixNxN<T> &operator=(MatrixBase<T> const &other);
  MatrixNxN<T> &operator=(MatrixBase<T> &&other);
};

template <typename T> class Matrix2x2 : public MatrixNxN<T> {
public:
  Matrix2x2() : MatrixNxN<T>(2) {}
  Matrix2x2(T const *array) : MatrixNxN<T>(2, array) {}
  Matrix2x2(T const &value) : MatrixNxN<T>(2, value) {}
  Matrix2x2(Vec<T> const &value) : MatrixNxN<T>(2, value) {}
  Matrix2x2(Vec<Vec<T>> const &value) : MatrixNxN<T>(value) {}
  Matrix2x2(Matrix2x2<T> const &other) : MatrixNxN<T>(other) {}
  Matrix2x2(MatrixBase<T> const &other) : MatrixNxN<T>(other) {}
  Matrix2x2(Matrix2x2<T> &&other) noexcept : MatrixNxN<T>(std::move(other)) {}
  template <typename U> Matrix2x2(U const *array) : MatrixNxN<T>(2, array) {}
  template <typename U> Matrix2x2(U const &value) : MatrixNxN<T>(2, value) {}
  template <typename U>
  Matrix2x2(Vec<U> const &value) : MatrixNxN<T>(2, value) {}
  template <typename U>
  Matrix2x2(Vec<Vec<U>> const &value) : MatrixNxN<T>(value) {}
  template <typename U>
  Matrix2x2(Matrix2x2<U> const &other) : MatrixNxN<T>(other) {}
  template <typename U>
  Matrix2x2(MatrixBase<U> const &other) : MatrixNxN<T>(other) {}

  Matrix2x2<T> &operator=(T const &value);
  Matrix2x2<T> &operator=(Vec<T> const &value);
  Matrix2x2<T> &operator=(Vec<Vec<T>> const &value);
  Matrix2x2<T> &operator=(Matrix2x2<T> const &other);
  Matrix2x2<T> &operator=(Matrix2x2<T> &&other);
  Matrix2x2<T> &operator=(MatrixBase<T> const &other);
  Matrix2x2<T> &operator=(MatrixBase<T> &&other);
};

template <typename T> class Matrix3x3 : public MatrixNxN<T> {
public:
  Matrix3x3() : MatrixNxN<T>(3) {}
  Matrix3x3(T const *array) : MatrixNxN<T>(3, array) {}
  Matrix3x3(T const &value) : MatrixNxN<T>(3, value) {}
  Matrix3x3(Vec<T> const &value) : MatrixNxN<T>(3, value) {}
  Matrix3x3(Vec<Vec<T>> const &value) : MatrixNxN<T>(value) {}
  Matrix3x3(Matrix3x3<T> const &other) : MatrixNxN<T>(other) {}
  Matrix3x3(MatrixBase<T> const &other) : MatrixNxN<T>(other) {}
  Matrix3x3(Matrix3x3<T> &&other) noexcept : MatrixNxN<T>(std::move(other)) {}
  template <typename U> Matrix3x3(U const *array) : MatrixNxN<T>(3, array) {}
  template <typename U> Matrix3x3(U const &value) : MatrixNxN<T>(3, value) {}
  template <typename U>
  Matrix3x3(Vec<U> const &value) : MatrixNxN<T>(3, value) {}
  template <typename U>
  Matrix3x3(Vec<Vec<U>> const &value) : MatrixNxN<T>(value) {}
  template <typename U>
  Matrix3x3(Matrix3x3<U> const &other) : MatrixNxN<T>(other) {}
  template <typename U>
  Matrix3x3(MatrixBase<U> const &other) : MatrixNxN<T>(other) {}

  Matrix3x3<T> &operator=(T const &value);
  Matrix3x3<T> &operator=(Vec<T> const &value);
  Matrix3x3<T> &operator=(Vec<Vec<T>> const &value);
  Matrix3x3<T> &operator=(Matrix3x3<T> const &other);
  Matrix3x3<T> &operator=(Matrix3x3<T> &&other);
  Matrix3x3<T> &operator=(MatrixBase<T> const &other);
  Matrix3x3<T> &operator=(MatrixBase<T> &&other);
};

template <typename T> class Matrix4x4 : public MatrixNxN<T> {
public:
  Matrix4x4() : MatrixNxN<T>(4) {}
  Matrix4x4(T const *array) : MatrixNxN<T>(4, array) {}
  Matrix4x4(T const &value) : MatrixNxN<T>(4, value) {}
  Matrix4x4(Vec<T> const &value) : MatrixNxN<T>(4, value) {}
  Matrix4x4(Vec<Vec<T>> const &value) : MatrixNxN<T>(value) {}
  Matrix4x4(Matrix4x4<T> const &other) : MatrixNxN<T>(other) {}
  Matrix4x4(MatrixBase<T> const &other) : MatrixNxN<T>(other) {}
  Matrix4x4(Matrix4x4<T> &&other) noexcept : MatrixNxN<T>(std::move(other)) {}
  template <typename U> Matrix4x4(U const *array) : MatrixNxN<T>(4, array) {}
  template <typename U> Matrix4x4(U const &value) : MatrixNxN<T>(4, value) {}
  template <typename U>
  Matrix4x4(Vec<U> const &value) : MatrixNxN<T>(4, value) {}
  template <typename U>
  Matrix4x4(Vec<Vec<U>> const &value) : MatrixNxN<T>(value) {}
  template <typename U>
  Matrix4x4(Matrix4x4<U> const &other) : MatrixNxN<T>(other) {}
  template <typename U>
  Matrix4x4(MatrixBase<U> const &other) : MatrixNxN<T>(other) {}

  Matrix4x4<T> &operator=(T const &value);
  Matrix4x4<T> &operator=(Vec<T> const &value);
  Matrix4x4<T> &operator=(Vec<Vec<T>> const &value);
  Matrix4x4<T> &operator=(Matrix4x4<T> const &other);
  Matrix4x4<T> &operator=(Matrix4x4<T> &&other);
  Matrix4x4<T> &operator=(MatrixBase<T> const &other);
  Matrix4x4<T> &operator=(MatrixBase<T> &&other);
};

template <typename T>
MatrixNxN<T> Dot(MatrixNxN<T> const &lhs, MatrixNxN<T> const &rhs) {
  MatrixNxN<T>(lhs * rhs);
}
template <typename T>
MatrixNxN<T> Hadamard(MatrixNxN<T> const &lhs, MatrixNxN<T> const &rhs) {
  MatrixNxN<T>(Hadamard((MatrixBase<T>)lhs, (MatrixBase<T>)rhs));
}
template <typename T> MatrixNxN<T> Transpose(MatrixNxN<T> const &matrix) {
  return MatrixNxN<T>(matrix.AcquireTransposed());
}
template <typename T> MatrixNxN<T> Inverse(MatrixNxN<T> const &matrix) {
  return MatrixNxN<T>(matrix.AcquireInversed());
}

template <typename T>
MatrixNxN<T> operator+(MatrixNxN<T> const &lhs, MatrixNxN<T> const &rhs) {
  return MatrixNxN<T>(static_cast<MatrixBase<T>>(lhs) +
                      static_cast<MatrixBase<T>>(rhs));
}
template <typename T>
MatrixNxN<T> operator-(MatrixNxN<T> const &lhs, MatrixNxN<T> const &rhs) {
  return MatrixNxN<T>(static_cast<MatrixBase<T>>(lhs) -
                      static_cast<MatrixBase<T>>(rhs));
}
template <typename T>
MatrixNxN<T> operator*(MatrixNxN<T> const &lhs, MatrixNxN<T> const &rhs) {
  return MatrixNxN<T>(static_cast<MatrixBase<T>>(lhs) *
                      static_cast<MatrixBase<T>>(rhs));
}
template <typename T>
MatrixNxN<T> operator+(MatrixNxN<T> const &lhs, T const &rhs) {
  return MatrixNxN<T>(static_cast<MatrixBase<T>>(lhs) + rhs);
}
template <typename T>
MatrixNxN<T> operator-(MatrixNxN<T> const &lhs, T const &rhs) {
  return MatrixNxN<T>(static_cast<MatrixBase<T>>(lhs) - rhs);
}
template <typename T>
MatrixNxN<T> operator*(MatrixNxN<T> const &lhs, T const &rhs) {
  return MatrixNxN<T>(static_cast<MatrixBase<T>>(lhs) * rhs);
}
template <typename T>
MatrixNxN<T> operator/(MatrixNxN<T> const &lhs, T const &rhs) {
  return MatrixNxN<T>(static_cast<MatrixBase<T>>(lhs) / rhs);
}
template <typename T>
MatrixNxN<T> operator+(T const &lhs, MatrixNxN<T> const &rhs) {
  return MatrixNxN<T>(lhs + static_cast<MatrixBase<T>>(rhs));
}
template <typename T>
MatrixNxN<T> operator-(T const &lhs, MatrixNxN<T> const &rhs) {
  return MatrixNxN<T>(lhs - static_cast<MatrixBase<T>>(rhs));
}
template <typename T>
MatrixNxN<T> operator*(T const &lhs, MatrixNxN<T> const &rhs) {
  return MatrixNxN<T>(lhs * static_cast<MatrixBase<T>>(rhs));
}

template <typename T>
Matrix2x2<T> Dot(Matrix2x2<T> const &lhs, Matrix2x2<T> const &rhs) {
  return Matrix2x2<T>(static_cast<MatrixBase<T>>(lhs) *
                      static_cast<MatrixBase<T>>(rhs));
}
template <typename T>
Matrix3x3<T> Dot(Matrix3x3<T> const &lhs, Matrix3x3<T> const &rhs) {
  return Matrix3x3<T>(static_cast<MatrixBase<T>>(lhs) *
                      static_cast<MatrixBase<T>>(rhs));
}
template <typename T>
Matrix4x4<T> Dot(Matrix4x4<T> const &lhs, Matrix4x4<T> const &rhs) {
  return Matrix4x4<T>(static_cast<MatrixBase<T>>(lhs) *
                      static_cast<MatrixBase<T>>(rhs));
}
template <typename T>
Matrix2x2<T> Hadamard(Matrix2x2<T> const &lhs, Matrix2x2<T> const &rhs) {
  Matrix2x2<T>(Hadamard((MatrixBase<T>)lhs, (MatrixBase<T>)rhs));
}
template <typename T>
Matrix3x3<T> Hadamard(Matrix3x3<T> const &lhs, Matrix3x3<T> const &rhs) {
  Matrix3x3<T>(Hadamard((MatrixBase<T>)lhs, (MatrixBase<T>)rhs));
}
template <typename T>
Matrix4x4<T> Hadamard(Matrix4x4<T> const &lhs, Matrix4x4<T> const &rhs) {
  Matrix4x4<T>(Hadamard((MatrixBase<T>)lhs, (MatrixBase<T>)rhs));
}
template <typename T> Matrix2x2<T> Transpose(Matrix2x2<T> const &matrix) {
  return Matrix2x2<T>(matrix.AcquireTransposed());
}
template <typename T> Matrix3x3<T> Transpose(Matrix3x3<T> const &matrix) {
  return Matrix3x3<T>(matrix.AcquireTransposed());
}
template <typename T> Matrix4x4<T> Transpose(Matrix4x4<T> const &matrix) {
  return Matrix4x4<T>(matrix.AcquireTransposed());
}
template <typename T> Matrix2x2<T> Inverse(Matrix2x2<T> const &matrix) {
  return Matrix2x2<T>(matrix.AcquireInversed());
}
template <typename T> Matrix3x3<T> Inverse(Matrix3x3<T> const &matrix) {
  return Matrix3x3<T>(matrix.AcquireInversed());
}
template <typename T> Matrix4x4<T> Inverse(Matrix4x4<T> const &matrix) {
  return Matrix4x4<T>(matrix.AcquireInversed());
}

template <typename T>
Matrix2x2<T> operator+(Matrix2x2<T> const &lhs, Matrix2x2<T> const &rhs) {
  return Matrix2x2<T>(static_cast<MatrixBase<T>>(lhs) +
                      static_cast<MatrixBase<T>>(rhs));
}
template <typename T>
Matrix2x2<T> operator-(Matrix2x2<T> const &lhs, Matrix2x2<T> const &rhs) {
  return Matrix2x2<T>(static_cast<MatrixBase<T>>(lhs) -
                      static_cast<MatrixBase<T>>(rhs));
}
template <typename T>
Matrix2x2<T> operator*(Matrix2x2<T> const &lhs, Matrix2x2<T> const &rhs) {
  return Matrix2x2<T>(static_cast<MatrixBase<T>>(lhs) *
                      static_cast<MatrixBase<T>>(rhs));
}
template <typename T>
Matrix2x2<T> operator+(Matrix2x2<T> const &lhs, T const &rhs) {
  return Matrix2x2<T>(static_cast<MatrixBase<T>>(lhs) + rhs);
}
template <typename T>
Matrix2x2<T> operator-(Matrix2x2<T> const &lhs, T const &rhs) {
  return Matrix2x2<T>(static_cast<MatrixBase<T>>(lhs) - rhs);
}
template <typename T>
Matrix2x2<T> operator*(Matrix2x2<T> const &lhs, T const &rhs) {
  return Matrix2x2<T>(static_cast<MatrixBase<T>>(lhs) * rhs);
}
template <typename T>
Matrix2x2<T> operator/(Matrix2x2<T> const &lhs, T const &rhs) {
  return Matrix2x2<T>(static_cast<MatrixBase<T>>(lhs) / rhs);
}
template <typename T>
Matrix2x2<T> operator+(T const &lhs, Matrix2x2<T> const &rhs) {
  return Matrix2x2<T>(lhs + static_cast<MatrixBase<T>>(rhs));
}
template <typename T>
Matrix2x2<T> operator-(T const &lhs, Matrix2x2<T> const &rhs) {
  return Matrix2x2<T>(lhs - static_cast<MatrixBase<T>>(rhs));
}
template <typename T>
Matrix2x2<T> operator*(T const &lhs, Matrix2x2<T> const &rhs) {
  return Matrix2x2<T>(lhs * static_cast<MatrixBase<T>>(rhs));
}

template <typename T>
Matrix3x3<T> operator+(Matrix3x3<T> const &lhs, Matrix3x3<T> const &rhs) {
  return Matrix3x3<T>(static_cast<MatrixBase<T>>(lhs) +
                      static_cast<MatrixBase<T>>(rhs));
}
template <typename T>
Matrix3x3<T> operator-(Matrix3x3<T> const &lhs, Matrix3x3<T> const &rhs) {
  return Matrix3x3<T>(static_cast<MatrixBase<T>>(lhs) -
                      static_cast<MatrixBase<T>>(rhs));
}
template <typename T>
Matrix3x3<T> operator*(Matrix3x3<T> const &lhs, Matrix3x3<T> const &rhs) {
  return Matrix3x3<T>(static_cast<MatrixBase<T>>(lhs) *
                      static_cast<MatrixBase<T>>(rhs));
}
template <typename T>
Matrix3x3<T> operator+(Matrix3x3<T> const &lhs, T const &rhs) {
  return Matrix3x3<T>(static_cast<MatrixBase<T>>(lhs) + rhs);
}
template <typename T>
Matrix3x3<T> operator-(Matrix3x3<T> const &lhs, T const &rhs) {
  return Matrix3x3<T>(static_cast<MatrixBase<T>>(lhs) - rhs);
}
template <typename T>
Matrix3x3<T> operator*(Matrix3x3<T> const &lhs, T const &rhs) {
  return Matrix3x3<T>(static_cast<MatrixBase<T>>(lhs) * rhs);
}
template <typename T>
Matrix3x3<T> operator/(Matrix3x3<T> const &lhs, T const &rhs) {
  return Matrix3x3<T>(static_cast<MatrixBase<T>>(lhs) / rhs);
}
template <typename T>
Matrix3x3<T> operator+(T const &lhs, Matrix3x3<T> const &rhs) {
  return Matrix3x3<T>(lhs + static_cast<MatrixBase<T>>(rhs));
}
template <typename T>
Matrix3x3<T> operator-(T const &lhs, Matrix3x3<T> const &rhs) {
  return Matrix3x3<T>(lhs - static_cast<MatrixBase<T>>(rhs));
}
template <typename T>
Matrix3x3<T> operator*(T const &lhs, Matrix3x3<T> const &rhs) {
  return Matrix3x3<T>(lhs * static_cast<MatrixBase<T>>(rhs));
}

template <typename T>
Matrix4x4<T> operator+(Matrix4x4<T> const &lhs, Matrix4x4<T> const &rhs) {
  return Matrix4x4<T>(static_cast<MatrixBase<T>>(lhs) +
                      static_cast<MatrixBase<T>>(rhs));
}
template <typename T>
Matrix4x4<T> operator-(Matrix4x4<T> const &lhs, Matrix4x4<T> const &rhs) {
  return Matrix4x4<T>(static_cast<MatrixBase<T>>(lhs) -
                      static_cast<MatrixBase<T>>(rhs));
}
template <typename T>
Matrix4x4<T> operator*(Matrix4x4<T> const &lhs, Matrix4x4<T> const &rhs) {
  return Matrix4x4<T>(static_cast<MatrixBase<T>>(lhs) *
                      static_cast<MatrixBase<T>>(rhs));
}
template <typename T>
Matrix4x4<T> operator+(Matrix4x4<T> const &lhs, T const &rhs) {
  return Matrix4x4<T>(static_cast<MatrixBase<T>>(lhs) + rhs);
}
template <typename T>
Matrix4x4<T> operator-(Matrix4x4<T> const &lhs, T const &rhs) {
  return Matrix4x4<T>(static_cast<MatrixBase<T>>(lhs) - rhs);
}
template <typename T>
Matrix4x4<T> operator*(Matrix4x4<T> const &lhs, T const &rhs) {
  return Matrix4x4<T>(static_cast<MatrixBase<T>>(lhs) * rhs);
}
template <typename T>
Matrix4x4<T> operator/(Matrix4x4<T> const &lhs, T const &rhs) {
  return Matrix4x4<T>(static_cast<MatrixBase<T>>(lhs) / rhs);
}
template <typename T>
Matrix4x4<T> operator+(T const &lhs, Matrix4x4<T> const &rhs) {
  return Matrix4x4<T>(lhs + static_cast<MatrixBase<T>>(rhs));
}
template <typename T>
Matrix4x4<T> operator-(T const &lhs, Matrix4x4<T> const &rhs) {
  return Matrix4x4<T>(lhs - static_cast<MatrixBase<T>>(rhs));
}
template <typename T>
Matrix4x4<T> operator*(T const &lhs, Matrix4x4<T> const &rhs) {
  return Matrix4x4<T>(lhs * static_cast<MatrixBase<T>>(rhs));
}

template <typename T>
Matrix2x2<T> Dot(ColumnVector2D<T> const &lhs, RowVector2D<T> const &rhs) {
  return Matrix2x2<T>(static_cast<MatrixBase<T>>(lhs) *
                      static_cast<MatrixBase<T>>(rhs));
}
template <typename T>
T Dot(ColumnVector2D<T> const &lhs, ColumnVector2D<T> const &rhs) {
  return Dot(static_cast<MatrixBase<T>>(lhs),
             static_cast<MatrixBase<T>>(rhs))(0, 0);
}
template <typename T>
Matrix3x3<T> Dot(ColumnVector3D<T> const &lhs, RowVector3D<T> const &rhs) {
  return Matrix3x3<T>(static_cast<MatrixBase<T>>(lhs) *
                      static_cast<MatrixBase<T>>(rhs));
}
template <typename T>
T Dot(ColumnVector3D<T> const &lhs, ColumnVector3D<T> const &rhs) {
  return Dot(static_cast<MatrixBase<T>>(lhs),
             static_cast<MatrixBase<T>>(rhs))(0, 0);
}
template <typename T>
Matrix4x4<T> Dot(ColumnVector4D<T> const &lhs, RowVector4D<T> const &rhs) {
  return Matrix4x4<T>(static_cast<MatrixBase<T>>(lhs) *
                      static_cast<MatrixBase<T>>(rhs));
}
template <typename T>
T Dot(ColumnVector4D<T> const &lhs, ColumnVector4D<T> const &rhs) {
  return Dot(static_cast<MatrixBase<T>>(lhs),
             static_cast<MatrixBase<T>>(rhs))(0, 0);
}
} // namespace TerreateMath::Matrix

namespace TerreateMath::Matrix {
using namespace TerreateMath::Defines;

template <typename T> MatrixNxN<T> &MatrixNxN<T>::operator=(T const &value) {
  MatrixBase<T>::operator=(value);
  return *this;
}

template <typename T>
MatrixNxN<T> &MatrixNxN<T>::operator=(Vec<T> const &value) {
  MatrixBase<T>::operator=(value);
  return *this;
}

template <typename T>
MatrixNxN<T> &MatrixNxN<T>::operator=(Vec<Vec<T>> const &value) {
  MatrixBase<T>::operator=(value);
  return *this;
}

template <typename T>
MatrixNxN<T> &MatrixNxN<T>::operator=(MatrixNxN<T> const &other) {
  MatrixBase<T>::operator=(other);
  return *this;
}

template <typename T>
MatrixNxN<T> &MatrixNxN<T>::operator=(MatrixNxN<T> &&other) {
  MatrixBase<T>::operator=(std::move(other));
  return *this;
}

template <typename T>
MatrixNxN<T> &MatrixNxN<T>::operator=(MatrixBase<T> const &other) {
  MatrixBase<T>::operator=(other);
  return *this;
}

template <typename T>
MatrixNxN<T> &MatrixNxN<T>::operator=(MatrixBase<T> &&other) {
  MatrixBase<T>::operator=(std::move(other));
  return *this;
}

template <typename T> Matrix2x2<T> &Matrix2x2<T>::operator=(T const &value) {
  MatrixNxN<T>::operator=(value);
  return *this;
}

template <typename T>
Matrix2x2<T> &Matrix2x2<T>::operator=(Vec<T> const &value) {
  MatrixNxN<T>::operator=(value);
  return *this;
}

template <typename T>
Matrix2x2<T> &Matrix2x2<T>::operator=(Vec<Vec<T>> const &value) {
  MatrixNxN<T>::operator=(value);
  return *this;
}

template <typename T>
Matrix2x2<T> &Matrix2x2<T>::operator=(Matrix2x2<T> const &other) {
  MatrixNxN<T>::operator=(other);
  return *this;
}

template <typename T>
Matrix2x2<T> &Matrix2x2<T>::operator=(Matrix2x2<T> &&other) {
  MatrixNxN<T>::operator=(std::move(other));
  return *this;
}

template <typename T>
Matrix2x2<T> &Matrix2x2<T>::operator=(MatrixBase<T> const &other) {
  MatrixNxN<T>::operator=(other);
  return *this;
}

template <typename T>
Matrix2x2<T> &Matrix2x2<T>::operator=(MatrixBase<T> &&other) {
  MatrixNxN<T>::operator=(std::move(other));
  return *this;
}

template <typename T> Matrix3x3<T> &Matrix3x3<T>::operator=(T const &value) {
  MatrixNxN<T>::operator=(value);
  return *this;
}

template <typename T>
Matrix3x3<T> &Matrix3x3<T>::operator=(Vec<T> const &value) {
  MatrixNxN<T>::operator=(value);
  return *this;
}

template <typename T>
Matrix3x3<T> &Matrix3x3<T>::operator=(Vec<Vec<T>> const &value) {
  MatrixNxN<T>::operator=(value);
  return *this;
}

template <typename T>
Matrix3x3<T> &Matrix3x3<T>::operator=(Matrix3x3<T> const &other) {
  MatrixNxN<T>::operator=(other);
  return *this;
}

template <typename T>
Matrix3x3<T> &Matrix3x3<T>::operator=(Matrix3x3<T> &&other) {
  MatrixNxN<T>::operator=(std::move(other));
  return *this;
}

template <typename T>
Matrix3x3<T> &Matrix3x3<T>::operator=(MatrixBase<T> const &other) {
  MatrixNxN<T>::operator=(other);
  return *this;
}

template <typename T>
Matrix3x3<T> &Matrix3x3<T>::operator=(MatrixBase<T> &&other) {
  MatrixNxN<T>::operator=(std::move(other));
  return *this;
}

template <typename T> Matrix4x4<T> &Matrix4x4<T>::operator=(T const &value) {
  MatrixNxN<T>::operator=(value);
  return *this;
}

template <typename T>
Matrix4x4<T> &Matrix4x4<T>::operator=(Vec<T> const &value) {
  MatrixNxN<T>::operator=(value);
  return *this;
}

template <typename T>
Matrix4x4<T> &Matrix4x4<T>::operator=(Vec<Vec<T>> const &value) {
  MatrixNxN<T>::operator=(value);
  return *this;
}

template <typename T>
Matrix4x4<T> &Matrix4x4<T>::operator=(Matrix4x4<T> const &other) {
  MatrixNxN<T>::operator=(other);
  return *this;
}

template <typename T>
Matrix4x4<T> &Matrix4x4<T>::operator=(Matrix4x4<T> &&other) {
  MatrixNxN<T>::operator=(std::move(other));
  return *this;
}

template <typename T>
Matrix4x4<T> &Matrix4x4<T>::operator=(MatrixBase<T> const &other) {
  MatrixNxN<T>::operator=(other);
  return *this;
}

template <typename T>
Matrix4x4<T> &Matrix4x4<T>::operator=(MatrixBase<T> &&other) {
  MatrixNxN<T>::operator=(std::move(other));
  return *this;
}
} // namespace TerreateMath::Matrix

#endif // __TC_MATH_MATRIXNXN_HPP__
