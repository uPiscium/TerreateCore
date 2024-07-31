#ifndef __TC_MATH_CORE_HPP__
#define __TC_MATH_CORE_HPP__

#include <stdexcept>
#ifndef EPSILON
#define EPSILON 1e-6
#endif // EPSILON

#include <cmath>
#include <cstring>
#include <iomanip>

#include "defines.hpp"

namespace TerreateMath::Core {
using namespace TerreateMath::Defines;

template <typename T> inline T Abs(T const &value) {
  return static_cast<T>(fabs(static_cast<double>(value)));
}

template <typename T> struct MatrixTypeTraits {
  static Str ToString(T const &value) { return std::to_string(value); }
};

template <typename T> class MatrixBase {
private:
  T *mArray = nullptr;
  Uint mRow = 0;
  Uint mColumn = 0;

public:
  MatrixBase() {}
  MatrixBase(Uint const &row, Uint const &column);
  MatrixBase(Uint const &row, Uint const &column, T const *array);
  MatrixBase(Uint const &row, Uint const &column, T const &value);
  MatrixBase(Uint const &row, Uint const &column, Vec<T> const &value);
  MatrixBase(Vec<Vec<T>> const &value);
  MatrixBase(MatrixBase<T> const &other);
  MatrixBase(MatrixBase<T> &&other);
  template <typename U>
  MatrixBase(Uint const &row, Uint const &column, U const *array);
  template <typename U>
  MatrixBase(Uint const &row, Uint const &column, U const &value);
  template <typename U>
  MatrixBase(Uint const &row, Uint const &column, Vec<U> const &value);
  template <typename U> MatrixBase(Vec<Vec<U>> const &value);
  template <typename U> MatrixBase(MatrixBase<U> const &other);
  ~MatrixBase();

  Uint GetSize() const { return mRow * mColumn; }
  Uint GetRow() const { return mRow; }
  Uint GetColumn() const { return mColumn; }
  T *GetArray() { return mArray; }
  T const *GetArray() const { return mArray; }
  MatrixBase<T> GetCopy() const { return MatrixBase<T>(*this); }

  Uint AcquireMaxDigit() const;
  T AcquireMaxValue() const;
  T AcquireMinValue() const;
  Uint AcquireRank() const;
  T AcquireDeterminant() const;
  MatrixBase<T> AcquireRow(Uint const &row) const;
  MatrixBase<T> AcquireColumn(Uint const &column) const;
  MatrixBase<T> AcquireCofactor(Uint const &row, Uint const &column) const;
  MatrixBase<T> AcquireTransposed() const;
  MatrixBase<T> AcquireUpperTriangular(int *c = nullptr) const;
  MatrixBase<T> AcquireInversed() const;

  void SetRow(Uint const &row, T const *value);
  void SetRow(Uint const &row, Vec<T> const &value);
  void SetRow(Uint const &row, MatrixBase<T> const &value);
  void SetColumn(Uint const &column, T const *value);
  void SetColumn(Uint const &column, Vec<T> const &value);
  void SetColumn(Uint const &column, MatrixBase<T> const &value);

  Uint SearchNonZeroRow(Uint const &row, Uint const &start = 0) const;
  Uint SearchNonZeroColumn(Uint const &column, Uint const &start = 0) const;
  void SwapRow(Uint const &row1, Uint const &row2);
  void SwapColumn(Uint const &column1, Uint const &column2);
  void MultiplyRow(Uint const &row, T const &value);
  void MultiplyColumn(Uint const &column, T const &value);
  void AddRow(Uint const &row1, Uint const &row2, T const &value);
  void AddColumn(Uint const &column1, Uint const &column2, T const &value);

  void LU(MatrixBase<T> &L, MatrixBase<T> &U) const;

  void Transpose();
  void UpperTriangulate(int *c = nullptr);
  void Inverse();

  MatrixBase<T> operator+() const { return *this; }
  MatrixBase<T> operator-() const;

  MatrixBase<T> &operator=(T const &value);
  MatrixBase<T> &operator=(Vec<T> const &value);
  MatrixBase<T> &operator=(Vec<Vec<T>> const &value);
  MatrixBase<T> &operator=(MatrixBase<T> const &other);
  MatrixBase<T> &operator=(MatrixBase<T> &&other);

  T &operator()(Uint const &row, Uint const &column) {
    return mArray[row * mColumn + column];
  }
  T const &operator()(Uint const &row, Uint const &column) const {
    return mArray[row * mColumn + column];
  }

  MatrixBase<T> operator+=(MatrixBase<T> const &other);
  MatrixBase<T> operator-=(MatrixBase<T> const &other);
  MatrixBase<T> operator*=(MatrixBase<T> const &other);
  MatrixBase<T> operator+=(T const &value);
  MatrixBase<T> operator-=(T const &value);
  MatrixBase<T> operator*=(T const &value);
  MatrixBase<T> operator/=(T const &value);

  operator T *() { return mArray; }
  operator T const *() const { return mArray; }
};

template <typename T>
inline MatrixBase<T> Dot(MatrixBase<T> const &lhs, MatrixBase<T> const &rhs);
template <typename T>
inline MatrixBase<T> Hadamard(MatrixBase<T> const &lhs,
                              MatrixBase<T> const &rhs);
template <typename T>
inline MatrixBase<T> Transpose(MatrixBase<T> const &matrix) {
  return matrix.AcquireTransposed();
}
template <typename T>
inline MatrixBase<T> UpperTriangulate(MatrixBase<T> const &matrix) {
  return matrix.AcquireUpperTriangular();
}
template <typename T>
inline MatrixBase<T> Inverse(MatrixBase<T> const &matrix) {
  return matrix.AcquireInversed();
}
template <typename T> inline MatrixBase<T> Eye(Uint const &size);

template <typename T>
inline MatrixBase<T> operator+(MatrixBase<T> const &lhs,
                               MatrixBase<T> const &rhs);
template <typename T>
inline MatrixBase<T> operator-(MatrixBase<T> const &lhs,
                               MatrixBase<T> const &rhs);
template <typename T>
inline MatrixBase<T> operator*(MatrixBase<T> const &lhs,
                               MatrixBase<T> const &rhs) {
  return Dot(lhs, rhs);
}
template <typename T>
inline MatrixBase<T> operator+(MatrixBase<T> const &lhs, T const &rhs);
template <typename T>
inline MatrixBase<T> operator-(MatrixBase<T> const &lhs, T const &rhs);
template <typename T>
inline MatrixBase<T> operator*(MatrixBase<T> const &lhs, T const &rhs);
template <typename T>
inline MatrixBase<T> operator/(MatrixBase<T> const &lhs, T const &rhs);
template <typename T>
inline MatrixBase<T> operator+(T const &lhs, MatrixBase<T> const &rhs);
template <typename T>
inline MatrixBase<T> operator-(T const &lhs, MatrixBase<T> const &rhs);
template <typename T>
inline MatrixBase<T> operator*(T const &lhs, MatrixBase<T> const &rhs);

template <typename T>
inline Bool operator==(MatrixBase<T> const &lhs, MatrixBase<T> const &rhs);
template <typename T>
inline Bool operator!=(MatrixBase<T> const &lhs, MatrixBase<T> const &rhs) {
  return !(lhs == rhs);
}
} // namespace TerreateMath::Core
template <typename T>
inline std::ostream &
operator<<(std::ostream &os, TerreateMath::Core::MatrixBase<T> const &matrix);

// Implementation
namespace TerreateMath::Core {
using namespace TerreateMath::Defines;

template <typename T>
MatrixBase<T>::MatrixBase(Uint const &row, Uint const &column)
    : mRow(row), mColumn(column) {
  mArray = new T[mRow * mColumn];
  for (Uint i = 0; i < mRow * mColumn; ++i) {
    mArray[i] = 0;
  }
}

template <typename T>
MatrixBase<T>::MatrixBase(Uint const &row, Uint const &column, T const *array)
    : mRow(row), mColumn(column) {
  mArray = new T[mRow * mColumn];
  memcpy(mArray, array, sizeof(T) * mRow * mColumn);
}

template <typename T>
MatrixBase<T>::MatrixBase(Uint const &row, Uint const &column, T const &value)
    : mRow(row), mColumn(column) {
  mArray = new T[mRow * mColumn];
  for (Uint i = 0; i < mRow * mColumn; ++i) {
    mArray[i] = value;
  }
}

template <typename T>
MatrixBase<T>::MatrixBase(Uint const &row, Uint const &column,
                          Vec<T> const &value)
    : mRow(row), mColumn(column) {
  mArray = new T[mRow * mColumn];
  for (Uint i = 0; i < mRow; ++i) {
    for (Uint j = 0; j < mColumn; ++j) {
      mArray[i * mColumn + j] = value[i * mColumn + j];
    }
  }
}

template <typename T> MatrixBase<T>::MatrixBase(Vec<Vec<T>> const &value) {
  mRow = value.size();
  mColumn = value[0].size();
  mArray = new T[mRow * mColumn];
  for (Uint i = 0; i < mRow; ++i) {
    for (Uint j = 0; j < mColumn; ++j) {
      mArray[i * mColumn + j] = value[i][j];
    }
  }
}

template <typename T>
MatrixBase<T>::MatrixBase(MatrixBase<T> const &other)
    : mRow(other.mRow), mColumn(other.mColumn) {
  mArray = new T[mRow * mColumn];
  memcpy(mArray, other.mArray, sizeof(T) * mRow * mColumn);
}

template <typename T>
MatrixBase<T>::MatrixBase(MatrixBase<T> &&other)
    : mRow(other.mRow), mColumn(other.mColumn) {
  mArray = other.mArray;
  other.mRow = 0;
  other.mColumn = 0;
  other.mArray = nullptr;
}

template <typename T>
template <typename U>
MatrixBase<T>::MatrixBase(Uint const &row, Uint const &column, U const *array)
    : mRow(row), mColumn(column) {
  mArray = new T[mRow * mColumn];
  for (Uint i = 0; i < mRow * mColumn; ++i) {
    mArray[i] = static_cast<T>(array[i]);
  }
}

template <typename T>
template <typename U>
MatrixBase<T>::MatrixBase(Uint const &row, Uint const &column, U const &value)
    : mRow(row), mColumn(column) {
  mArray = new T[mRow * mColumn];
  for (Uint i = 0; i < mRow * mColumn; ++i) {
    mArray[i] = static_cast<T>(value);
  }
}

template <typename T>
template <typename U>
MatrixBase<T>::MatrixBase(Uint const &row, Uint const &column,
                          Vec<U> const &value)
    : mRow(row), mColumn(column) {
  mArray = new T[mRow * mColumn];
  for (Uint i = 0; i < mRow; ++i) {
    for (Uint j = 0; j < mColumn; ++j) {
      mArray[i * mColumn + j] = static_cast<T>(value[j]);
    }
  }
}

template <typename T>
template <typename U>
MatrixBase<T>::MatrixBase(Vec<Vec<U>> const &value) {
  mRow = value.size();
  mColumn = value[0].size();
  mArray = new T[mRow * mColumn];
  for (Uint i = 0; i < mRow; ++i) {
    for (Uint j = 0; j < mColumn; ++j) {
      mArray[i * mColumn + j] = static_cast<T>(value[i][j]);
    }
  }
}

template <typename T>
template <typename U>
MatrixBase<T>::MatrixBase(MatrixBase<U> const &other)
    : mRow(other.GetRow()), mColumn(other.GetColumn()) {
  mArray = new T[mRow * mColumn];
  for (Uint i = 0; i < mRow * mColumn; ++i) {
    mArray[i] = static_cast<T>(other.GetArray()[i]);
  }
}

template <typename T> MatrixBase<T>::~MatrixBase() {
  if (mArray != nullptr) {
    delete[] mArray;
    mArray = nullptr;
  }
}

template <typename T> Uint MatrixBase<T>::AcquireMaxDigit() const {
  Uint maxDigit = 0;
  for (Uint i = 0; i < mRow * mColumn; ++i) {
    Str str = MatrixTypeTraits<T>::ToString(mArray[i]);
    Uint digit = str.size();
    if (maxDigit < digit) {
      maxDigit = digit;
    }
  }
  return maxDigit;
}

template <typename T> T MatrixBase<T>::AcquireMaxValue() const {
  T max = mArray[0];
  for (Uint i = 1; i < mRow * mColumn; ++i) {
    if (max < mArray[i]) {
      max = mArray[i];
    }
  }
  return max;
}

template <typename T> T MatrixBase<T>::AcquireMinValue() const {
  T min = mArray[0];
  for (Uint i = 1; i < mRow * mColumn; ++i) {
    if (min > mArray[i]) {
      min = mArray[i];
    }
  }
  return min;
}

template <typename T> Uint MatrixBase<T>::AcquireRank() const {
  MatrixBase<T> upper = AcquireUpperTriangular();
  Uint rank = 0;
  for (Uint i = 0; i < mRow; ++i) {
    if (upper.SearchNonZeroRow(i, i) < mColumn) {
      ++rank;
    }
  }
  return rank;
}

template <typename T> T MatrixBase<T>::AcquireDeterminant() const {
  if (mRow != mColumn) {
    std::runtime_error("Matrix is not square.");
  }
  if (mRow == 1) {
    return mArray[0];
  }
  if (mRow == 2) {
    return mArray[0] * mArray[3] - mArray[1] * mArray[2];
  }
  Int c = 0;
  T det = 1;
  MatrixBase<T> triangle = AcquireUpperTriangular(&c);
  for (Uint i = 0; i < mRow; ++i) {
    T cii = triangle(i, i);
    if (Abs(cii) < EPSILON) {
      return 0;
    }
    det *= cii;
  }
  return c * det;
}

template <typename T>
MatrixBase<T> MatrixBase<T>::AcquireRow(Uint const &row) const {
  MatrixBase<T> rowMatrix(1, mColumn);
  for (Uint i = 0; i < mColumn; ++i) {
    rowMatrix(0, i) = (*this)(row, i);
  }
  return rowMatrix;
}

template <typename T>
MatrixBase<T> MatrixBase<T>::AcquireColumn(Uint const &column) const {
  MatrixBase<T> columnMatrix(mRow, 1);
  for (Uint i = 0; i < mRow; ++i) {
    columnMatrix(i, 0) = (*this)(i, column);
  }
  return columnMatrix;
}

template <typename T>
MatrixBase<T> MatrixBase<T>::AcquireCofactor(Uint const &row,
                                             Uint const &column) const {
  MatrixBase<T> cofactor(mRow - 1, mColumn - 1);
  for (Uint i = 0; i < mRow; ++i) {
    if (i == row) {
      continue;
    }
    for (Uint j = 0; j < mColumn; ++j) {
      if (j == column) {
        continue;
      }
      Uint r = i < row ? i : i - 1;
      Uint c = j < column ? j : j - 1;
      cofactor(r, c) = (*this)(i, j);
    }
  }
  return cofactor;
}

template <typename T> MatrixBase<T> MatrixBase<T>::AcquireTransposed() const {
  MatrixBase<T> transposed(mColumn, mRow);
  for (Uint i = 0; i < mRow; ++i) {
    for (Uint j = 0; j < mColumn; ++j) {
      transposed(j, i) = (*this)(i, j);
    }
  }
  return transposed;
}

template <typename T>
MatrixBase<T> MatrixBase<T>::AcquireUpperTriangular(int *c) const {
  MatrixBase<T> upper = *this;
  if (c) {
    *c = 1;
  }
  for (Uint i = 0; i < mRow; ++i) {
    Uint j = upper.SearchNonZeroRow(i, i);
    if (j == mColumn) {
      continue;
    }

    if (j != i) {
      upper.SwapRow(i, j);
      if (c) {
        *c = -*c;
      }
    }

    for (Uint j = i + 1; j < mRow; ++j) {
      T value = upper(j, i) / upper(i, i);
      upper.AddRow(j, i, -value);
    }
  }
  return upper;
}

template <typename T> MatrixBase<T> MatrixBase<T>::AcquireInversed() const {
  if (mRow != mColumn) {
    std::runtime_error("Matrix is not square.");
  }

  MatrixBase<T> inverse = Eye<T>(mRow);
  MatrixBase<T> current = this->GetCopy();

  for (Uint i = 0; i < mRow; ++i) {
    Uint j = current.SearchNonZeroRow(i, i);
    if (j == mColumn) {
      std::runtime_error("Matrix is not inversable.");
    }

    if (j != i) {
      current.SwapRow(i, j);
      inverse.SwapRow(i, j);
    }

    T value = current(i, i);
    current.MultiplyRow(i, 1 / value);
    inverse.MultiplyRow(i, 1 / value);

    for (Uint j = 0; j < mRow; ++j) {
      if (j == i) {
        continue;
      }

      T value = current(j, i);
      current.AddRow(j, i, -value);
      inverse.AddRow(j, i, -value);
    }
  }
  return inverse;
}

template <typename T>
void MatrixBase<T>::SetRow(Uint const &row, T const *value) {
  if (row < 0 || mRow <= row) {
    std::runtime_error("Index out of range.");
  }

  for (Uint i = 0; i < mColumn; ++i) {
    mArray[row * mColumn + i] = value[i];
  }
}

template <typename T>
void MatrixBase<T>::SetRow(Uint const &row, Vec<T> const &value) {
  if (row < 0 || mRow <= row) {
    std::runtime_error("Index out of range.");
  }

  for (Uint i = 0; i < mColumn; ++i) {
    mArray[row * mColumn + i] = value[i];
  }
}

template <typename T>
void MatrixBase<T>::SetRow(Uint const &row, MatrixBase<T> const &value) {
  if (row < 0 || mRow <= row) {
    std::runtime_error("Index out of range.");
  }

  for (Uint i = 0; i < mColumn; ++i) {
    mArray[row * mColumn + i] = value(i, 0);
  }
}

template <typename T>
void MatrixBase<T>::SetColumn(Uint const &column, T const *value) {
  if (column < 0 || mColumn <= column) {
    std::runtime_error("Index out of range.");
  }

  for (Uint i = 0; i < mRow; ++i) {
    mArray[i * mColumn + column] = value[i];
  }
}

template <typename T>
void MatrixBase<T>::SetColumn(Uint const &column, Vec<T> const &value) {
  if (column < 0 || mColumn <= column) {
    std::runtime_error("Index out of range.");
  }

  for (Uint i = 0; i < mRow; ++i) {
    mArray[i * mColumn + column] = value[i];
  }
}

template <typename T>
void MatrixBase<T>::SetColumn(Uint const &column, MatrixBase<T> const &value) {
  if (column < 0 || mColumn <= column) {
    std::runtime_error("Index out of range.");
  }

  for (Uint i = 0; i < mRow; ++i) {
    mArray[i * mColumn + column] = value(0, i);
  }
}

template <typename T>
Uint MatrixBase<T>::SearchNonZeroRow(Uint const &row, Uint const &start) const {
  for (Uint i = (0 <= start || start < mColumn) ? start : 0; i < mColumn; ++i) {
    if (Abs((*this)(row, i)) > EPSILON) {
      return i;
    }
  }
  return mColumn;
}

template <typename T>
Uint MatrixBase<T>::SearchNonZeroColumn(Uint const &column,
                                        Uint const &start) const {
  for (Uint i = (0 <= start || start < mRow) ? start : 0; i < mRow; ++i) {
    if (Abs((*this)(i, column)) > EPSILON) {
      return i;
    }
  }
  return mRow;
}

template <typename T>
void MatrixBase<T>::SwapRow(Uint const &row1, Uint const &row2) {
  if (row1 < 0 || mRow <= row1 || row2 < 0 || mRow <= row2) {
    std::runtime_error("Index out of range.");
  }

  for (Uint i = 0; i < mColumn; ++i) {
    T temp = mArray[row1 * mColumn + i];
    mArray[row1 * mColumn + i] = mArray[row2 * mColumn + i];
    mArray[row2 * mColumn + i] = temp;
  }
}

template <typename T>
void MatrixBase<T>::SwapColumn(Uint const &column1, Uint const &column2) {
  if (column1 < 0 || mColumn <= column1 || column2 < 0 || mColumn <= column2) {
    std::runtime_error("Index out of range");
  }

  for (Uint i = 0; i < mRow; ++i) {
    T temp = mArray[i * mColumn + column1];
    mArray[i * mColumn + column1] = mArray[i * mColumn + column2];
    mArray[i * mColumn + column2] = temp;
  }
}

template <typename T>
void MatrixBase<T>::MultiplyRow(Uint const &row, T const &value) {
  if (row < 0 || mRow <= row) {
    std::runtime_error("Index out of range.");
  }

  for (Uint i = 0; i < mColumn; ++i) {
    mArray[row * mColumn + i] *= value;
  }
}

template <typename T>
void MatrixBase<T>::MultiplyColumn(Uint const &column, T const &value) {
  if (column < 0 || mColumn <= column) {
    std::runtime_error("Index out of range.");
  }

  for (Uint i = 0; i < mRow; ++i) {
    mArray[i * mColumn + column] *= value;
  }
}

template <typename T>
void MatrixBase<T>::AddRow(Uint const &row1, Uint const &row2, T const &value) {
  if (row1 < 0 || mRow <= row1 || row2 < 0 || mRow <= row2) {
    std::runtime_error("Index out of range.");
  }

  for (Uint i = 0; i < mColumn; ++i) {
    mArray[row1 * mColumn + i] += mArray[row2 * mColumn + i] * value;
  }
}

template <typename T>
void MatrixBase<T>::AddColumn(Uint const &column1, Uint const &column2,
                              T const &value) {
  if (column1 < 0 || mColumn <= column1 || column2 < 0 || mColumn <= column2) {
    std::runtime_error("Index out of range");
  }

  for (Uint i = 0; i < mRow; ++i) {
    mArray[i * mColumn + column1] += mArray[i * mColumn + column2] * value;
  }
}

template <typename T>
void MatrixBase<T>::LU(MatrixBase<T> &L, MatrixBase<T> &U) const {
  if (mRow != mColumn) {
    std::runtime_error("Matrix is not square.");
  }

  MatrixBase<T> current = this->GetCopy();
  MatrixBase<T> cofactor = MatrixBase();
  L = MatrixBase<T>(mRow, mColumn, 0);
  U = Eye<T>(mRow);
  MatrixBase<T> vl = MatrixBase<T>();
  MatrixBase<T> vu = MatrixBase<T>();
  T cnn = 0;
  Uint n = 0;

  for (Uint i = 0; i < mRow - 1; ++i) {
    n = (mRow - 1) - i;
    cnn = current(0, 0);
    Vec<T> vuArr, vlArr;
    for (Uint j = 0; j < n; ++j) {
      vuArr.push_back(current(0, j + 1));
      vlArr.push_back(current(j + 1, 0));
    }
    vu = MatrixBase(1, n, vuArr);
    vu /= cnn;
    vl = MatrixBase(n, 1, vlArr);
    cofactor = vl * vu;
    L(i, i) = cnn;
    for (Uint j = 0; j < n; ++j) {
      L(i + j + 1, i) = vl(j, 0);
      U(i, i + j + 1) = vu(0, j);
    }
    current = current.AcquireCofactor(0, 0) - cofactor;
  }
  L(mRow - 1, mRow - 1) = current(0, 0);
}

template <typename T> void MatrixBase<T>::Transpose() {
  MatrixBase<T> transposed = this->AcquireTransposed();
  mRow = transposed.GetRow();
  mColumn = transposed.GetColumn();
  memcpy(mArray, transposed.GetArray(), sizeof(T) * mRow * mColumn);
}

template <typename T> void MatrixBase<T>::UpperTriangulate(int *c) {
  MatrixBase<T> upper = this->AcquireUpperTriangular(c);
  memcpy(mArray, upper.GetArray(), sizeof(T) * mRow * mColumn);
}

template <typename T> void MatrixBase<T>::Inverse() {
  MatrixBase<T> inverse = this->AcquireInversed();
  memcpy(mArray, inverse.GetArray(), sizeof(T) * mRow * mColumn);
}

template <typename T> MatrixBase<T> MatrixBase<T>::operator-() const {
  MatrixBase<T> result = this->GetCopy();
  for (Uint i = 0; i < mRow * mColumn; ++i) {
    result[i] = -mArray[i];
  }
  return *this;
}

template <typename T> MatrixBase<T> &MatrixBase<T>::operator=(T const &value) {
  for (Uint i = 0; i < mRow * mColumn; ++i) {
    mArray[i] = value;
  }
  return *this;
}

template <typename T>
MatrixBase<T> &MatrixBase<T>::operator=(Vec<T> const &value) {
  if (mRow * mColumn != value.size()) {
    std::runtime_error("Data size is not matched.");
  }

  for (Uint i = 0; i < mRow; ++i) {
    for (Uint j = 0; j < mColumn; ++j) {
      mArray[i * mColumn + j] = value[j];
    }
  }
  return *this;
}

template <typename T>
MatrixBase<T> &MatrixBase<T>::operator=(Vec<Vec<T>> const &value) {
  if (mRow != value.size() || mColumn != value[0].size()) {
    std::runtime_error("Data size is not matched.");
  }

  for (Uint i = 0; i < mRow; ++i) {
    for (Uint j = 0; j < mColumn; ++j) {
      mArray[i * mColumn + j] = value[i][j];
    }
  }
  return *this;
}

template <typename T>
MatrixBase<T> &MatrixBase<T>::operator=(MatrixBase<T> const &other) {
  if (mRow != other.mRow || mColumn != other.mColumn) {
    if (mArray != nullptr) {
      delete[] mArray;
    }
    mRow = other.mRow;
    mColumn = other.mColumn;
    mArray = new T[mRow * mColumn];
  }
  memcpy(mArray, other.mArray, sizeof(T) * mRow * mColumn);
  return *this;
}

template <typename T>
MatrixBase<T> &MatrixBase<T>::operator=(MatrixBase<T> &&other) {
  if (mArray != nullptr) {
    delete[] mArray;
  }
  mRow = other.mRow;
  mColumn = other.mColumn;
  mArray = other.mArray;
  other.mRow = 0;
  other.mColumn = 0;
  other.mArray = nullptr;
  return *this;
}

template <typename T>
MatrixBase<T> MatrixBase<T>::operator+=(MatrixBase<T> const &other) {
  if (mRow != other.GetRow() || mColumn != other.GetColumn()) {
    std::runtime_error("Incompatible matrix size.");
  }

  for (Uint i = 0; i < mRow * mColumn; ++i) {
    mArray[i] += other.mArray[i];
  }
  return *this;
}

template <typename T>
MatrixBase<T> MatrixBase<T>::operator-=(MatrixBase<T> const &other) {
  if (mRow != other.GetRow() || mColumn != other.GetColumn()) {
    std::runtime_error("Incompatible matrix size.");
  }

  for (Uint i = 0; i < mRow * mColumn; ++i) {
    mArray[i] -= other.mArray[i];
  }
  return *this;
}

template <typename T>
MatrixBase<T> MatrixBase<T>::operator*=(MatrixBase<T> const &other) {
  if (mColumn != other.mRow) {
    std::runtime_error("Incompatible matrix size");
  }

  MatrixBase<T> result(mRow, other.mColumn);
  for (Uint i = 0; i < mRow; ++i) {
    for (Uint j = 0; j < other.mColumn; ++j) {
      for (Uint k = 0; k < mColumn; ++k) {
        result(i, j) += mArray[i * mColumn + k] * other(k, j);
      }
    }
  }
  *this = result;
  return *this;
}

template <typename T> MatrixBase<T> MatrixBase<T>::operator+=(T const &value) {
  for (Uint i = 0; i < mRow * mColumn; ++i) {
    mArray[i] += value;
  }
  return *this;
}

template <typename T> MatrixBase<T> MatrixBase<T>::operator-=(T const &value) {
  for (Uint i = 0; i < mRow * mColumn; ++i) {
    mArray[i] -= value;
  }
  return *this;
}

template <typename T> MatrixBase<T> MatrixBase<T>::operator*=(T const &value) {
  for (Uint i = 0; i < mRow * mColumn; ++i) {
    mArray[i] *= value;
  }
  return *this;
}

template <typename T> MatrixBase<T> MatrixBase<T>::operator/=(T const &value) {
  for (Uint i = 0; i < mRow * mColumn; ++i) {
    mArray[i] /= value;
  }
  return *this;
}

template <typename T>
inline MatrixBase<T> Dot(MatrixBase<T> const &lhs, MatrixBase<T> const &rhs) {
  if (lhs.GetColumn() != rhs.GetRow()) {
    std::runtime_error("Incompatible matrix size");
  }

  Uint row = lhs.GetRow();
  Uint column = rhs.GetColumn();
  MatrixBase<T> result(row, column);
  for (Uint i = 0; i < row; ++i) {
    for (Uint j = 0; j < column; ++j) {
      for (Uint k = 0; k < lhs.GetColumn(); ++k) {
        result(i, j) += lhs(i, k) * rhs(k, j);
      }
    }
  }
  return result;
}

template <typename T>
inline MatrixBase<T> Hadamard(MatrixBase<T> const &lhs,
                              MatrixBase<T> const &rhs) {
  if (lhs.GetRow() != rhs.GetRow() || lhs.GetColumn() != rhs.GetColumn()) {
    std::runtime_error("Incompatible matrix size.");
  }

  Vec<T> data(lhs.GetSize());
  T const *larr = lhs.GetArray();
  T const *rarr = rhs.GetArray();
  for (Uint i = 0; i < lhs.GetSize(); ++i) {
    data[i] = larr[i] * rarr[i];
  }
  return MatrixBase<T>(lhs.GetRow(), rhs.GetColumn(), data);
}

template <typename T> inline MatrixBase<T> Eye(Uint const &size) {
  MatrixBase<T> eye(size, size, 0);
  for (Uint i = 0; i < size; ++i) {
    eye(i, i) = 1;
  }
  return eye;
}

template <typename T>
inline MatrixBase<T> operator+(MatrixBase<T> const &lhs,
                               MatrixBase<T> const &rhs) {
  if (lhs.GetRow() != rhs.GetRow() || lhs.GetColumn() != rhs.GetColumn()) {
    std::runtime_error("Incompatible matrix size.");
  }

  MatrixBase<T> copy = lhs.GetCopy();
  copy += rhs;
  return copy;
}

template <typename T>
inline MatrixBase<T> operator-(MatrixBase<T> const &lhs,
                               MatrixBase<T> const &rhs) {
  if (lhs.GetRow() != rhs.GetRow() || lhs.GetColumn() != rhs.GetColumn()) {
    std::runtime_error("Incompatible matrix size.");
  }

  MatrixBase<T> copy = lhs.GetCopy();
  copy -= rhs;
  return copy;
}

template <typename T>
inline MatrixBase<T> operator+(MatrixBase<T> const &lhs, T const &rhs) {
  MatrixBase<T> copy = lhs.GetCopy();
  copy += rhs;
  return copy;
}

template <typename T>
inline MatrixBase<T> operator-(MatrixBase<T> const &lhs, T const &rhs) {
  MatrixBase<T> copy = lhs.GetCopy();
  copy -= rhs;
  return rhs;
}

template <typename T>
inline MatrixBase<T> operator*(MatrixBase<T> const &lhs, T const &rhs) {
  MatrixBase<T> copy = lhs.GetCopy();
  copy *= rhs;
  return copy;
}

template <typename T>
inline MatrixBase<T> operator/(MatrixBase<T> const &lhs, T const &rhs) {
  MatrixBase<T> copy = lhs.GetCopy();
  copy /= rhs;
  return copy;
}

template <typename T>
inline MatrixBase<T> operator+(T const &lhs, MatrixBase<T> const &rhs) {
  MatrixBase<T> result(rhs.GetRow(), rhs.GetColumn(), lhs);
  result += rhs;
  return result;
}

template <typename T>
inline MatrixBase<T> operator-(T const &lhs, MatrixBase<T> const &rhs) {
  MatrixBase<T> result(rhs.GetRow(), rhs.GetColumn());
  result -= rhs;
  return result;
}

template <typename T>
inline MatrixBase<T> operator*(T const &lhs, MatrixBase<T> const &rhs) {
  MatrixBase<T> copy = rhs.GetCopy();
  copy *= lhs;
  return copy;
}

template <typename T>
inline bool operator==(MatrixBase<T> const &lhs, MatrixBase<T> const &rhs) {
  if (lhs.GetRow() != rhs.GetRow() || lhs.GetColumn() != rhs.GetColumn()) {
    return false;
  }

  for (Uint i = 0; i < lhs.GetRow(); ++i) {
    for (Uint j = 0; j < lhs.GetColumn(); ++j) {
      if (lhs(i, j) != rhs(i, j)) {
        return false;
      }
    }
  }
}
} // namespace TerreateMath::Core

template <typename T>
inline std::ostream &
operator<<(std::ostream &os, TerreateMath::Core::MatrixBase<T> const &matrix) {
  using namespace TerreateMath::Defines;
  Uint digit = matrix.AcquireMaxDigit();
  digit = digit > 16 ? 16 : digit;
  for (Uint i = 0; i < matrix.GetRow(); ++i) {
    os << "| ";
    for (Uint j = 0; j < matrix.GetColumn(); ++j) {
      T value = matrix(i, j);
      if (Abs(value) < EPSILON) {
        os << std::setw(digit) << 0 << " ";
      } else {
        os << std::setw(digit)
           << TerreateMath::Core::MatrixTypeTraits<T>::ToString(value) << " ";
      }
    }
    os << "|" << std::endl;
  }
  return os;
}
#endif // __TC_MATH_CORE_HPP__
