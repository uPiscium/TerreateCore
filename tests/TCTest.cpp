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

void NullableTest() {
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
}

void ExecutorTest() {
  Utils::Executor executor(2);

  Utils::Task successTask([]() { std::cout << "Success Task" << std::endl; });
  Utils::Task failTask([]() {
    std::cout << "Fail Task" << std::endl;
    throw std::runtime_error("Fail Task");
  });

  executor.Schedule(std::move(successTask));
  executor.Schedule(std::move(failTask));

  executor.WaitForAll();

  for (auto &exception : executor.GetExceptions()) {
    try {
      std::rethrow_exception(exception);
    } catch (std::exception const &e) {
      std::cout << e.what() << std::endl;
    }
  }
}

int main() {
  ExecutorTest();
  return 0;
}
