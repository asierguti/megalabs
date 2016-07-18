#include "HandlerBase.h"
#include "SenderInstance.h"

#include <iostream>
#include <memory>
#include <thread>
#include <vector>

#include <QtCore/QtCore>

int main(int argc, char* argv[]) {
  int threads;

  std::cout << "Please, enter the number of working threads: ";
  std::cin >> threads;

  if (threads < 2) {
    while (threads < 2) {
      std::cout << "Enter a number bigger than 1: ";
      std::cin >> threads;
    }
  }

  std::vector<std::thread> running_threads;

  auto s = std::make_shared<SenderInstance>();
  s->init();
  SenderBase* ptr = s.get();

  for (auto i = 0; i < threads; ++i) {
    running_threads.emplace_back(
        std::thread(&HandlerBase::run, HandlerBase(*ptr)));
  }

  std::cout << "Yahoo" << std::endl;

  for (auto& t : running_threads) {
    t.join();
  }

  return 1;
}