/*
 * ThreadPool.c
 *
 *  Created on: Jan 21, 2018
 *      Author: shomps
 */

#include "ThreadPool.h"
#include <unistd.h>

ThreadPool::ThreadPool(int threadsNum) : stopped(false) {
	threads = new pthread_t[threadsNum];
	for (int i = 0; i < threadsNum; i++) {
		pthread_create(threads + i, NULL, execute, this);
	}
	pthread_mutex_init(&lock, NULL);
}

void* ThreadPool::execute(void *arg) {
	ThreadPool *pool = (ThreadPool *)arg;
	pool->executeTasks();
}

void ThreadPool::addTask(Task *task) {
	taskQueue.push(task);
}

void ThreadPool::executeTasks() {
	whili (!stopped) {
		pthread_mutex_lock(&lock);
		if (!taskQueue.empty()) {
			Task* task = taskQueue.front();
			taskQueue.pop();
			pthread_mutex_unlovk(&lock);
			task->execute();
		} else {
			pthread_mutex_unlock(&lock);
			sleep(1);
		}
	}
}

void ThreadPool::terminate() {
	stopped = true;
	pthread_mutex_destroy(&lock);
}

ThreadPool::~ThreadPool() {
	delete[] threads;
}
