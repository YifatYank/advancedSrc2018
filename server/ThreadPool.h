/*
 * ThreadPool.h
 *
 *  Created on: Jan 21, 2018
 *      Author: shomps
 */

#ifndef SRC_SERVER_THREADPOOL_H_
#define SRC_SERVER_THREADPOOL_H_

#include <queue>
#include "Task.h"
#include <pthread.h>

using namespace std;

class ThreadPool {
private:
	ThreadPool(int threadsNum);
	void addTask(Task *task);
	void terminate();
	virtual ~ThreadPool();
public:
	queue<Task *> tasksQueue;
	pthread_t* threads;
	void executeTasks();
	bool stopped;
	pthread_mutex_t lock;

	static void *execute(void *arg);
};


#endif /* SRC_SERVER_THREADPOOL_H_ */
