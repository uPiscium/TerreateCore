#ifndef __TERREATE_GRAPHICS_BITFLAG_HPP__
#define __TERREATE_GRAPHICS_BITFLAG_HPP__

#include "defines.hpp"

namespace TerreateCore::Core {
using namespace TerreateCore::Defines;

template <enumtype T> class BitFlag {
public:
  using Flag = typename std::underlying_type<T>::type;

private:
  Flag mFlag = static_cast<Flag>(0);

public:
  BitFlag() {}
  BitFlag(T const &flag) : mFlag(static_cast<Flag>(flag)) {}
  BitFlag(Flag const &flag) : mFlag(flag) {}

  void Set(T const &flag) { mFlag |= static_cast<Flag>(flag); }
  void Set(Flag const &flag) { mFlag |= flag; }

  void Unset(T const &flag) { mFlag &= ~static_cast<Flag>(flag); }
  void Unset(Flag const &flag) { mFlag &= ~flag; }

  void Toggle(T const &flag) { mFlag ^= static_cast<Flag>(flag); }
  void Toggle(Flag const &flag) { mFlag ^= flag; }

  Bool IsSet(T const &flag) const {
    return (mFlag & static_cast<Flag>(flag)) != 0;
  }
  Bool IsSet(Flag const &flag) const { return (mFlag & flag) != 0; }

  void Clear() { mFlag = static_cast<Flag>(0); }

  BitFlag<T> &operator=(T const &flag);
  BitFlag<T> &operator=(Flag const &flag);

  BitFlag<T> &operator~();

  BitFlag<T> &operator|=(T const &flag);
  BitFlag<T> &operator|=(Flag const &flag);
  BitFlag<T> &operator&=(T const &flag);
  BitFlag<T> &operator&=(Flag const &flag);
  BitFlag<T> &operator^=(T const &flag);
  BitFlag<T> &operator^=(Flag const &flag);

  Bool operator==(T const &flag) const {
    return mFlag == static_cast<Flag>(flag);
  }
  Bool operator==(Flag const &flag) const { return mFlag == flag; }
  Bool operator!=(T const &flag) const {
    return mFlag != static_cast<Flag>(flag);
  }
  Bool operator!=(Flag const &flag) const { return mFlag != flag; }

  explicit operator T() const { return static_cast<T>(mFlag); }
  explicit operator Flag() const { return mFlag; }
  operator Bool() const { return mFlag != static_cast<Flag>(0); }
};

template <enumtype T>
BitFlag<T> operator|(BitFlag<T> const &lhs, BitFlag<T> const &rhs);
template <enumtype T>
BitFlag<T> operator&(BitFlag<T> const &lhs, BitFlag<T> const &rhs);
template <enumtype T>
BitFlag<T> operator^(BitFlag<T> const &lhs, BitFlag<T> const &rhs);
template <enumtype T> BitFlag<T> operator|(BitFlag<T> const &lhs, T const &rhs);
template <enumtype T> BitFlag<T> operator&(BitFlag<T> const &lhs, T const &rhs);
template <enumtype T> BitFlag<T> operator^(BitFlag<T> const &lhs, T const &rhs);
template <enumtype T> BitFlag<T> operator|(T const &lhs, BitFlag<T> const &rhs);
template <enumtype T> BitFlag<T> operator&(T const &lhs, BitFlag<T> const &rhs);
template <enumtype T> BitFlag<T> operator^(T const &lhs, BitFlag<T> const &rhs);
template <enumtype T> BitFlag<T> operator|(T const &lhs, T const &rhs);
template <enumtype T> BitFlag<T> operator&(T const &lhs, T const &rhs);
template <enumtype T> BitFlag<T> operator^(T const &lhs, T const &rhs);
} // namespace TerreateCore::Core

// Implementation
namespace TerreateCore::Core {
using namespace TerreateCore::Defines;

template <enumtype T> BitFlag<T> &BitFlag<T>::operator=(T const &flag) {
  mFlag = static_cast<Flag>(flag);
  return *this;
}

template <enumtype T> BitFlag<T> &BitFlag<T>::operator=(Flag const &flag) {
  mFlag = flag;
  return *this;
}

template <enumtype T> BitFlag<T> &BitFlag<T>::operator~() {
  mFlag = ~mFlag;
  return *this;
}

template <enumtype T> BitFlag<T> &BitFlag<T>::operator|=(T const &flag) {
  mFlag |= static_cast<Flag>(flag);
  return *this;
}

template <enumtype T> BitFlag<T> &BitFlag<T>::operator|=(Flag const &flag) {
  mFlag |= flag;
  return *this;
}

template <enumtype T> BitFlag<T> &BitFlag<T>::operator&=(T const &flag) {
  mFlag &= static_cast<Flag>(flag);
  return *this;
}

template <enumtype T> BitFlag<T> &BitFlag<T>::operator&=(Flag const &flag) {
  mFlag &= flag;
  return *this;
}

template <enumtype T> BitFlag<T> &BitFlag<T>::operator^=(T const &flag) {
  mFlag ^= static_cast<Flag>(flag);
  return *this;
}

template <enumtype T> BitFlag<T> &BitFlag<T>::operator^=(Flag const &flag) {
  mFlag ^= flag;
  return *this;
}

template <enumtype T>
BitFlag<T> operator|(BitFlag<T> const &lhs, BitFlag<T> const &rhs) {
  BitFlag<T> result(lhs);
  result |= rhs;
  return result;
}

template <enumtype T>
BitFlag<T> operator&(BitFlag<T> const &lhs, BitFlag<T> const &rhs) {
  BitFlag<T> result(lhs);
  result &= rhs;
  return result;
}

template <enumtype T>
BitFlag<T> operator^(BitFlag<T> const &lhs, BitFlag<T> const &rhs) {
  BitFlag<T> result(lhs);
  result ^= rhs;
  return result;
}

template <enumtype T>
BitFlag<T> operator|(BitFlag<T> const &lhs, T const &rhs) {
  BitFlag<T> result(lhs);
  result |= rhs;
  return result;
}

template <enumtype T>
BitFlag<T> operator&(BitFlag<T> const &lhs, T const &rhs) {
  BitFlag<T> result(lhs);
  result &= rhs;
  return result;
}

template <enumtype T>
BitFlag<T> operator^(BitFlag<T> const &lhs, T const &rhs) {
  BitFlag<T> result(lhs);
  result ^= rhs;
  return result;
}

template <enumtype T>
BitFlag<T> operator|(T const &lhs, BitFlag<T> const &rhs) {
  BitFlag<T> result(lhs);
  result |= rhs;
  return result;
}

template <enumtype T>
BitFlag<T> operator&(T const &lhs, BitFlag<T> const &rhs) {
  BitFlag<T> result(lhs);
  result &= rhs;
  return result;
}

template <enumtype T>
BitFlag<T> operator^(T const &lhs, BitFlag<T> const &rhs) {
  BitFlag<T> result(lhs);
  result ^= rhs;
  return result;
}

template <enumtype T> BitFlag<T> operator|(T const &lhs, T const &rhs) {
  BitFlag<T> result(lhs);
  result |= rhs;
  return result;
}

template <enumtype T> BitFlag<T> operator&(T const &lhs, T const &rhs) {
  BitFlag<T> result(lhs);
  result &= rhs;
  return result;
}

template <enumtype T> BitFlag<T> operator^(T const &lhs, T const &rhs) {
  BitFlag<T> result(lhs);
  result ^= rhs;
  return result;
}
} // namespace TerreateCore::Core

#endif // __TERREATE_GRAPHICS_BITFLAG_HPP__
