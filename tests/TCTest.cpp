#include "../includes/TerreateCore.hpp"

#include <iomanip>
#include <iostream>
#include <random>

using namespace TerreateCore;

int RandomInt(int min, int max) {
  static std::random_device rd;
  static std::mt19937 gen(rd());
  std::uniform_int_distribution<int> dist(min, max);
  return dist(gen);
}

void BusyWork(Defines::Uint const &ms) {
  std::this_thread::sleep_for(std::chrono::milliseconds(ms));
}

void TestNormalTask() {
  Executor::Executor executor;

  auto start = Defines::Now();
  Defines::Map<std::thread::id, Defines::Vec<Executor::Utils::JobStamp>>
      jobStamps;
  Defines::Mutex jobStampsMutex;
  for (Defines::Uint i = 0; i < 10; ++i) {
    executor.Schedule([&jobStamps, &jobStampsMutex, i] {
      Executor::Utils::JobStamp jobStamp;
      jobStamp.id = 'A' + i;
      jobStamp.start = Defines::Now();
      auto thID = std::this_thread::get_id();
      BusyWork(RandomInt(100, 1000));
      std::lock_guard lock(jobStampsMutex);
      if (jobStamps.find(std::this_thread::get_id()) == jobStamps.end()) {
        jobStamps[thID] = {};
      }
      jobStamp.end = Defines::Now();
      jobStamps[thID].push_back(jobStamp);
    });
    BusyWork(RandomInt(10, 30));
  }
  executor.WaitForAll();

  auto end = Defines::Now();
  for (auto const &[id, stamps] : jobStamps) {
    auto &stamp = stamps[0];
    std::cout << "Thread: " << std::setw(5) << std::setfill(' ') << id << " | "
              << Executor::Utils::CreateJobTimeLine(stamps, start, end) << " |"
              << std::endl;
  }
}

void TestParallelTask() {
  Executor::Executor executor(8);

  auto start = Defines::Now();
  Defines::Map<std::thread::id, Defines::Vec<Executor::Utils::JobStamp>>
      jobStamps;
  Defines::Mutex jobStampsMutex;
  int splitCount = 10;
  int size = 10000 / splitCount;

  auto &t = executor.Schedule(
      splitCount, [size, &jobStamps, &jobStampsMutex](Defines::Uint i) {
        Executor::Utils::JobStamp jobStamp;
        jobStamp.id = 'A';
        jobStamp.start = Defines::Now();
        auto thID = std::this_thread::get_id();
        for (int j = 0; j < size; ++j) {
          Defines::Uint idx = size * i + j;
        }
        BusyWork(10);
        jobStamp.end = Defines::Now();
        std::lock_guard lock(jobStampsMutex);
        if (jobStamps.find(thID) == jobStamps.end()) {
          jobStamps[thID] = {};
        }
        jobStamps[thID].push_back(jobStamp);
      });

  executor.WaitForAll();

  auto end = Defines::Now();
  std::cout << "Parallel Task: "
            << Defines::DurationCast<Defines::MilliSec>(end - start).count()
            << "ms" << std::endl;
  for (auto const &[id, stamps] : jobStamps) {
    std::cout << "Thread: " << id << " | "
              << Executor::Utils::CreateJobTimeLine(stamps, start, end) << " |"
              << std::endl;
  }
}

int main() {
  TestParallelTask();
  return 0;
}
