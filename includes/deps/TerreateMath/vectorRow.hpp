#ifndef __TC_MATH_VECTOR_ROW_HPP__
#define __TC_MATH_VECTOR_ROW_HPP__

#include "core.hpp"
#include "defines.hpp"
#include <stdexcept>

namespace TerreateMath::Vector {
using namespace TerreateMath::Defines;
using namespace TerreateMath::Core;

template <typename T> class RowVectorBase : public MatrixBase<T> {
public:
  RowVectorBase() : MatrixBase<T>() {}
  RowVectorBase(Uint const &comps) : MatrixBase<T>(1, comps) {}
  RowVectorBase(Uint const &comps, T const *array)
      : MatrixBase<T>(1, comps, array) {}
  RowVectorBase(Uint const &comps, T const &value)
      : MatrixBase<T>(1, comps, value) {}
  RowVectorBase(Vec<T> const &value) : MatrixBase<T>(1, value.size(), value) {}
  RowVectorBase(RowVectorBase<T> const &other) : MatrixBase<T>(other) {}
  RowVectorBase(MatrixBase<T> const &other) : MatrixBase<T>(other) {}
  RowVectorBase(RowVectorBase<T> &&other) noexcept
      : MatrixBase<T>(std::move(other)) {}
  template <typename U>
  RowVectorBase(Uint const &comps, U const *array)
      : MatrixBase<T>(1, comps, array) {}
  template <typename U>
  RowVectorBase(Uint const &comps, U const &value)
      : MatrixBase<T>(1, comps, value) {}
  template <typename U>
  RowVectorBase(Uint const &comps, Vec<U> const &value)
      : MatrixBase<T>(1, comps, value) {}
  template <typename U>
  RowVectorBase(Vec<U> const &value) : MatrixBase<T>(1, value.size(), value) {}
  template <typename U>
  RowVectorBase(RowVectorBase<U> const &other) : MatrixBase<T>(other) {}
  template <typename U>
  RowVectorBase(MatrixBase<U> const &other) : MatrixBase<T>(other) {}

  Uint GetComps() const { return this->GetColumn(); }

  T AcquireLength() const;
  T AcquireLengthSquared() const;
  T AcquireNormalized() const;

  void Normalize();

  RowVectorBase<T> &operator=(T const &value);
  RowVectorBase<T> &operator=(Vec<T> const &value);
  RowVectorBase<T> &operator=(RowVectorBase<T> const &other);
  RowVectorBase<T> &operator=(RowVectorBase<T> &&other) noexcept;
  RowVectorBase<T> &operator=(MatrixBase<T> const &other);
  RowVectorBase<T> &operator=(MatrixBase<T> &&other);

  T &operator[](Uint const &index) { return (*this)(0, index); }
  T const &operator[](Uint const &index) const { return (*this)(0, index); }
};

template <typename T> class RowVector2D : public RowVectorBase<T> {
public:
  RowVector2D() : RowVectorBase<T>(2) {}
  RowVector2D(T const *array) : RowVectorBase<T>(2, array) {}
  RowVector2D(T const &x, T const &y) : RowVectorBase<T>(Vec<T>({x, y})) {}
  RowVector2D(Vec<T> const &value) : RowVectorBase<T>(value) {}
  RowVector2D(RowVector2D<T> const &other) : RowVectorBase<T>(other) {}
  RowVector2D(MatrixBase<T> const &other) : RowVectorBase<T>(other) {}
  RowVector2D(RowVector2D<T> &&other) noexcept
      : RowVectorBase<T>(std::move(other)) {}
  template <typename U>
  RowVector2D(U const *array) : RowVectorBase<T>(2, array) {}
  template <typename U>
  RowVector2D(U const &x, U const &y) : RowVectorBase<T>(Vec<T>({static_cast<T>(x), static_cast<T>(y)})) {}
  template <typename U>
  RowVector2D(Vec<U> const &value) : RowVectorBase<T>(value) {}
  template <typename U>
  RowVector2D(RowVector2D<U> const &other) : RowVectorBase<T>(other) {}
  template <typename U>
  RowVector2D(MatrixBase<U> const &other) : RowVectorBase<T>(other) {}

  RowVector2D<T> &operator=(T const &value);
  RowVector2D<T> &operator=(Vec<T> const &value);
  RowVector2D<T> &operator=(RowVector2D<T> const &other);
  RowVector2D<T> &operator=(RowVector2D<T> &&other) noexcept;
  RowVector2D<T> &operator=(MatrixBase<T> const &other);
  RowVector2D<T> &operator=(MatrixBase<T> &&other);
};

template <typename T> class RowVector3D : public RowVectorBase<T> {
public:
  RowVector3D() : RowVectorBase<T>(3) {}
  RowVector3D(T const *array) : RowVectorBase<T>(3, array) {}
  RowVector3D(T const &x, T const &y, T const &z)
      : RowVectorBase<T>(Vec<T>({x, y, z})) {}
  RowVector3D(Vec<T> const &value) : RowVectorBase<T>(value) {}
  RowVector3D(RowVector3D<T> const &other) : RowVectorBase<T>(other) {}
  RowVector3D(MatrixBase<T> const &other) : RowVectorBase<T>(other) {}
  RowVector3D(RowVector3D<T> &&other) noexcept
      : RowVectorBase<T>(std::move(other)) {}
  RowVector3D(RowVector2D<T> const &other, T const &z)
      : RowVectorBase<T>(Vec<T>({other[0], other[1], z})) {}
  template <typename U>
  RowVector3D(U const *array) : RowVectorBase<T>(3, array) {}
  template <typename U>
  RowVector3D(U const &x, U const &y, U const &z)
      : RowVectorBase<T>(Vec<T>({static_cast<T>(x), static_cast<T>(y), static_cast<T>(z)})) {}
  template <typename U>
  RowVector3D(Vec<U> const &value) : RowVectorBase<T>(value) {}
  template <typename U>
  RowVector3D(RowVector3D<U> const &other) : RowVectorBase<T>(other) {}
  template <typename U>
  RowVector3D(MatrixBase<U> const &other) : RowVectorBase<T>(other) {}
  template <typename U>
  RowVector3D(RowVector2D<U> const &other, U const &z)
      : RowVectorBase<T>(Vec<T>({other[0], other[1], z})) {}

  RowVector3D<T> &operator=(T const &value);
  RowVector3D<T> &operator=(Vec<T> const &value);
  RowVector3D<T> &operator=(RowVector3D<T> const &other);
  RowVector3D<T> &operator=(RowVector3D<T> &&other) noexcept;
  RowVector3D<T> &operator=(MatrixBase<T> const &other);
  RowVector3D<T> &operator=(MatrixBase<T> &&other);
};

template <typename T> class RowVector4D : public RowVectorBase<T> {
public:
  RowVector4D() : RowVectorBase<T>(4) {}
  RowVector4D(T const *array) : RowVectorBase<T>(4, array) {}
  RowVector4D(T const &x, T const &y, T const &z, T const &w)
      : RowVectorBase<T>(Vec<T>({x, y, z, w})) {}
  RowVector4D(Vec<T> const &value) : RowVectorBase<T>(value) {}
  RowVector4D(RowVector4D<T> const &other) : RowVectorBase<T>(other) {}
  RowVector4D(MatrixBase<T> const &other) : RowVectorBase<T>(other) {}
  RowVector4D(RowVector4D<T> &&other) noexcept
      : RowVectorBase<T>(std::move(other)) {}
  RowVector4D(RowVector3D<T> const &other, T const &w)
      : RowVectorBase<T>(Vec<T>({other[0], other[1], other[2], w})) {}
  template <typename U>
  RowVector4D(U const *array) : RowVectorBase<T>(4, array) {}
  template <typename U>
  RowVector4D(U const &x, U const &y, U const &z, U const &w)
      : RowVectorBase<T>(Vec<T>({static_cast<T>(x), static_cast<T>(y), static_cast<T>(z), static_cast<T>(w)})) {}
  template <typename U>
  RowVector4D(Vec<U> const &value) : RowVectorBase<T>(value) {}
  template <typename U>
  RowVector4D(RowVector4D<U> const &other) : RowVectorBase<T>(other) {}
  template <typename U>
  RowVector4D(MatrixBase<U> const &other) : RowVectorBase<T>(other) {}
  template <typename U>
  RowVector4D(RowVector3D<U> const &other, U const &w)
      : RowVectorBase<T>(Vec<T>({other[0], other[1], other[2], w})) {}

  RowVector4D<T> &operator=(T const &value);
  RowVector4D<T> &operator=(Vec<T> const &value);
  RowVector4D<T> &operator=(RowVector4D<T> const &other);
  RowVector4D<T> &operator=(RowVector4D<T> &&other) noexcept;
  RowVector4D<T> &operator=(MatrixBase<T> const &other);
  RowVector4D<T> &operator=(MatrixBase<T> &&other);
};

template <typename T>
RowVectorBase<T> Normalize(RowVectorBase<T> const &vector);
template <typename T>
RowVector3D<T> Cross(RowVectorBase<T> const &lhs, RowVectorBase<T> const &rhs);

template <typename T>
RowVectorBase<T> operator+(RowVectorBase<T> const &lhs,
                           RowVectorBase<T> const &rhs) {
  return RowVectorBase<T>(static_cast<MatrixBase<T>>(lhs) +
                          static_cast<MatrixBase<T>>(rhs));
}
template <typename T>
RowVectorBase<T> operator-(RowVectorBase<T> const &lhs,
                           RowVectorBase<T> const &rhs) {
  return RowVectorBase<T>(static_cast<MatrixBase<T>>(lhs) -
                          static_cast<MatrixBase<T>>(rhs));
}
template <typename T>
T operator*(RowVectorBase<T> const &lhs, RowVectorBase<T> const &rhs) {
  return (static_cast<MatrixBase<T>>(lhs) *
          static_cast<MatrixBase<T>>(Transpose(rhs)))(0, 0);
}
template <typename T>
RowVectorBase<T> operator+(RowVectorBase<T> const &lhs, T const &rhs) {
  return RowVectorBase<T>(static_cast<MatrixBase<T>>(lhs) + rhs);
}
template <typename T>
RowVectorBase<T> operator-(RowVectorBase<T> const &lhs, T const &rhs) {
  return RowVectorBase<T>(static_cast<MatrixBase<T>>(lhs) - rhs);
}
template <typename T>
RowVectorBase<T> operator*(RowVectorBase<T> const &lhs, T const &rhs) {
  return RowVectorBase<T>(static_cast<MatrixBase<T>>(lhs) * rhs);
}
template <typename T>
RowVectorBase<T> operator/(RowVectorBase<T> const &lhs, T const &rhs) {
  return RowVectorBase<T>(static_cast<MatrixBase<T>>(lhs) / rhs);
}
template <typename T>
RowVectorBase<T> operator+(T const &lhs, RowVectorBase<T> const &rhs) {
  return RowVectorBase<T>(lhs + static_cast<MatrixBase<T>>(rhs));
}
template <typename T>
RowVectorBase<T> operator-(T const &lhs, RowVectorBase<T> const &rhs) {
  return RowVectorBase<T>(lhs - static_cast<MatrixBase<T>>(rhs));
}
template <typename T>
RowVectorBase<T> operator*(T const &lhs, RowVectorBase<T> const &rhs) {
  return RowVectorBase<T>(lhs * static_cast<MatrixBase<T>>(rhs));
}

template <typename T> RowVector2D<T> Normalize(RowVector2D<T> const &vector) {
  return RowVector2D<T>(Normalize(static_cast<RowVectorBase<T>>(vector)));
}
template <typename T> RowVector3D<T> Normalize(RowVector3D<T> const &vector) {
  return RowVector3D<T>(Normalize(static_cast<RowVectorBase<T>>(vector)));
}
template <typename T> RowVector4D<T> Normalize(RowVector4D<T> const &vector) {
  return RowVector4D<T>(Normalize(static_cast<RowVectorBase<T>>(vector)));
}
template <typename T>
RowVector3D<T> Cross(RowVector2D<T> const &lhs, RowVector2D<T> const &rhs) {
  return Cross(static_cast<RowVectorBase<T>>(lhs),
               static_cast<RowVectorBase<T>>(rhs));
}
template <typename T>
RowVector3D<T> Cross(RowVector3D<T> const &lhs, RowVector3D<T> const &rhs) {
  return Cross(static_cast<RowVectorBase<T>>(lhs),
               static_cast<RowVectorBase<T>>(rhs));
}

template <typename T>
RowVector2D<T> operator+(RowVector2D<T> const &lhs, RowVector2D<T> const &rhs) {
  return RowVector2D<T>(static_cast<MatrixBase<T>>(lhs) +
                        static_cast<MatrixBase<T>>(rhs));
}
template <typename T>
RowVector2D<T> operator-(RowVector2D<T> const &lhs, RowVector2D<T> const &rhs) {
  return RowVector2D<T>(static_cast<MatrixBase<T>>(lhs) -
                        static_cast<MatrixBase<T>>(rhs));
}
template <typename T>
T operator*(RowVector2D<T> const &lhs, RowVector2D<T> const &rhs) {
  return (static_cast<MatrixBase<T>>(lhs) *
          static_cast<MatrixBase<T>>(Transpose(rhs)))(0, 0);
}
template <typename T>
RowVector2D<T> operator+(RowVector2D<T> const &lhs, T const &rhs) {
  return RowVector2D<T>(static_cast<MatrixBase<T>>(lhs) + rhs);
}
template <typename T>
RowVector2D<T> operator-(RowVector2D<T> const &lhs, T const &rhs) {
  return RowVector2D<T>(static_cast<MatrixBase<T>>(lhs) - rhs);
}
template <typename T>
RowVector2D<T> operator*(RowVector2D<T> const &lhs, T const &rhs) {
  return RowVector2D<T>(static_cast<MatrixBase<T>>(lhs) * rhs);
}
template <typename T>
RowVector2D<T> operator/(RowVector2D<T> const &lhs, T const &rhs) {
  return RowVector2D<T>(static_cast<MatrixBase<T>>(lhs) / rhs);
}
template <typename T>
RowVector2D<T> operator+(T const &lhs, RowVector2D<T> const &rhs) {
  return RowVector2D<T>(lhs + static_cast<MatrixBase<T>>(rhs));
}
template <typename T>
RowVector2D<T> operator-(T const &lhs, RowVector2D<T> const &rhs) {
  return RowVector2D<T>(lhs - static_cast<MatrixBase<T>>(rhs));
}
template <typename T>
RowVector2D<T> operator*(T const &lhs, RowVector2D<T> const &rhs) {
  return RowVector2D<T>(lhs * static_cast<MatrixBase<T>>(rhs));
}

template <typename T>
RowVector3D<T> operator+(RowVector3D<T> const &lhs, RowVector3D<T> const &rhs) {
  return RowVector3D<T>(static_cast<MatrixBase<T>>(lhs) +
                        static_cast<MatrixBase<T>>(rhs));
}
template <typename T>
RowVector3D<T> operator-(RowVector3D<T> const &lhs, RowVector3D<T> const &rhs) {
  return RowVector3D<T>(static_cast<MatrixBase<T>>(lhs) -
                        static_cast<MatrixBase<T>>(rhs));
}
template <typename T>
T operator*(RowVector3D<T> const &lhs, RowVector3D<T> const &rhs) {
  return (static_cast<MatrixBase<T>>(lhs) *
          static_cast<MatrixBase<T>>(Transpose(rhs)))(0, 0);
}
template <typename T>
RowVector3D<T> operator+(RowVector3D<T> const &lhs, T const &rhs) {
  return RowVector3D<T>(static_cast<MatrixBase<T>>(lhs) + rhs);
}
template <typename T>
RowVector3D<T> operator-(RowVector3D<T> const &lhs, T const &rhs) {
  return RowVector3D<T>(static_cast<MatrixBase<T>>(lhs) - rhs);
}
template <typename T>
RowVector3D<T> operator*(RowVector3D<T> const &lhs, T const &rhs) {
  return RowVector3D<T>(static_cast<MatrixBase<T>>(lhs) * rhs);
}
template <typename T>
RowVector3D<T> operator/(RowVector3D<T> const &lhs, T const &rhs) {
  return RowVector3D<T>(static_cast<MatrixBase<T>>(lhs) / rhs);
}
template <typename T>
RowVector3D<T> operator+(T const &lhs, RowVector3D<T> const &rhs) {
  return RowVector3D<T>(lhs + static_cast<MatrixBase<T>>(rhs));
}
template <typename T>
RowVector3D<T> operator-(T const &lhs, RowVector3D<T> const &rhs) {
  return RowVector3D<T>(lhs - static_cast<MatrixBase<T>>(rhs));
}
template <typename T>
RowVector3D<T> operator*(T const &lhs, RowVector3D<T> const &rhs) {
  return RowVector3D<T>(lhs * static_cast<MatrixBase<T>>(rhs));
}

template <typename T>
RowVector4D<T> operator+(RowVector4D<T> const &lhs, RowVector4D<T> const &rhs) {
  return RowVector4D<T>(static_cast<MatrixBase<T>>(lhs) +
                        static_cast<MatrixBase<T>>(rhs));
}
template <typename T>
RowVector4D<T> operator-(RowVector4D<T> const &lhs, RowVector4D<T> const &rhs) {
  return RowVector4D<T>(static_cast<MatrixBase<T>>(lhs) -
                        static_cast<MatrixBase<T>>(rhs));
}
template <typename T>
T operator*(RowVector4D<T> const &lhs, RowVector4D<T> const &rhs) {
  return (static_cast<MatrixBase<T>>(lhs) *
          static_cast<MatrixBase<T>>(Transpose(rhs)))(0, 0);
}
template <typename T>
RowVector4D<T> operator+(RowVector4D<T> const &lhs, T const &rhs) {
  return RowVector4D<T>(static_cast<MatrixBase<T>>(lhs) + rhs);
}
template <typename T>
RowVector4D<T> operator-(RowVector4D<T> const &lhs, T const &rhs) {
  return RowVector4D<T>(static_cast<MatrixBase<T>>(lhs) - rhs);
}
template <typename T>
RowVector4D<T> operator*(RowVector4D<T> const &lhs, T const &rhs) {
  return RowVector4D<T>(static_cast<MatrixBase<T>>(lhs) * rhs);
}
template <typename T>
RowVector4D<T> operator/(RowVector4D<T> const &lhs, T const &rhs) {
  return RowVector4D<T>(static_cast<MatrixBase<T>>(lhs) / rhs);
}
template <typename T>
RowVector4D<T> operator+(T const &lhs, RowVector4D<T> const &rhs) {
  return RowVector4D<T>(lhs + static_cast<MatrixBase<T>>(rhs));
}
template <typename T>
RowVector4D<T> operator-(T const &lhs, RowVector4D<T> const &rhs) {
  return RowVector4D<T>(lhs - static_cast<MatrixBase<T>>(rhs));
}
template <typename T>
RowVector4D<T> operator*(T const &lhs, RowVector4D<T> const &rhs) {
  return RowVector4D<T>(lhs * static_cast<MatrixBase<T>>(rhs));
}
} // namespace TerreateMath::Vector

// Implementation
namespace TerreateMath::Vector {
using namespace TerreateMath::Defines;

template <typename T> T RowVectorBase<T>::AcquireLength() const {
  T sum = 0;
  for (Uint i = 0; i < this->GetColumn(); i++) {
    sum += (*this)(0, i) * (*this)(0, i);
  }
  return std::sqrt(sum);
}

template <typename T> T RowVectorBase<T>::AcquireLengthSquared() const {
  T sum = 0;
  for (Uint i = 0; i < this->GetColumn(); i++) {
    sum += (*this)(0, i) * (*this)(0, i);
  }
  return sum;
}

template <typename T> T RowVectorBase<T>::AcquireNormalized() const {
  T length = AcquireLength();
  if (length == 0) {
    return 0;
  }
  RowVectorBase<T> result = this->GetCopy();
  return result / length;
}

template <typename T> void RowVectorBase<T>::Normalize() {
  T length = AcquireLength();
  for (Uint i = 0; i < this->GetColumn(); i++) {
    (*this)(0, i) /= length;
  }
}

template <typename T>
RowVectorBase<T> &RowVectorBase<T>::operator=(T const &value) {
  MatrixBase<T>::operator=(value);
  return *this;
}

template <typename T>
RowVectorBase<T> &RowVectorBase<T>::operator=(Vec<T> const &value) {
  MatrixBase<T>::operator=(value);
  return *this;
}

template <typename T>
RowVectorBase<T> &RowVectorBase<T>::operator=(RowVectorBase<T> const &other) {
  MatrixBase<T>::operator=(other);
  return *this;
}

template <typename T>
RowVectorBase<T> &
RowVectorBase<T>::operator=(RowVectorBase<T> &&other) noexcept {
  MatrixBase<T>::operator=(std::move(other));
  return *this;
}

template <typename T>
RowVectorBase<T> &RowVectorBase<T>::operator=(MatrixBase<T> const &other) {
  MatrixBase<T>::operator=(other);
  return *this;
}

template <typename T>
RowVectorBase<T> &RowVectorBase<T>::operator=(MatrixBase<T> &&other) {
  MatrixBase<T>::operator=(std::move(other));
  return *this;
}

template <typename T>
RowVector2D<T> &RowVector2D<T>::operator=(T const &value) {
  RowVectorBase<T>::operator=(value);
  return *this;
}

template <typename T>
RowVector2D<T> &RowVector2D<T>::operator=(Vec<T> const &value) {
  RowVectorBase<T>::operator=(value);
  return *this;
}

template <typename T>
RowVector2D<T> &RowVector2D<T>::operator=(RowVector2D<T> const &other) {
  RowVectorBase<T>::operator=(other);
  return *this;
}

template <typename T>
RowVector2D<T> &RowVector2D<T>::operator=(RowVector2D<T> &&other) noexcept {
  RowVectorBase<T>::operator=(std::move(other));
  return *this;
}

template <typename T>
RowVector2D<T> &RowVector2D<T>::operator=(MatrixBase<T> const &other) {
  RowVectorBase<T>::operator=(other);
  return *this;
}

template <typename T>
RowVector2D<T> &RowVector2D<T>::operator=(MatrixBase<T> &&other) {
  RowVectorBase<T>::operator=(std::move(other));
  return *this;
}

template <typename T>
RowVector3D<T> &RowVector3D<T>::operator=(T const &value) {
  RowVectorBase<T>::operator=(value);
  return *this;
}

template <typename T>
RowVector3D<T> &RowVector3D<T>::operator=(Vec<T> const &value) {
  RowVectorBase<T>::operator=(value);
  return *this;
}

template <typename T>
RowVector3D<T> &RowVector3D<T>::operator=(RowVector3D<T> const &other) {
  RowVectorBase<T>::operator=(other);
  return *this;
}

template <typename T>
RowVector3D<T> &RowVector3D<T>::operator=(RowVector3D<T> &&other) noexcept {
  RowVectorBase<T>::operator=(std::move(other));
  return *this;
}

template <typename T>
RowVector3D<T> &RowVector3D<T>::operator=(MatrixBase<T> const &other) {
  RowVectorBase<T>::operator=(other);
  return *this;
}

template <typename T>
RowVector3D<T> &RowVector3D<T>::operator=(MatrixBase<T> &&other) {
  RowVectorBase<T>::operator=(std::move(other));
  return *this;
}

template <typename T>
RowVector4D<T> &RowVector4D<T>::operator=(T const &value) {
  RowVectorBase<T>::operator=(value);
  return *this;
}

template <typename T>
RowVector4D<T> &RowVector4D<T>::operator=(Vec<T> const &value) {
  RowVectorBase<T>::operator=(value);
  return *this;
}

template <typename T>
RowVector4D<T> &RowVector4D<T>::operator=(RowVector4D<T> const &other) {
  RowVectorBase<T>::operator=(other);
  return *this;
}

template <typename T>
RowVector4D<T> &RowVector4D<T>::operator=(RowVector4D<T> &&other) noexcept {
  RowVectorBase<T>::operator=(std::move(other));
  return *this;
}

template <typename T>
RowVector4D<T> &RowVector4D<T>::operator=(MatrixBase<T> const &other) {
  RowVectorBase<T>::operator=(other);
  return *this;
}

template <typename T>
RowVector4D<T> &RowVector4D<T>::operator=(MatrixBase<T> &&other) {
  RowVectorBase<T>::operator=(std::move(other));
  return *this;
}

template <typename T>
RowVectorBase<T> Normalize(RowVectorBase<T> const &vector) {
  T length = vector.AcquireLength();
  if (length == 0) {
    return vector;
  }
  RowVectorBase<T> result = vector.GetCopy();
  return result / length;
}

template <typename T>
RowVector3D<T> Cross(RowVectorBase<T> const &lhs, RowVectorBase<T> const &rhs) {
  Uint lComps = lhs.GetComps();
  Uint rComps = rhs.GetComps();

  if (lComps > 3 || rComps > 3) {
    std::runtime_error("Incompatible vector size.");
  }

  RowVector3D<T> v1;
  RowVector3D<T> v2;
  memcpy(v1.GetArray(), lhs.GetArray(), sizeof(T) * lhs.GetSize());
  memcpy(v2.GetArray(), rhs.GetArray(), sizeof(T) * rhs.GetSize());

  MatrixBase<T> result(1, 3, 0);
  result(0, 0) = v1(0, 1) * v2(0, 2) - v1(0, 2) * v2(0, 1);
  result(0, 1) = v1(0, 2) * v2(0, 0) - v1(0, 0) * v2(0, 2);
  result(0, 2) = v1(0, 0) * v2(0, 1) - v1(0, 1) * v2(0, 0);
  return result;
}

} // namespace TerreateMath::Vector
#endif // __TC_MATH_VECTOR_ROW_HPP__
