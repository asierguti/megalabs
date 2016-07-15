/*
 * HandlerBase.h
 *
 *  Created on: May 24, 2016
 *      Author: apodolin
 */

#ifndef HANDLERBASE_H_
#define HANDLERBASE_H_
class SenderBase;

class HandlerBase {
private:
	SenderBase& _sender; /**< sender's link */
	bool _active; /**< thread status */
public:
	// constructor
	HandlerBase(SenderBase& sender);

	// destructor
	virtual ~HandlerBase();

	/**
	 * Do some job
	 *
	 * @remarks threadssafe no
	 * @author  apodolin
	 * @date  May 24, 2016
	 * @return void
	 */
	void run();
};

#endif /* ifndef HANDLERBASE_H_ */
