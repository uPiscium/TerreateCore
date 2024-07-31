#include "../includes/object.hpp"

namespace TerreateCore::Core {
TerreateObjectBase &
TerreateObjectBase::operator=(TerreateObjectBase const &other) {
  mUUID = other.mUUID;
  return *this;
}

TerreateObjectBase &TerreateObjectBase::operator=(TerreateObjectBase &&other) {
  mUUID = std::move(other.mUUID);
  return *this;
}
} // namespace TerreateCore::Core

std::ostream &operator<<(std::ostream &os,
                         TerreateCore::Core::TerreateObjectBase const &obj) {
  os << obj.GetUUID();
  return os;
}
