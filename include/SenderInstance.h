/*
 * SenderBase.h
 *
 *  Created on: July 15, 2016
 *      Author: Asier Gutierrez <asierguti@gmail.com>
 */

#ifndef SENDERINSTANCE_H_
#define SENDERINTANSCE_H_

#include <QtCore/QtCore>
#include <QtNetwork/QtNetwork>
#include "SenderBase.h"

class SenderInstance : public SenderBase, public QObject {
private:
	std::list<MetricBody> _metrics; /**< metrics */
	std::mutex _mutex; /**< metrcis main mutex */

	QTcpSocket *_pSocket;

private slots:
	void init();
	void sendAlive();

public:
	SenderInstance() = default;
	virtual ~SenderInstance();

	virtual void run();
	virtual void addMetric(const std::string& name, long int count = 0) ;
};

#endif /* ifndef SENDERINSTANCE_H_ */
