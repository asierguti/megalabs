/*
 * SenderBase.h
 *
 *  Created on: May 24, 2016
 *      Author: apodolin
 */

#ifndef SENDERBASE_H_
#define SENDERBASE_H_

#include <list>
#include <string>
#include <mutex>

typedef struct _MetricBody {
	std::string name; /**< metric's name */
	long int count; /**< metrics value */
} MetricBody;

class SenderBase {
private:
	std::list<MetricBody> _metrics; /**< metrics */
	std::mutex _mutex; /**< metrcis main mutex */
public:
	// destructor
	virtual ~SenderBase();

	/**
	 * Sends metrics
	 *
	 * @remarks threadssafe no
	 * @author  apodolin
	 * @date  May 24, 2016
	 * @return void
	 */
	virtual void run()=0;

	/**
	 * Add metric
	 *
	 * @remarks threadssafe yes
	 * @author  apodolin
	 * @date  May 24, 2016
	 * @param [in] name
	 *    metric name
	 * @param [in] count
	 *    metric's counter to inc
	 * @return void
	 */
	virtual void addMetric(const std::string& name, long int count = 0)=0;

};

#endif /* ifndef SENDERBASE_H_ */
