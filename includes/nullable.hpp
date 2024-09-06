#ifndef __TERREATECORE_NULLABLE_HPP__
#define __TERREATECORE_NULLABLE_HPP__

#include "defines.hpp"
#include "exceptions.hpp"

namespace TerreateCore::Utils {
using namespace TerreateCore::Defines;

template <typename T> struct NullableTypeTraits {
  typedef T &RefenceType;
  typedef T const &ConstRefenceType;
  typedef T &&MoveType;
};

template <> struct NullableTypeTraits<void> {
  typedef void RefenceType;
  typedef void ConstRefenceType;
  typedef void MoveType;
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
  typedef typename NullableTypeTraits<T>::MoveType MoveType;

private:
  T *mValue;
  Deleter mDeleter;

public:
  Nullable() : mValue(nullptr) {}
  Nullable(ConstRefenceType value) : mValue(new T(value)) {}
  Nullable(MoveType value) : mValue(new T(std::move(value))) {}
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
  ConstRefenceType Value() const {
    if (!this->Valid()) {
      throw Exceptions::NullReferenceException("Nullable is null");
    } else {
      return *mValue;
    }
  }
  RefenceType Value() {
    if (!this->Valid()) {
      throw Exceptions::NullReferenceException("Nullable is null");
    } else {
      return *mValue;
    }
  }
  T const *Get() const { return mValue; }
  T *Get() { return mValue; }

  ConstRefenceType operator*() const {
    if (!this->Valid()) {
      throw Exceptions::NullReferenceException("Nullable is null");
    } else {
      return *mValue;
    }
  }
  RefenceType operator*() {
    if (!this->Valid()) {
      throw Exceptions::NullReferenceException("Nullable is null");
    } else {
      return *mValue;
    }
  }
  T *operator->() { return mValue; }

  Nullable &operator=(ConstRefenceType value) {
    mDeleter(mValue);
    mValue = new T(value);
    return *this;
  }
  Nullable &operator=(MoveType value) {
    mDeleter(mValue);
    mValue = new T(std::move(value));
    return *this;
  }
  Nullable &operator=(Nullable const &other) {
    if (this != &other) {
      mDeleter(mValue);
      mValue = other.mValue ? new T(*other.mValue) : nullptr;
    }
    return *this;
  }
  Nullable &operator=(Nullable &&other) {
    if (this != &other) {
      mDeleter(mValue);
      mValue = other.mValue;
      other.mValue = nullptr;
    }
    return *this;
  }
  template <typename U> Nullable &operator=(Nullable<U> const &other) {
    mDeleter(mValue);
    mValue = other.mValue ? new T(*other.mValue) : nullptr;
    return *this;
  }

  operator ConstRefenceType() const {
    if (!this->Valid()) {
      throw Exceptions::NullReferenceException("Nullable is null");
    } else {
      return *mValue;
    }
  }
  operator RefenceType() {
    if (!this->Valid()) {
      throw Exceptions::NullReferenceException("Nullable is null");
    } else {
      return *mValue;
    }
  }
};
} // namespace TerreateCore::Utils

#endif // __TERREATECORE_NULLABLE_HPP__
