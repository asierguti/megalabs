/*
 * SenderNetwork.h
 *
 *  Created on: July 15, 2016
 *      Author: Asier Gutierrez <asierguti@gmail.com>
 */

#ifndef SENDERNETWORK_H_
#define SENDERNETWORK_H_

#include "SenderInstance.h"

#include <chrono>
#include <iostream>
#include <memory>

#include <QtCore/QtCore>
#include <QtNetwork/QtNetwork>

class SenderInstance;

class SenderNetwork : public QObject {
  Q_OBJECT
 public:
  SenderNetwork() {}
  SenderNetwork(const std::shared_ptr<SenderInstance>& i)
      : _SenderInstance(i) {}
  virtual ~SenderNetwork() {}

 private:
  std::chrono::high_resolution_clock::time_point _time;
  QTcpSocket* _pSocket;

  std::shared_ptr<SenderInstance> _SenderInstance;

 public slots:
  virtual void run();
  void finished() {}
  void readHandler();
  void onConnected();
  void handleWrite(qint64);
};
#endif