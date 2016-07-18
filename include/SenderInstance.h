/*
 * SenderBase.h
 *
 *  Created on: July 15, 2016
 *      Author: Asier Gutierrez <asierguti@gmail.com>
 */

#ifndef SENDERINSTANCE_H_
#define SENDERINSTANCE_H_

#include <QtCore/QtCore>
#include <list>
#include <thread>
#include "SenderBase.h"
#include "SenderNetwork.h"

class SenderNetwork;

class SenderInstance : public QObject,
                       public SenderBase,
                       public std::enable_shared_from_this<SenderInstance> {
  Q_OBJECT
 private:
  std::list<MetricBody> _metrics; /**< metrics */
  std::mutex _mutex;              /**< metrcis main mutex */
  std::chrono::high_resolution_clock::time_point _time;

  std::unique_ptr<SenderNetwork> _SenderNetwork;
  std::thread _senderThread;

 public:
  virtual void run() {}
  void init();

  std::list<MetricBody> getMetrics() { return _metrics; }

  SenderInstance();
  virtual ~SenderInstance() { _senderThread.join(); }

  SenderInstance(const SenderInstance& other){};
  virtual void addMetric(const std::string& name, long int count = 0);
};

#endif /* ifndef SENDERINSTANCE_H_ */