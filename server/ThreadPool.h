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
	queue<Task *> tasksQueue_;
	pthread_t* threads_;
	void executeTasks();
	bool stopped_;
	pthread_mutex_t lock_;

	static void *execute(void *arg);

public:
	ThreadPool(int threadsNum);
	void addTask(Task *task);
	void terminate();
	virtual ~ThreadPool();
};

#endif /* SRC_SERVER_THREADPOOL_H_ */
