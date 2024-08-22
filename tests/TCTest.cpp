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
    Executor::Task task([&jobStamps, &jobStampsMutex, i] {
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
    executor.Schedule(std::move(task));
    BusyWork(RandomInt(10, 30));
  }
  executor.WaitForAll();

  auto end = Defines::Now();
  std::cout << "Normal Task: "
            << Defines::DurationCast<Defines::MilliSec>(end - start).count()
            << "ms" << std::endl;
  for (auto const &[id, stamps] : jobStamps) {
    auto &stamp = stamps[0];
    std::cout << "Thread: " << std::setw(5) << std::setfill(' ') << id << " | "
              << Executor::Utils::CreateJobTimeLine(stamps, start, end) << " |"
              << std::endl;
  }
}

void TestDependencyTask() {
  Executor::Executor executor(2);

  auto start = Defines::Now();
  Defines::Map<std::thread::id, Defines::Vec<Executor::Utils::JobStamp>>
      jobStamps;
  Defines::Mutex jobStampsMutex;

  Executor::Task task1([&jobStamps, &jobStampsMutex] {
    Executor::Utils::JobStamp jobStamp;
    jobStamp.id = 'A';
    jobStamp.start = Defines::Now();
    auto thID = std::this_thread::get_id();
    BusyWork(RandomInt(10, 100));
    std::lock_guard lock(jobStampsMutex);
    if (jobStamps.find(std::this_thread::get_id()) == jobStamps.end()) {
      jobStamps[thID] = {};
    }
    jobStamp.end = Defines::Now();
    jobStamps[thID].push_back(jobStamp);
  });

  Executor::Task task2([&jobStamps, &jobStampsMutex] {
    Executor::Utils::JobStamp jobStamp;
    jobStamp.id = 'B';
    jobStamp.start = Defines::Now();
    auto thID = std::this_thread::get_id();
    BusyWork(RandomInt(10, 100));
    std::lock_guard lock(jobStampsMutex);
    if (jobStamps.find(std::this_thread::get_id()) == jobStamps.end()) {
      jobStamps[thID] = {};
    }
    jobStamp.end = Defines::Now();
    jobStamps[thID].push_back(jobStamp);
  });

  Executor::Task task3([&jobStamps, &jobStampsMutex] {
    Executor::Utils::JobStamp jobStamp;
    jobStamp.id = 'C';
    jobStamp.start = Defines::Now();
    auto thID = std::this_thread::get_id();
    BusyWork(RandomInt(10, 100));
    std::lock_guard lock(jobStampsMutex);
    if (jobStamps.find(std::this_thread::get_id()) == jobStamps.end()) {
      jobStamps[thID] = {};
    }
    jobStamp.end = Defines::Now();
    jobStamps[thID].push_back(jobStamp);
  });

  Executor::Task task4([&jobStamps, &jobStampsMutex] {
    Executor::Utils::JobStamp jobStamp;
    jobStamp.id = 'D';
    jobStamp.start = Defines::Now();
    auto thID = std::this_thread::get_id();
    BusyWork(RandomInt(10, 100));
    std::lock_guard lock(jobStampsMutex);
    if (jobStamps.find(std::this_thread::get_id()) == jobStamps.end()) {
      jobStamps[thID] = {};
    }
    jobStamp.end = Defines::Now();
    jobStamps[thID].push_back(jobStamp);
  });

  Executor::Task task5([&jobStamps, &jobStampsMutex] {
    Executor::Utils::JobStamp jobStamp;
    jobStamp.id = 'E';
    jobStamp.start = Defines::Now();
    auto thID = std::this_thread::get_id();
    BusyWork(RandomInt(10, 100));
    std::lock_guard lock(jobStampsMutex);
    if (jobStamps.find(std::this_thread::get_id()) == jobStamps.end()) {
      jobStamps[thID] = {};
    }
    jobStamp.end = Defines::Now();
    jobStamps[thID].push_back(jobStamp);
  });

  Executor::Task task6([&jobStamps, &jobStampsMutex] {
    Executor::Utils::JobStamp jobStamp;
    jobStamp.id = 'F';
    jobStamp.start = Defines::Now();
    auto thID = std::this_thread::get_id();
    BusyWork(RandomInt(10, 100));
    std::lock_guard lock(jobStampsMutex);
    if (jobStamps.find(std::this_thread::get_id()) == jobStamps.end()) {
      jobStamps[thID] = {};
    }
    jobStamp.end = Defines::Now();
    jobStamps[thID].push_back(jobStamp);
  });

  Executor::Task task7([&jobStamps, &jobStampsMutex] {
    Executor::Utils::JobStamp jobStamp;
    jobStamp.id = 'G';
    jobStamp.start = Defines::Now();
    auto thID = std::this_thread::get_id();
    BusyWork(RandomInt(10, 100));
    std::lock_guard lock(jobStampsMutex);
    if (jobStamps.find(std::this_thread::get_id()) == jobStamps.end()) {
      jobStamps[thID] = {};
    }
    jobStamp.end = Defines::Now();
    jobStamps[thID].push_back(jobStamp);
  });

  Executor::Task task8([&jobStamps, &jobStampsMutex] {
    Executor::Utils::JobStamp jobStamp;
    jobStamp.id = 'H';
    jobStamp.start = Defines::Now();
    auto thID = std::this_thread::get_id();
    BusyWork(RandomInt(10, 100));
    std::lock_guard lock(jobStampsMutex);
    if (jobStamps.find(std::this_thread::get_id()) == jobStamps.end()) {
      jobStamps[thID] = {};
    }
    jobStamp.end = Defines::Now();
    jobStamps[thID].push_back(jobStamp);
  });

  Executor::Task task9([&jobStamps, &jobStampsMutex] {
    Executor::Utils::JobStamp jobStamp;
    jobStamp.id = 'I';
    jobStamp.start = Defines::Now();
    auto thID = std::this_thread::get_id();
    BusyWork(RandomInt(10, 100));
    std::lock_guard lock(jobStampsMutex);
    if (jobStamps.find(std::this_thread::get_id()) == jobStamps.end()) {
      jobStamps[thID] = {};
    }
    jobStamp.end = Defines::Now();
    jobStamps[thID].push_back(jobStamp);
  });

  task3.AddDependency(task1.GetHandle());
  task3.AddDependency(task2.GetHandle());

  task6.AddDependency(task4.GetHandle());
  task6.AddDependency(task5.GetHandle());

  executor.Schedule(std::move(task1));
  executor.Schedule(std::move(task2));
  executor.Schedule(std::move(task3));
  executor.Schedule(std::move(task4));
  executor.Schedule(std::move(task5));
  executor.Schedule(std::move(task6));
  executor.Schedule(std::move(task7));
  executor.Schedule(std::move(task8));
  executor.Schedule(std::move(task9));

  executor.WaitForAll();

  auto end = Defines::Now();
  std::cout << "Dependency Task: "
            << Defines::DurationCast<Defines::MilliSec>(end - start).count()
            << "ms" << std::endl;
  for (auto const &[id, stamps] : jobStamps) {
    auto &stamp = stamps[0];
    std::cout << "Thread: " << std::setw(5) << std::setfill(' ') << id << " | "
              << Executor::Utils::CreateJobTimeLine(stamps, start, end) << " |"
              << std::endl;
  }
}

int main() {
  TestNormalTask();
  TestDependencyTask();
  return 0;
}
