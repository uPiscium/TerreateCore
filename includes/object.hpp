#ifndef __TERREATECORE_OBJECT_HPP__
#define __TERREATECORE_OBJECT_HPP__

#include "defines.hpp"
#include "uuid.hpp"

namespace TerreateCore::Core {
class TerreateObjectBase {
private:
  UUID mUUID;

public:
  TerreateObjectBase() : mUUID() {}
  TerreateObjectBase(UUID const &uuid) : mUUID(uuid) {}
  TerreateObjectBase(TerreateObjectBase const &other) : mUUID(other.mUUID) {}
  virtual ~TerreateObjectBase() {}

  UUID const &GetUUID() const { return mUUID; }

  bool operator==(TerreateObjectBase const &other) const {
    return mUUID == other.mUUID;
  }
  bool operator!=(TerreateObjectBase const &other) const {
    return mUUID != other.mUUID;
  }
  bool operator<(TerreateObjectBase const &other) const {
    return mUUID < other.mUUID;
  }
  bool operator>(TerreateObjectBase const &other) const {
    return mUUID > other.mUUID;
  }
  bool operator<=(TerreateObjectBase const &other) const {
    return mUUID <= other.mUUID;
  }
  bool operator>=(TerreateObjectBase const &other) const {
    return mUUID >= other.mUUID;
  }

  TerreateObjectBase &operator=(TerreateObjectBase const &other);
  TerreateObjectBase &operator=(TerreateObjectBase &&other);

  operator Str() const { return mUUID.ToString(); }
  operator Byte const *() const { return mUUID.Raw(); }
  operator size_t() const { return mUUID.Hash(); }
};
} // namespace TerreateCore::Core

std::ostream &operator<<(std::ostream &os,
                         TerreateCore::Core::TerreateObjectBase const &obj);

#endif // __TERREATECORE_OBJECT_HPP__
