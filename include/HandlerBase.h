/*
 * HandlerBase.h
 *
 *  Created on: May 24, 2016
 *      Author: apodolin
 *      Modified: Asier Gutierrez <asierguti@gmail.com>
 */

#ifndef HANDLERBASE_H_
#define HANDLERBASE_H_
class SenderBase;

class HandlerBase {
private:
	SenderBase& _sender; /**< sender's link */
	bool _active; /**< thread status */
	// Why do we need a bool here? This would mean a waste in the cache lines.
	// Almost everytime there is a bool, it's because there is some kind of state change,
	// so we are emulating a FSM. There are much more efficient ways to do it
	
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
