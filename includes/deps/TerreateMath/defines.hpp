#ifndef __TM_DEFINES_HPP__
#define __TM_DEFINES_HPP__

#include <cstdint>
#include <iostream>
#include <string>
#include <vector>

#define TM_PI 3.14159265358979

namespace TerreateMath::Defines {
typedef bool Bool;
typedef int32_t Int;
typedef uint32_t Uint;
typedef float Float;
typedef double Double;
typedef std::string Str;

template <typename T> using Vec = std::vector<T>;
} // namespace TerreateMath::Defines

#endif // __TM_DEFINES_HPP__
