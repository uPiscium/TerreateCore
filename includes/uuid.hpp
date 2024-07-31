#ifndef _TERREATECORE_UUID_HPP__
#define _TERREATECORE_UUID_HPP__

#include <cstring>
#include <random>

#include "defines.hpp"

namespace TerreateCore::Core {
using namespace TerreateCore::Defines;

class UUID {
private:
  Byte mUUID[16] = {0};
  static std::mt19937 sRandomEngine;

private:
  void GenerateUUID();
  UUID(Byte const *uuid) { std::memcpy(mUUID, uuid, sizeof(char) * 16); }
  UUID(Str const &uuid) { std::memcpy(mUUID, uuid.c_str(), sizeof(char) * 16); }

public:
  UUID() { GenerateUUID(); }
  UUID(const UUID &other) {
    std::memcpy(mUUID, other.mUUID, sizeof(char) * 16);
  }

  Byte const *Raw() const { return mUUID; }

  Str ToString() const;
  size_t Hash() const { return std::hash<Str>{}(ToString()); }

  bool operator==(UUID const &other) const {
    return std::memcmp(mUUID, other.mUUID, sizeof(char) * 16) == 0;
  }
  bool operator!=(UUID const &other) const {
    return std::memcmp(mUUID, other.mUUID, sizeof(char) * 16) != 0;
  }
  bool operator<(UUID const &other) const {
    return std::memcmp(mUUID, other.mUUID, sizeof(char) * 16) < 0;
  }
  bool operator>(UUID const &other) const {
    return std::memcmp(mUUID, other.mUUID, sizeof(char) * 16) > 0;
  }
  bool operator<=(UUID const &other) const {
    return std::memcmp(mUUID, other.mUUID, sizeof(char) * 16) <= 0;
  }
  bool operator>=(UUID const &other) const {
    return std::memcmp(mUUID, other.mUUID, sizeof(char) * 16) >= 0;
  }
  UUID &operator=(UUID const &other);
  UUID &operator=(UUID &&other);
  operator size_t() const { return this->Hash(); }
  operator Str() const { return this->ToString(); }

public:
  static UUID FromChar(Byte const *uuid) { return UUID(uuid); }
  static UUID FromString(Str const &uuid) { return UUID(uuid); }
};
} // namespace TerreateCore::Core

std::ostream &operator<<(std::ostream &stream,
                         TerreateCore::Core::UUID const &uuid);

template <> struct std::hash<TerreateCore::Core::UUID> {
  size_t operator()(TerreateCore::Core::UUID const &uuid) const {
    return std::hash<std::string>()(uuid.ToString());
  }
};

#endif // _TERREATECORE_UUID_HPP__
