/*
 * ServerInstance.cpp
 *
 *  Created on: July 15, 2016
 *      Author: Asier Gutierrez <asierguti@gmail.com>
 */

#include "SenderInstance.h"

// SenderInstance::SenderInstance() = default;
SenderInstance::~SenderInstance()
{}

void SenderInstance::sendAlive() {

	auto received = _pSocket->readAll();
}

void SenderInstance::init() {
    _pSocket = new QTcpSocket( this ); 
    connect( _pSocket, SIGNAL(readyRead()), SLOT(sendAlive()) );

    _pSocket->connectToHost("85.143.218.211", 9977);	
}

void SenderInstance::run() {
    QByteArray data;

    if( _pSocket->waitForConnected() ) {
        _pSocket->write( data );
    }
}

void SenderInstance::addMetric(const std::string& name, long int count) {
	if (count < 0) {
		throw "negative count";
	}

	if (name.empty()) {
		throw "empty name";
	}

    std::lock_guard<std::mutex> lock(_mutex);

    MetricBody metric {name, count};
    _metrics.push_back (metric);
}
