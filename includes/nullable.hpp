#ifndef __TERREATECORE_NULLABLE_HPP__
#define __TERREATECORE_NULLABLE_HPP__

#include "defines.hpp"

namespace TerreateCore::Utils {
using namespace TerreateCore::Defines;

template <typename T> struct NullableTypeTraits {
  typedef T &RefenceType;
  typedef T const &ConstRefenceType;
};

template <> struct NullableTypeTraits<void> {
  typedef void RefenceType;
  typedef void ConstRefenceType;
};

template <typename T> struct DefaultDeleter {
  void operator()(T *ptr) {
    if (ptr) {
      delete ptr;
    }
  }
};

template <typename T, typename Deleter = DefaultDeleter<T>> class Nullable {
public:
  typedef typename NullableTypeTraits<T>::RefenceType RefenceType;
  typedef typename NullableTypeTraits<T>::ConstRefenceType ConstRefenceType;

private:
  T *mValue;
  Deleter mDeleter;

public:
  Nullable() : mValue(nullptr) {}
  Nullable(T const &value) : mValue(new T(value)) {}
  Nullable(T &&value) : mValue(new T(std::move(value))) {}
  Nullable(Nullable const &other)
      : mValue(other.mValue ? new T(*other.mValue) : nullptr) {}
  Nullable(Nullable &&other) : mValue(other.mValue) { other.mValue = nullptr; }
  template <typename U>
  Nullable(Nullable<U> const &other)
      : mValue(other.mValue ? new T(*other.mValue) : nullptr) {}
  template <typename U> Nullable(Nullable<U> &&other) : mValue(other.mValue) {
    other.mValue = nullptr;
  }
  ~Nullable() { mDeleter(mValue); }

  Bool Valid() const { return mValue != nullptr; }
  ConstRefenceType Value() const { return *mValue; }
  RefenceType Value() { return *mValue; }

  ConstRefenceType operator*() const { return *mValue; }
  RefenceType operator*() { return *mValue; }
  T *operator->() { return mValue; }

  Nullable &operator=(T const &value) {
    mDeleter(mValue);
    mValue = new T(value);
    return *this;
  }
  Nullable &operator=(T &&value) {
    mDeleter(mValue);
    mValue = new T(std::move(value));
    return *this;
  }

  operator Bool() const { return this->Valid(); }
  operator ConstRefenceType() const { return *mValue; }
  operator RefenceType() { return *mValue; }
};
} // namespace TerreateCore::Utils

#endif // __TERREATECORE_NULLABLE_HPP__
