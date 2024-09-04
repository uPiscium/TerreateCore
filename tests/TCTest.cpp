#include "../includes/TerreateCore.hpp"

#include <iostream>

using namespace TerreateCore;

template <typename T> struct CustomDeleter {
  void operator()(T *ptr) {
    if (ptr) {
      delete[] ptr;
    }
  }
};

int main() {
  std::cout << "Nullable Test" << std::endl;
  std::cout << "-------------" << std::endl;

  std::cout << "[int]" << std::endl;
  Utils::Nullable<int> n;
  std::cout << n.Valid() << std::endl;
  n = 5;
  std::cout << n.Valid() << std::endl;
  std::cout << *n << std::endl;
  std::cout << n.Value() << std::endl;
  std::cout << "-------------" << std::endl;

  std::cout << "[int*]" << std::endl;
  Utils::Nullable<int *> p;
  std::cout << p.Valid() << std::endl;
  p = new int(5);
  std::cout << p.Valid() << std::endl;
  std::cout << **p << std::endl;
  std::cout << *p.Value() << std::endl;
  std::cout << "-------------" << std::endl;

  std::cout << "[int*] with custom deleter" << std::endl;
  Utils::Nullable<int *, CustomDeleter<int *>> p2;
  std::cout << p2.Valid() << std::endl;
  p2 = new int[5];
  std::cout << p2.Valid() << std::endl;
  std::cout << p2.Value() << std::endl;
  for (int i = 0; i < 5; i++) {
    p2.Value()[i] = i;
  }
  for (int i = 0; i < 5; i++) {
    std::cout << p2.Value()[i] << " ";
  }
  std::cout << std::endl;
  std::cout << "-------------" << std::endl;

  return 0;
}
