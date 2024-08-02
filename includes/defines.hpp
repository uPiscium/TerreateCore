#ifndef __TERREATECORE_DEFINES_HPP__
#define __TERREATECORE_DEFINES_HPP__

#include <chrono>
#include <cstdint>
#include <fstream>
#include <functional>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include <TerreateMath/TerreateMath.hpp>

#ifndef TC_PI
#define TC_PI 3.14159265358979
#endif // TC_PI

#ifndef TC_UNICODE_HALF_SPACE
#define TC_UNICODE_HALF_SPACE 32
#endif // TC_UNICODE_HALF_SPACE

#ifndef TC_UNICODE_FULL_SPACE
#define TC_UNICODE_FULL_SPACE 32306
#endif // TC_UNICODE_FULL_SPACE

namespace TerreateCore::Defines {
// Type aliases
// TC types (TerreateCore types)
typedef bool TCbool;
typedef int8_t TCi8;
typedef uint8_t TCu8;
typedef int16_t TCi16;
typedef uint16_t TCu16;
typedef int32_t TCi32;
typedef uint32_t TCu32;
typedef int64_t TCi64;
typedef uint64_t TCu64;
typedef float TCfloat;
typedef double TCdouble;

// Standard types
typedef TCbool Bool;
typedef TCi8 Byte;
typedef TCu8 Ubyte;
typedef TCi16 Short;
typedef TCu16 Ushort;
typedef TCi32 Int;
typedef TCu32 Uint;
typedef TCi64 Long;
typedef TCu64 Ulong;
typedef TCfloat Float;
typedef TCdouble Double;

typedef TCu32 ID;
typedef TCu64 Index;
typedef TCu64 EventID;
typedef TCu64 Size;
typedef std::string Str;
typedef std::wstring WStr;
typedef std::stringstream Stream;
typedef std::ifstream InputFileStream;
typedef std::ofstream OutputFileStream;

template <typename S, typename T> using Map = std::unordered_map<S, T>;
template <typename T> using Pair = std::pair<T, T>;
template <typename T> using Set = std::unordered_set<T>;
template <typename T> using Vec = std::vector<T>;
template <typename T> using Function = std::function<T>;

// Chrono types
namespace chrono = std::chrono;
typedef chrono::nanoseconds NanoSec;
typedef chrono::system_clock SystemClock;
typedef chrono::steady_clock SteadyClock;
template <typename T> using ZonedTimeT = chrono::zoned_time<T>;
using ZonedTime = ZonedTimeT<NanoSec>;

// TM types (TerreateMath types)
typedef TerreateMath::Math::complex complex;
typedef TerreateMath::Math::fraction fraction;
typedef TerreateMath::Math::matrix matrix;

typedef TerreateMath::Math::vec2 vec2;
typedef TerreateMath::Math::vec3 vec3;
typedef TerreateMath::Math::vec4 vec4;

typedef TerreateMath::Math::mat2 mat2;
typedef TerreateMath::Math::mat2x3 mat2x3;
typedef TerreateMath::Math::mat2x4 mat2x4;
typedef TerreateMath::Math::mat3x2 mat3x2;
typedef TerreateMath::Math::mat3 mat3;
typedef TerreateMath::Math::mat3x4 mat3x4;
typedef TerreateMath::Math::mat4x2 mat4x2;
typedef TerreateMath::Math::mat4x3 mat4x3;
typedef TerreateMath::Math::mat4 mat4;

typedef TerreateMath::Math::quat quat;

// Concepts
template <typename Derived, typename Base>
concept extends = std::derived_from<Derived, Base>;
template <typename Enum>
concept enumtype = std::is_enum_v<Enum>;

// Functions
template <typename T> inline Str ToStr(T const &val) {
  Stream stream;
  stream << val;
  return stream.str();
}
template <typename S, typename T> inline S DurationCast(T const &time) {
  return chrono::duration_cast<S>(time);
}
inline SteadyClock::duration SinceEpoch() {
  return SteadyClock::now().time_since_epoch();
}
inline Double GetNanoSec() {
  return static_cast<Double>(DurationCast<NanoSec>(SinceEpoch()).count()) /
         1000000000;
}
inline ZonedTime GetCurrentTime() {
  return ZonedTime{chrono::current_zone(), SystemClock::now()};
}

} // namespace TerreateCore::Defines

#endif // __TERREATECORE_DEFINES_HPP__
