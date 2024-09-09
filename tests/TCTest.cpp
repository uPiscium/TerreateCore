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
  Utils::Executor executor;

  std::cout << "Executor Test" << std::endl;
  std::cout << "-------------" << std::endl;

  Defines::Vec<Utils::SharedFuture<void>> futures;
  for (int i = 0; i < 4; ++i) {
    futures.push_back(executor.Schedule([]() {
      std::this_thread::sleep_for(std::chrono::seconds(1));
      std::cout << "Task 1" << std::endl;
    }));
    futures.push_back(executor.Schedule([]() {
      std::this_thread::sleep_for(std::chrono::seconds(0));
      std::cout << "Task 2" << std::endl;
    }));
  }
  executor.Schedule([]() { std::cout << "Task 3" << std::endl; }, futures);

  executor.WaitForAll();
}

int main() {
  ExecutorTest();
  return 0;
}
