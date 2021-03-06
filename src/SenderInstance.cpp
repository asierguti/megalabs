/*
 * ServerInstance.cpp
 *
 *  Created on: July 15, 2016
 *      Author: Asier Gutierrez <asierguti@gmail.com>
 */

#include "SenderInstance.h"
#include <chrono>
#include <iostream>
#include <thread>
SenderInstance::SenderInstance() {}

void SenderInstance::init() {
  auto sender = new SenderNetwork(shared_from_this());
  auto thread = new QThread();
  sender->moveToThread(thread);
  connect(thread, SIGNAL(started()), sender, SLOT(run()));
  thread->start();
}

std::list<MetricBody> SenderInstance::getMetrics() {
 std::list<MetricBody> temp_list {};
 temp_list.splice (temp_list.begin(), _metrics);
 return temp_list;
}


void SenderInstance::addMetric(const std::string& name, long int count) {
  if (count < 0) {
    throw "negative count";
  }

  if (name.empty()) {
    throw "empty name";
  }

  std::lock_guard<std::mutex> lock(_mutex);

  auto end_iterator = _metrics.end();
  auto it =
      std::find_if(_metrics.begin(), end_iterator,
                   [&name](const MetricBody& x) { return x.name == name; });

  if (it != end_iterator) {
    it->count += count;
  } else {
    MetricBody metric{name, count};
    _metrics.push_back(metric);
  }
}
