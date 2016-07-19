/*
 * SenderNetworkF.h
 *
 *  Created on: July 15, 2016
 *      Author: Asier Gutierrez <asierguti@gmail.com>
 */

#include "SenderNetwork.h"

#include <chrono>
#include <iostream>
#include <memory>

void SenderNetwork::readHandler() {
  while (_pSocket->bytesAvailable()) {
    auto now = std::chrono::high_resolution_clock::now();
    auto delta = now - _time;
    auto received = _pSocket->readAll();
    if (received.contains("Command:Ping")) {
      _pSocket->write("Command:Pong\r\n");
      _pSocket->waitForBytesWritten();
    } else if (received.contains("Response:Done")) {
      std::cout << "Response done" << std::endl;
    }

    if (std::chrono::duration_cast<std::chrono::seconds>(delta).count() > 60) {
      auto list = _SenderInstance->getMetrics();
      std::string to_send;
      for (const auto &m : list) {
        to_send = m.name;
        to_send.append("count:");
        to_send.append(std::to_string(m.count));
        to_send.append("\r\n");
      }

      QByteArray data(to_send.c_str());
      _pSocket->write(data);

      _time = now;
    }
    _pSocket->waitForReadyRead();
  }
}

void SenderNetwork::onConnected() { return; }

void SenderNetwork::handleWrite(qint64) { return; }

void SenderNetwork::run() {
  _pSocket = new QTcpSocket(this);
  connect(_pSocket, SIGNAL(readyRead()), this, SLOT(readHandler()));
  connect(_pSocket, SIGNAL(connected()), this, SLOT(onConnected()));
  connect(_pSocket, SIGNAL(bytesWritten(qint64)), this,
          SLOT(handleWrite(qint64)));
  _pSocket->connectToHost("85.143.218.211", 9977);
  if (!_pSocket->waitForConnected(5000)) {
    std::cout << "Error: ";
  }

  QByteArray data("test.count:1\r\n\\");
  _time = std::chrono::system_clock::now();
  _pSocket->waitForReadyRead();
}