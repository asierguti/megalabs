/*
 * HandlerBase.cpp
 *
 *  Created on: May 24, 2016
 *      Author: apodolin
 */

#include "HandlerBase.h"

#include <chrono>
#include <thread>

#include "SenderBase.h"

HandlerBase::HandlerBase(SenderBase& sender) :
		_sender(sender), _active(true) {
}

HandlerBase::~HandlerBase() {
	_active = false;
}

void HandlerBase::run() {
	while (_active) {
		_sender.addMetric("jobs.count", 1);
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	}
}
