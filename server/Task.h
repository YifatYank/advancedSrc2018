/*
 * Task.h
 *
 *  Created on: Jan 21, 2018
 *      Author: shomps
 */

#ifndef SRC_SERVER_TASK_H_
#define SRC_SERVER_TASK_H_

class Task {
private:
	void* (*func)(void *arg);
	void *arg;
public:
	Task(void * (*func)(void *arg), void* arg) : func(func), arg(arg) {}
	void execute() {
		func(arg);
	}
	virtual ~Task() {}
};



#endif /* SRC_SERVER_TASK_H_ */
