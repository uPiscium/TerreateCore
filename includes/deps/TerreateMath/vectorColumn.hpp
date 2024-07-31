#ifndef __TC_MATH_VECTOR_COLUMN_HPP__
#define __TC_MATH_VECTOR_COLUMN_HPP__

#include "core.hpp"
#include "defines.hpp"

namespace TerreateMath::Vector {
using namespace TerreateMath::Defines;
using namespace TerreateMath::Core;

template <typename T> class ColumnVectorBase : public MatrixBase<T> {
public:
  ColumnVectorBase() : MatrixBase<T>() {}
  ColumnVectorBase(Uint const &comps) : MatrixBase<T>(comps, 1) {}
  ColumnVectorBase(Uint const &comps, T const *array)
      : MatrixBase<T>(comps, 1, array) {}
  ColumnVectorBase(Uint const &comps, T const &value)
      : MatrixBase<T>(comps, 1, value) {}
  ColumnVectorBase(Vec<T> const &value)
      : MatrixBase<T>(value.size(), 1, value) {}
  ColumnVectorBase(ColumnVectorBase<T> const &other) : MatrixBase<T>(other) {}
  ColumnVectorBase(MatrixBase<T> const &other) : MatrixBase<T>(other) {}
  ColumnVectorBase(ColumnVectorBase<T> &&other) noexcept
      : MatrixBase<T>(std::move(other)) {}
  template <typename U>
  ColumnVectorBase(Uint const &comps, U const *array)
      : MatrixBase<T>(comps, 1, array) {}
  template <typename U>
  ColumnVectorBase(Uint const &comps, U const &value)
      : MatrixBase<T>(comps, 1, value) {}
  template <typename U>
  ColumnVectorBase(Uint const &comps, Vec<U> const &value)
      : MatrixBase<T>(comps, 1, value) {}
  template <typename U>
  ColumnVectorBase(Vec<U> const &value)
      : MatrixBase<T>(value.size(), 1, value) {}
  template <typename U>
  ColumnVectorBase(ColumnVectorBase<U> const &other) : MatrixBase<T>(other) {}
  template <typename U>
  ColumnVectorBase(MatrixBase<U> const &other) : MatrixBase<T>(other) {}

  Uint GetComps() const { return this->GetRow(); }

  T AcquireLength() const;
  T AcquireLengthSquared() const;
  T AcquireNormalized() const;

  void Normalize();

  ColumnVectorBase<T> &operator=(T const &value);
  ColumnVectorBase<T> &operator=(Vec<T> const &value);
  ColumnVectorBase<T> &operator=(ColumnVectorBase<T> const &other);
  ColumnVectorBase<T> &operator=(ColumnVectorBase<T> &&other) noexcept;
  ColumnVectorBase<T> &operator=(MatrixBase<T> const &other);
  ColumnVectorBase<T> &operator=(MatrixBase<T> &&other);

  T &operator[](Uint const &index) { return (*this)(index, 0); }
  T const &operator[](Uint const &index) const { return (*this)(index, 0); }
};

template <typename T> class ColumnVector2D : public ColumnVectorBase<T> {
public:
  ColumnVector2D() : ColumnVectorBase<T>(2) {}
  ColumnVector2D(T const *array) : ColumnVectorBase<T>(2, array) {}
  ColumnVector2D(T const &x, T const &y)
      : ColumnVectorBase<T>(Vec<T>({x, y})) {}
  ColumnVector2D(Vec<T> const &value) : ColumnVectorBase<T>(value) {}
  ColumnVector2D(ColumnVector2D<T> const &other) : ColumnVectorBase<T>(other) {}
  ColumnVector2D(MatrixBase<T> const &other) : ColumnVectorBase<T>(other) {}
  ColumnVector2D(ColumnVector2D<T> &&other) noexcept
      : ColumnVectorBase<T>(std::move(other)) {}
  template <typename U>
  ColumnVector2D(U const *array) : ColumnVectorBase<T>(2, array) {}
  template <typename U>
  ColumnVector2D(U const &x, U const &y)
      : ColumnVectorBase<T>(Vec<T>({static_cast<T>(x), static_cast<T>(y)})) {}
  template <typename U>
  ColumnVector2D(Vec<U> const &value) : ColumnVectorBase<T>(value) {}
  template <typename U>
  ColumnVector2D(ColumnVector2D<U> const &other) : ColumnVectorBase<T>(other) {}
  template <typename U>
  ColumnVector2D(MatrixBase<U> const &other) : ColumnVectorBase<T>(other) {}

  ColumnVector2D<T> &operator=(T const &value);
  ColumnVector2D<T> &operator=(Vec<T> const &value);
  ColumnVector2D<T> &operator=(ColumnVector2D<T> const &other);
  ColumnVector2D<T> &operator=(ColumnVector2D<T> &&other) noexcept;
  ColumnVector2D<T> &operator=(MatrixBase<T> const &other);
  ColumnVector2D<T> &operator=(MatrixBase<T> &&other);
};

template <typename T> class ColumnVector3D : public ColumnVectorBase<T> {
public:
  ColumnVector3D() : ColumnVectorBase<T>(3) {}
  ColumnVector3D(T const *array) : ColumnVectorBase<T>(3, array) {}
  ColumnVector3D(T const &x, T const &y, T const &z)
      : ColumnVectorBase<T>(Vec<T>({x, y, z})) {}
  ColumnVector3D(Vec<T> const &value) : ColumnVectorBase<T>(value) {}
  ColumnVector3D(MatrixBase<T> const &other) : ColumnVectorBase<T>(other) {}
  ColumnVector3D(ColumnVector3D<T> const &other) : ColumnVectorBase<T>(other) {}
  ColumnVector3D(ColumnVector3D<T> &&other) noexcept
      : ColumnVectorBase<T>(std::move(other)) {}
  template <typename U>
  ColumnVector3D(U const *array) : ColumnVectorBase<T>(3, array) {}
  template <typename U>
  ColumnVector3D(U const &x, U const &y, U const &z)
      : ColumnVectorBase<T>(Vec<T>({static_cast<T>(x), static_cast<T>(y), static_cast<T>(z)})) {}
  template <typename U>
  ColumnVector3D(Vec<U> const &value) : ColumnVectorBase<T>(value) {}
  template <typename U>
  ColumnVector3D(ColumnVector3D<U> const &other) : ColumnVectorBase<T>(other) {}
  template <typename U>
  ColumnVector3D(MatrixBase<U> const &other) : ColumnVectorBase<T>(other) {}

  ColumnVector3D<T> &operator=(T const &value);
  ColumnVector3D<T> &operator=(Vec<T> const &value);
  ColumnVector3D<T> &operator=(ColumnVector3D<T> const &other);
  ColumnVector3D<T> &operator=(ColumnVector3D<T> &&other) noexcept;
  ColumnVector3D<T> &operator=(MatrixBase<T> const &other);
  ColumnVector3D<T> &operator=(MatrixBase<T> &&other);
};

template <typename T> class ColumnVector4D : public ColumnVectorBase<T> {
public:
  ColumnVector4D() : ColumnVectorBase<T>(4) {}
  ColumnVector4D(T const *array) : ColumnVectorBase<T>(4, array) {}
  ColumnVector4D(T const &x, T const &y, T const &z, T const &w)
      : ColumnVectorBase<T>(Vec<T>({x, y, z, w})) {}
  ColumnVector4D(Vec<T> const &value) : ColumnVectorBase<T>(value) {}
  ColumnVector4D(ColumnVector4D<T> const &other) : ColumnVectorBase<T>(other) {}
  ColumnVector4D(MatrixBase<T> const &other) : ColumnVectorBase<T>(other) {}
  ColumnVector4D(ColumnVector4D<T> &&other) noexcept
      : ColumnVectorBase<T>(std::move(other)) {}
  template <typename U>
  ColumnVector4D(U const *array) : ColumnVectorBase<T>(4, array) {}
  template <typename U>
  ColumnVector4D(U const &x, U const &y, U const &z, U const &w)
      : ColumnVectorBase<T>(Vec<T>({static_cast<T>(x), static_cast<T>(y), static_cast<T>(z), static_cast<T>(w)})) {}
  template <typename U>
  ColumnVector4D(Vec<U> const &value) : ColumnVectorBase<T>(value) {}
  template <typename U>
  ColumnVector4D(ColumnVector4D<U> const &other) : ColumnVectorBase<T>(other) {}
  template <typename U>
  ColumnVector4D(MatrixBase<U> const &other) : ColumnVectorBase<T>(other) {}

  ColumnVector4D<T> &operator=(T const &value);
  ColumnVector4D<T> &operator=(Vec<T> const &value);
  ColumnVector4D<T> &operator=(ColumnVector4D<T> const &other);
  ColumnVector4D<T> &operator=(ColumnVector4D<T> &&other) noexcept;
  ColumnVector4D<T> &operator=(MatrixBase<T> const &other);
  ColumnVector4D<T> &operator=(MatrixBase<T> &&other);
};

template <typename T>
ColumnVectorBase<T> Normalize(ColumnVectorBase<T> const &vector);
template <typename T>
ColumnVector3D<T> Cross(ColumnVectorBase<T> const &lhs,
                        ColumnVectorBase<T> const &rhs);

template <typename T>
ColumnVectorBase<T> operator+(ColumnVectorBase<T> const &lhs,
                              ColumnVectorBase<T> const &rhs) {
  return ColumnVectorBase<T>(static_cast<MatrixBase<T>>(lhs) +
                             static_cast<MatrixBase<T>>(rhs));
}
template <typename T>
ColumnVectorBase<T> operator-(ColumnVectorBase<T> const &lhs,
                              ColumnVectorBase<T> const &rhs) {
  return ColumnVectorBase<T>(static_cast<MatrixBase<T>>(lhs) -
                             static_cast<MatrixBase<T>>(rhs));
}
template <typename T>
T operator*(ColumnVectorBase<T> const &lhs, ColumnVectorBase<T> const &rhs) {
  return (static_cast<MatrixBase<T>>(Transpose(lhs)) *
          static_cast<MatrixBase<T>>(rhs))(0, 0);
}
template <typename T>
ColumnVectorBase<T> operator+(ColumnVectorBase<T> const &lhs, T const &rhs) {
  return ColumnVectorBase<T>(static_cast<MatrixBase<T>>(lhs) + rhs);
}
template <typename T>
ColumnVectorBase<T> operator-(ColumnVectorBase<T> const &lhs, T const &rhs) {
  return ColumnVectorBase<T>(static_cast<MatrixBase<T>>(lhs) - rhs);
}
template <typename T>
ColumnVectorBase<T> operator*(ColumnVectorBase<T> const &lhs, T const &rhs) {
  return ColumnVectorBase<T>(static_cast<MatrixBase<T>>(lhs) * rhs);
}
template <typename T>
ColumnVectorBase<T> operator/(ColumnVectorBase<T> const &lhs, T const &rhs) {
  return ColumnVectorBase<T>(static_cast<MatrixBase<T>>(lhs) / rhs);
}
template <typename T>
ColumnVectorBase<T> operator+(T const &lhs, ColumnVectorBase<T> const &rhs) {
  return ColumnVectorBase<T>(lhs + static_cast<MatrixBase<T>>(rhs));
}
template <typename T>
ColumnVectorBase<T> operator-(T const &lhs, ColumnVectorBase<T> const &rhs) {
  return ColumnVectorBase<T>(lhs - static_cast<MatrixBase<T>>(rhs));
}
template <typename T>
ColumnVectorBase<T> operator*(T const &lhs, ColumnVectorBase<T> const &rhs) {
  return ColumnVectorBase<T>(lhs * static_cast<MatrixBase<T>>(rhs));
}

template <typename T>
ColumnVector2D<T> Normalize(ColumnVector2D<T> const &vector) {
  return ColumnVector2D<T>(Normalize(static_cast<ColumnVectorBase<T>>(vector)));
}
template <typename T>
ColumnVector3D<T> Normalize(ColumnVector3D<T> const &vector) {
  return ColumnVector3D<T>(Normalize(static_cast<ColumnVectorBase<T>>(vector)));
}
template <typename T>
ColumnVector4D<T> Normalize(ColumnVector4D<T> const &vector) {
  return ColumnVector4D<T>(Normalize(static_cast<ColumnVectorBase<T>>(vector)));
}

template <typename T>
ColumnVector3D<T> Cross(ColumnVector2D<T> const &lhs,
                        ColumnVector2D<T> const &rhs) {
  return Cross(static_cast<ColumnVectorBase<T>>(lhs),
               static_cast<ColumnVectorBase<T>>(rhs));
}
template <typename T>
ColumnVector3D<T> Cross(ColumnVector3D<T> const &lhs,
                        ColumnVector3D<T> const &rhs) {
  return Cross(static_cast<ColumnVectorBase<T>>(lhs),
               static_cast<ColumnVectorBase<T>>(rhs));
}

template <typename T>
ColumnVector2D<T> operator+(ColumnVector2D<T> const &lhs,
                            ColumnVector2D<T> const &rhs) {
  return ColumnVector2D<T>(static_cast<MatrixBase<T>>(lhs) +
                           static_cast<MatrixBase<T>>(rhs));
}
template <typename T>
ColumnVector2D<T> operator-(ColumnVector2D<T> const &lhs,
                            ColumnVector2D<T> const &rhs) {
  return ColumnVector2D<T>(static_cast<MatrixBase<T>>(lhs) -
                           static_cast<MatrixBase<T>>(rhs));
}
template <typename T>
T operator*(ColumnVector2D<T> const &lhs, ColumnVector2D<T> const &rhs) {
  return (static_cast<MatrixBase<T>>(Transpose(lhs)) *
          static_cast<MatrixBase<T>>(rhs))(0, 0);
}
template <typename T>
ColumnVector2D<T> operator+(ColumnVector2D<T> const &lhs, T const &rhs) {
  return ColumnVector2D<T>(static_cast<MatrixBase<T>>(lhs) + rhs);
}
template <typename T>
ColumnVector2D<T> operator-(ColumnVector2D<T> const &lhs, T const &rhs) {
  return ColumnVector2D<T>(static_cast<MatrixBase<T>>(lhs) - rhs);
}
template <typename T>
ColumnVector2D<T> operator*(ColumnVector2D<T> const &lhs, T const &rhs) {
  return ColumnVector2D<T>(static_cast<MatrixBase<T>>(lhs) * rhs);
}
template <typename T>
ColumnVector2D<T> operator/(ColumnVector2D<T> const &lhs, T const &rhs) {
  return ColumnVector2D<T>(static_cast<MatrixBase<T>>(lhs) / rhs);
}
template <typename T>
ColumnVector2D<T> operator+(T const &lhs, ColumnVector2D<T> const &rhs) {
  return ColumnVector2D<T>(lhs + static_cast<MatrixBase<T>>(rhs));
}
template <typename T>
ColumnVector2D<T> operator-(T const &lhs, ColumnVector2D<T> const &rhs) {
  return ColumnVector2D<T>(lhs - static_cast<MatrixBase<T>>(rhs));
}
template <typename T>
ColumnVector2D<T> operator*(T const &lhs, ColumnVector2D<T> const &rhs) {
  return ColumnVector2D<T>(lhs * static_cast<MatrixBase<T>>(rhs));
}

template <typename T>
ColumnVector3D<T> operator+(ColumnVector3D<T> const &lhs,
                            ColumnVector3D<T> const &rhs) {
  return ColumnVector3D<T>(static_cast<MatrixBase<T>>(lhs) +
                           static_cast<MatrixBase<T>>(rhs));
}
template <typename T>
ColumnVector3D<T> operator-(ColumnVector3D<T> const &lhs,
                            ColumnVector3D<T> const &rhs) {
  return ColumnVector3D<T>(static_cast<MatrixBase<T>>(lhs) -
                           static_cast<MatrixBase<T>>(rhs));
}
template <typename T>
T operator*(ColumnVector3D<T> const &lhs, ColumnVector3D<T> const &rhs) {
  return (static_cast<MatrixBase<T>>(Transpose(lhs)) *
          static_cast<MatrixBase<T>>(rhs))(0, 0);
}
template <typename T>
ColumnVector3D<T> operator+(ColumnVector3D<T> const &lhs, T const &rhs) {
  return ColumnVector3D<T>(static_cast<MatrixBase<T>>(lhs) + rhs);
}
template <typename T>
ColumnVector3D<T> operator-(ColumnVector3D<T> const &lhs, T const &rhs) {
  return ColumnVector3D<T>(static_cast<MatrixBase<T>>(lhs) - rhs);
}
template <typename T>
ColumnVector3D<T> operator*(ColumnVector3D<T> const &lhs, T const &rhs) {
  return ColumnVector3D<T>(static_cast<MatrixBase<T>>(lhs) * rhs);
}
template <typename T>
ColumnVector3D<T> operator/(ColumnVector3D<T> const &lhs, T const &rhs) {
  return ColumnVector3D<T>(static_cast<MatrixBase<T>>(lhs) / rhs);
}
template <typename T>
ColumnVector3D<T> operator+(T const &lhs, ColumnVector3D<T> const &rhs) {
  return ColumnVector3D<T>(lhs + static_cast<MatrixBase<T>>(rhs));
}
template <typename T>
ColumnVector3D<T> operator-(T const &lhs, ColumnVector3D<T> const &rhs) {
  return ColumnVector3D<T>(lhs - static_cast<MatrixBase<T>>(rhs));
}
template <typename T>
ColumnVector3D<T> operator*(T const &lhs, ColumnVector3D<T> const &rhs) {
  return ColumnVector3D<T>(lhs * static_cast<MatrixBase<T>>(rhs));
}

template <typename T>
ColumnVector4D<T> operator+(ColumnVector4D<T> const &lhs,
                            ColumnVector4D<T> const &rhs) {
  return ColumnVector4D<T>(static_cast<MatrixBase<T>>(lhs) +
                           static_cast<MatrixBase<T>>(rhs));
}
template <typename T>
ColumnVector4D<T> operator-(ColumnVector4D<T> const &lhs,
                            ColumnVector4D<T> const &rhs) {
  return ColumnVector4D<T>(static_cast<MatrixBase<T>>(lhs) -
                           static_cast<MatrixBase<T>>(rhs));
}
template <typename T>
T operator*(ColumnVector4D<T> const &lhs, ColumnVector4D<T> const &rhs) {
  return (static_cast<MatrixBase<T>>(Transpose(lhs)) *
          static_cast<MatrixBase<T>>(rhs))(0, 0);
}
template <typename T>
ColumnVector4D<T> operator+(ColumnVector4D<T> const &lhs, T const &rhs) {
  return ColumnVector4D<T>(static_cast<MatrixBase<T>>(lhs) + rhs);
}
template <typename T>
ColumnVector4D<T> operator-(ColumnVector4D<T> const &lhs, T const &rhs) {
  return ColumnVector4D<T>(static_cast<MatrixBase<T>>(lhs) - rhs);
}
template <typename T>
ColumnVector4D<T> operator*(ColumnVector4D<T> const &lhs, T const &rhs) {
  return ColumnVector4D<T>(static_cast<MatrixBase<T>>(lhs) * rhs);
}
template <typename T>
ColumnVector4D<T> operator/(ColumnVector4D<T> const &lhs, T const &rhs) {
  return ColumnVector4D<T>(static_cast<MatrixBase<T>>(lhs) / rhs);
}
template <typename T>
ColumnVector4D<T> operator+(T const &lhs, ColumnVector4D<T> const &rhs) {
  return ColumnVector4D<T>(lhs + static_cast<MatrixBase<T>>(rhs));
}
template <typename T>
ColumnVector4D<T> operator-(T const &lhs, ColumnVector4D<T> const &rhs) {
  return ColumnVector4D<T>(lhs - static_cast<MatrixBase<T>>(rhs));
}
template <typename T>
ColumnVector4D<T> operator*(T const &lhs, ColumnVector4D<T> const &rhs) {
  return ColumnVector4D<T>(lhs * static_cast<MatrixBase<T>>(rhs));
}
} // namespace TerreateMath::Vector

// Implementation
namespace TerreateMath::Vector {
template <typename T> T ColumnVectorBase<T>::AcquireLength() const {
  T sum = 0;
  for (Uint i = 0; i < this->GetRow(); i++) {
    sum += (*this)(i, 0) * (*this)(i, 0);
  }
  return std::sqrt(sum);
}

template <typename T> T ColumnVectorBase<T>::AcquireLengthSquared() const {
  T sum = 0;
  for (Uint i = 0; i < this->GetRow(); i++) {
    sum += (*this)(i, 0) * (*this)(i, 0);
  }
  return sum;
}

template <typename T> T ColumnVectorBase<T>::AcquireNormalized() const {
  T length = AcquireLength();
  if (length == 0) {
    return 0;
  }
  ColumnVectorBase<T> result = this->GetCopy();
  return result / length;
}

template <typename T> void ColumnVectorBase<T>::Normalize() {
  T length = AcquireLength();
  for (Uint i = 0; i < this->GetRow(); i++) {
    (*this)(i, 0) /= length;
  }
}

template <typename T>
ColumnVectorBase<T> &ColumnVectorBase<T>::operator=(T const &value) {
  MatrixBase<T>::operator=(value);
  return *this;
}

template <typename T>
ColumnVectorBase<T> &ColumnVectorBase<T>::operator=(Vec<T> const &value) {
  MatrixBase<T>::operator=(value);
  return *this;
}

template <typename T>
ColumnVectorBase<T> &
ColumnVectorBase<T>::operator=(ColumnVectorBase<T> const &other) {
  MatrixBase<T>::operator=(other);
  return *this;
}

template <typename T>
ColumnVectorBase<T> &
ColumnVectorBase<T>::operator=(ColumnVectorBase<T> &&other) noexcept {
  MatrixBase<T>::operator=(std::move(other));
  return *this;
}

template <typename T>
ColumnVectorBase<T> &
ColumnVectorBase<T>::operator=(MatrixBase<T> const &other) {
  MatrixBase<T>::operator=(other);
  return *this;
}

template <typename T>
ColumnVectorBase<T> &ColumnVectorBase<T>::operator=(MatrixBase<T> &&other) {
  MatrixBase<T>::operator=(std::move(other));
  return *this;
}

template <typename T>
ColumnVector2D<T> &ColumnVector2D<T>::operator=(T const &value) {
  ColumnVectorBase<T>::operator=(value);
  return *this;
}

template <typename T>
ColumnVector2D<T> &ColumnVector2D<T>::operator=(Vec<T> const &value) {
  ColumnVectorBase<T>::operator=(value);
  return *this;
}

template <typename T>
ColumnVector2D<T> &
ColumnVector2D<T>::operator=(ColumnVector2D<T> const &other) {
  ColumnVectorBase<T>::operator=(other);
  return *this;
}

template <typename T>
ColumnVector2D<T> &
ColumnVector2D<T>::operator=(ColumnVector2D<T> &&other) noexcept {
  ColumnVectorBase<T>::operator=(std::move(other));
  return *this;
}

template <typename T>
ColumnVector2D<T> &ColumnVector2D<T>::operator=(MatrixBase<T> const &other) {
  ColumnVectorBase<T>::operator=(other);
  return *this;
}

template <typename T>
ColumnVector2D<T> &ColumnVector2D<T>::operator=(MatrixBase<T> &&other) {
  ColumnVectorBase<T>::operator=(std::move(other));
  return *this;
}

template <typename T>
ColumnVector3D<T> &ColumnVector3D<T>::operator=(T const &value) {
  ColumnVectorBase<T>::operator=(value);
  return *this;
}

template <typename T>
ColumnVector3D<T> &ColumnVector3D<T>::operator=(Vec<T> const &value) {
  ColumnVectorBase<T>::operator=(value);
  return *this;
}

template <typename T>
ColumnVector3D<T> &
ColumnVector3D<T>::operator=(ColumnVector3D<T> const &other) {
  ColumnVectorBase<T>::operator=(other);
  return *this;
}

template <typename T>
ColumnVector3D<T> &
ColumnVector3D<T>::operator=(ColumnVector3D<T> &&other) noexcept {
  ColumnVectorBase<T>::operator=(std::move(other));
  return *this;
}

template <typename T>
ColumnVector3D<T> &ColumnVector3D<T>::operator=(MatrixBase<T> const &other) {
  ColumnVectorBase<T>::operator=(other);
  return *this;
}

template <typename T>
ColumnVector3D<T> &ColumnVector3D<T>::operator=(MatrixBase<T> &&other) {
  ColumnVectorBase<T>::operator=(std::move(other));
  return *this;
}

template <typename T>
ColumnVector4D<T> &ColumnVector4D<T>::operator=(T const &value) {
  ColumnVectorBase<T>::operator=(value);
  return *this;
}

template <typename T>
ColumnVector4D<T> &ColumnVector4D<T>::operator=(Vec<T> const &value) {
  ColumnVectorBase<T>::operator=(value);
  return *this;
}

template <typename T>
ColumnVector4D<T> &
ColumnVector4D<T>::operator=(ColumnVector4D<T> const &other) {
  ColumnVectorBase<T>::operator=(other);
  return *this;
}

template <typename T>
ColumnVector4D<T> &
ColumnVector4D<T>::operator=(ColumnVector4D<T> &&other) noexcept {
  ColumnVectorBase<T>::operator=(std::move(other));
  return *this;
}

template <typename T>
ColumnVector4D<T> &ColumnVector4D<T>::operator=(MatrixBase<T> const &other) {
  ColumnVectorBase<T>::operator=(other);
  return *this;
}

template <typename T>
ColumnVector4D<T> &ColumnVector4D<T>::operator=(MatrixBase<T> &&other) {
  ColumnVectorBase<T>::operator=(std::move(other));
  return *this;
}

template <typename T>
ColumnVectorBase<T> Normalize(ColumnVectorBase<T> const &vector) {
  T length = vector.AcquireLength();
  if (length == 0) {
    return vector;
  }
  ColumnVectorBase<T> result = vector.GetCopy();
  return result / length;
}

template <typename T>
ColumnVector3D<T> Cross(ColumnVectorBase<T> const &lhs,
                        ColumnVectorBase<T> const &rhs) {
  Uint lComps = lhs.GetComps();
  Uint rComps = rhs.GetComps();

  if (lComps > 3 || rComps > 3) {
    std::runtime_error("Incompatible vector size.");
  }

  ColumnVector3D<T> v1;
  ColumnVector3D<T> v2;
  memcpy(v1.GetArray(), lhs.GetArray(), sizeof(T) * lhs.GetSize());
  memcpy(v2.GetArray(), rhs.GetArray(), sizeof(T) * rhs.GetSize());

  MatrixBase<T> result(3, 1, 0);
  result(0, 0) = v1(1, 0) * v2(2, 0) - v1(2, 0) * v2(1, 0);
  result(1, 0) = v1(2, 0) * v2(0, 0) - v1(0, 0) * v2(2, 0);
  result(2, 0) = v1(0, 0) * v2(1, 0) - v1(1, 0) * v2(0, 0);
  return result;
}
} // namespace TerreateMath::Vector
#endif // __TC_MATH_VECTOR_COLUMN_HPP__
