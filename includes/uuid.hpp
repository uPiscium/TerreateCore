#ifndef _TERREATECORE_UUID_HPP__
#define _TERREATECORE_UUID_HPP__

#include <cstring>
#include <random>

#include "defines.hpp"

namespace TerreateCore::Core {
using namespace TerreateCore::Defines;

class UUID {
private:
  static Uint const sUUIDLength = 32;

private:
  TCi8 mUUID[sUUIDLength] = {0};
  static std::mt19937 sRandomEngine;

private:
  void GenerateUUID();
  UUID(TCi8 const *uuid);
  UUID(Str const &uuid) {
    std::memcpy(mUUID, uuid.c_str(), sizeof(TCi8) * sUUIDLength);
  }

public:
  UUID() { this->GenerateUUID(); }
  UUID(UUID const &other) { this->GenerateUUID(); }
  UUID(UUID &&other) {
    std::memcpy(mUUID, other.mUUID, sizeof(TCi8) * sUUIDLength);
  }

  TCi8 const *Raw() const { return mUUID; }

  Str ToString() const;
  size_t Hash() const { return std::hash<Str>{}(this->ToString()); }

  bool operator==(UUID const &other) const {
    return std::memcmp(mUUID, other.mUUID, sizeof(TCi8) * sUUIDLength) == 0;
  }
  bool operator!=(UUID const &other) const {
    return std::memcmp(mUUID, other.mUUID, sizeof(TCi8) * sUUIDLength) != 0;
  }
  bool operator<(UUID const &other) const {
    return std::memcmp(mUUID, other.mUUID, sizeof(TCi8) * sUUIDLength) < 0;
  }
  bool operator>(UUID const &other) const {
    return std::memcmp(mUUID, other.mUUID, sizeof(TCi8) * sUUIDLength) > 0;
  }
  bool operator<=(UUID const &other) const {
    return std::memcmp(mUUID, other.mUUID, sizeof(TCi8) * sUUIDLength) <= 0;
  }
  bool operator>=(UUID const &other) const {
    return std::memcmp(mUUID, other.mUUID, sizeof(TCi8) * sUUIDLength) >= 0;
  }
  UUID &operator=(UUID const &other);
  UUID &operator=(UUID &&other);
  operator size_t() const { return this->Hash(); }
  operator Str() const { return this->ToString(); }

public:
  static UUID FromTCi8(TCi8 const *uuid) { return UUID(uuid); }
  static UUID FromString(Str const &uuid) { return UUID(uuid); }
  static UUID Empty() { return UUID(nullptr); }
  static UUID Copy(UUID const &uuid) {
    return UUID::FromString(uuid.ToString());
  }
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
