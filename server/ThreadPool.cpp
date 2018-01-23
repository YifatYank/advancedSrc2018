/**
 * Names       : Yifat Yankocivh
 * 				 Shoham Bar-Gad
 * IDs	       : 204709224
 * 				 315706614
 * User Names  : yankovy
 * 				 bagnosh
 *
 * Class Name  : ThreadPool.cpp
 * Description : Implements the methods of ThreadPool
 */

#include "ThreadPool.h"
#include <unistd.h>

ThreadPool::ThreadPool(int threadsNum) : stopped_(false) {
	this->threads_= new pthread_t[threadsNum];
	for (int i = 0; i < threadsNum; i++) {
		pthread_create(this->threads_ + i, NULL, execute, this);
	}
	pthread_mutex_init(&this->lock_, NULL);
}

void* ThreadPool::execute(void *arg) {
	ThreadPool *pool = (ThreadPool *)arg;
	pool->executeTasks();
	return NULL;
}

void ThreadPool::addTask(Task *task) {
	this->tasksQueue_.push(task);
}

void ThreadPool::executeTasks() {
	while (!this->stopped_) {
		pthread_mutex_lock(&this->lock_);
		if (!this->tasksQueue_.empty()) {
			Task* task = this->tasksQueue_.front();
			this->tasksQueue_.pop();
			pthread_mutex_unlock(&this->lock_);
			task->execute();
		} else {
			pthread_mutex_unlock(&this->lock_);
			sleep(1);
		}
	}
}

void ThreadPool::terminate() {
	this->stopped_= true;
	pthread_mutex_destroy(&this->lock_);
}

ThreadPool::~ThreadPool() {
	delete[] threads_;
}
