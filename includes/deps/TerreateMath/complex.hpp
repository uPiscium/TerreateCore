#ifndef __TC_MATH_COMPLEX_HPP__
#define __TC_MATH_COMPLEX_HPP__

#include <cmath>

#include "core.hpp"
#include "defines.hpp"

namespace TerreateMath::Complex {
using namespace TerreateMath::Defines;

template <typename T> class Complex {
private:
  T mReal;
  T mImaginary;

public:
  Complex() : mReal(static_cast<T>(0)), mImaginary(static_cast<T>(0)) {}
  Complex(T real, T imaginary) : mReal(real), mImaginary(imaginary) {}
  Complex(Complex<T> const &other)
      : mReal(other.mReal), mImaginary(other.mImaginary) {}
  Complex(Complex<T> &&other)
      : mReal(other.mReal), mImaginary(other.mImaginary) {}
  template <typename U>
  Complex(Complex<U> const &other)
      : mReal(static_cast<T>(other.mReal)),
        mImaginary(static_cast<T>(other.mImaginary)) {}
  template <typename U>
  Complex(Complex<U> &&other)
      : mReal(static_cast<T>(other.mReal)),
        mImaginary(static_cast<T>(other.mImaginary)) {}

  T const &GetReal() const { return mReal; }
  T const &GetImaginary() const { return mImaginary; }

  T AcquireLength() const {
    return sqrt(mReal * mReal + mImaginary * mImaginary);
  }
  T AcquireArg() const { return atan2(mImaginary, mReal); }

  Complex<T> operator+() const { return *this; }
  Complex<T> operator-() const { return Complex<T>(-mReal, -mImaginary); }

  Complex<T> &operator=(Complex<T> const &other);
  Complex<T> &operator=(Complex<T> &&other);
  template <typename U> Complex<T> &operator=(Complex<U> const &other);

  Complex<T> &operator+=(Complex<T> const &other);
  Complex<T> &operator-=(Complex<T> const &other);
  Complex<T> &operator*=(Complex<T> const &other);
  Complex<T> &operator/=(Complex<T> const &other);

  Complex<T> &operator*=(T const &scalar);
  Complex<T> &operator/=(T const &scalar);
};

template <typename T>
Complex<T> operator+(Complex<T> const &lhs, Complex<T> const &rhs) {
  return Complex<T>(lhs.GetReal() + rhs.GetReal(),
                    lhs.GetImaginary() + rhs.GetImaginary());
}
template <typename T>
Complex<T> operator-(Complex<T> const &lhs, Complex<T> const &rhs) {
  return Complex<T>(lhs.GetReal() - rhs.GetReal(),
                    lhs.GetImaginary() - rhs.GetImaginary());
}
template <typename T>
Complex<T> operator*(Complex<T> const &lhs, Complex<T> const &rhs) {
  return Complex<T>(
      lhs.GetReal() * rhs.GetReal() - lhs.GetImaginary() * rhs.GetImaginary(),
      lhs.GetReal() * rhs.GetImaginary() + lhs.GetImaginary() * rhs.GetReal());
}
template <typename T>
Complex<T> operator/(Complex<T> const &lhs, Complex<T> const &rhs);
template <typename T>
Complex<T> operator*(Complex<T> const &lhs, T const &scalar) {
  return Complex<T>(lhs.GetReal() * scalar, lhs.GetImaginary() * scalar);
}
template <typename T>
Complex<T> operator*(T const &scalar, Complex<T> const &rhs) {
  return Complex<T>(rhs.GetReal() * scalar, rhs.GetImaginary() * scalar);
}
template <typename T>
Complex<T> operator/(Complex<T> const &lhs, T const &scalar) {
  return Complex<T>(lhs.GetReal() / scalar, lhs.GetImaginary() / scalar);
}
template <typename T>
Complex<T> operator/(T const &scalar, Complex<T> const &rhs);
} // namespace TerreateMath::Complex

// Implementation
namespace TerreateMath::Complex {
using namespace TerreateMath::Defines;

template <typename T>
Complex<T> &Complex<T>::operator=(Complex<T> const &other) {
  mReal = other.mReal;
  mImaginary = other.mImaginary;
  return *this;
}

template <typename T> Complex<T> &Complex<T>::operator=(Complex<T> &&other) {
  mReal = other.mReal;
  mImaginary = other.mImaginary;
  return *this;
}

template <typename T>
template <typename U>
Complex<T> &Complex<T>::operator=(Complex<U> const &other) {
  mReal = static_cast<T>(other.mReal);
  mImaginary = static_cast<T>(other.mImaginary);
  return *this;
}

template <typename T>
Complex<T> &Complex<T>::operator+=(Complex<T> const &other) {
  mReal += other.mReal;
  mImaginary += other.mImaginary;
  return *this;
}

template <typename T>
Complex<T> &Complex<T>::operator-=(Complex<T> const &other) {
  mReal -= other.mReal;
  mImaginary -= other.mImaginary;
  return *this;
}

template <typename T>
Complex<T> &Complex<T>::operator*=(Complex<T> const &other) {
  T real = mReal * other.mReal - mImaginary * other.mImaginary;
  T imaginary = mReal * other.mImaginary + mImaginary * other.mReal;
  mReal = real;
  mImaginary = imaginary;
  return *this;
}

template <typename T>
Complex<T> &Complex<T>::operator/=(Complex<T> const &other) {
  T denominator =
      other.mReal * other.mReal - other.mImaginary * other.mImaginary;
  T real = (mReal * other.mReal + mImaginary * other.mImaginary) / denominator;
  T imaginary =
      (mImaginary * other.mReal - mReal * other.mImaginary) / denominator;
  mReal = real;
  mImaginary = imaginary;
  return *this;
}

template <typename T> Complex<T> &Complex<T>::operator*=(T const &scalar) {
  mReal *= scalar;
  mImaginary *= scalar;
  return *this;
}

template <typename T> Complex<T> &Complex<T>::operator/=(T const &scalar) {
  mReal /= scalar;
  mImaginary /= scalar;
  return *this;
}

template <typename T>
Complex<T> operator/(Complex<T> const &lhs, Complex<T> const &rhs) {
  T denominator =
      rhs.GetReal() * rhs.GetReal() - rhs.GetImaginary() * rhs.GetImaginary();
  T real = (lhs.GetReal() * rhs.GetReal() +
            lhs.GetImaginary() * rhs.GetImaginary()) /
           denominator;
  T imaginary = (lhs.GetImaginary() * rhs.GetReal() -
                 lhs.GetReal() * rhs.GetImaginary()) /
                denominator;
  return Complex<T>(real, imaginary);
}

template <typename T>
Complex<T> operator/(T const &scalar, Complex<T> const &rhs) {
  T denominator =
      rhs.GetReal() * rhs.GetReal() + rhs.GetImaginary() * rhs.GetImaginary();
  T real = scalar * rhs.GetReal() / denominator;
  T imaginary = -scalar * rhs.GetImaginary() / denominator;
  return Complex<T>(real, imaginary);
}

template <typename T> T Abs(Complex<T> const &c) { return c.AcquireLength(); }

} // namespace TerreateMath::Complex

namespace TerreateMath::Core {
template <typename T>
struct MatrixTypeTraits<TerreateMath::Complex::Complex<T>> {
  static Str ToString(TerreateMath::Complex::Complex<T> const &c) {
    if (c.GetImaginary() >= static_cast<T>(0)) {
      return std::to_string(c.GetReal()) + " + " +
             std::to_string(c.GetImaginary()) + "i";
    }
    return std::to_string(c.GetReal()) + " - " +
           std::to_string(-c.GetImaginary()) + "i";
  }
};
} // namespace TerreateMath::Core

template <typename T>
std::ostream &operator<<(std::ostream &os,
                         TerreateMath::Complex::Complex<T> const &c) {
  os << c.GetReal();
  if (c.GetImaginary() >= static_cast<T>(0)) {
    os << " + " << c.GetImaginary() << "i";
  } else {
    os << " - " << -c.GetImaginary() << "i";
  }
  return os;
}

#endif // __TC_MATH_COMPLEX_HPP__
