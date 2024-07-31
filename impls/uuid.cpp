#include "../includes/uuid.hpp"

#include <iomanip>

namespace TerreateCore::Core {
std::mt19937 UUID::sRandomEngine = std::mt19937(std::random_device()());

void UUID::GenerateUUID() {
  auto time = std::chrono::system_clock::now();
  time_t epoch = time.time_since_epoch().count();
  std::memcpy(mUUID, &epoch, sizeof(time_t));
  for (int i = 0; i < 2; i++) {
    TCu32 random = sRandomEngine();
    std::memcpy(mUUID + sizeof(time_t) + i * sizeof(TCu32), &random,
                sizeof(TCu32));
  }
}

Str UUID::ToString() const {
  std::stringstream ss;
  for (int i = 0; i < 8; i++) {
    TCi16 block = 0;
    std::memcpy(&block, mUUID + i * sizeof(TCi16), sizeof(TCi16));
    std::memcpy(&block, mUUID + i * sizeof(TCi16), sizeof(TCi16));
    ss << std::hex << std::setfill('0') << std::setw(4) << block;
    if (i != 7)
      ss << "-";
  }
  return ss.str();
}

UUID &UUID::operator=(UUID const &other) {
  std::memcpy(mUUID, other.mUUID, sizeof(char) * 16);
  return *this;
}

UUID &UUID::operator=(UUID &&other) {
  std::memcpy(mUUID, other.mUUID, sizeof(char) * 16);
  return *this;
}
} // namespace TerreateCore::Core

std::ostream &operator<<(std::ostream &stream,
                         TerreateCore::Core::UUID const &uuid) {
  stream << uuid.ToString();
  return stream;
}
