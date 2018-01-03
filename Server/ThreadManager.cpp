#include "ThreadManager.h"

using namespace std;

ThreadManager::ThreadManager() {
	this->threads_ = vector<pthread_t>();
}

void ThreadManager::addThread(pthread_t thread) {
	pthread_mutex_lock(&this->thread_mutex_);
	this->threads_.push_back(thread);
	pthread_mutex_unlock(&this->thread_mutex_);
}

void ThreadManager::join(pthread_t thread) {
	pthread_mutex_lock(&this->thread_mutex_);
	void * status;
	vector<pthread_t>::iterator it;
	for (it = this->threads_.begin(); it != this->threads_.end(); it ++) {
		if (pthread_equal((*it), thread) != 0) {
			this->threads_.erase(it);
			break;
		}
	}
	pthread_join(thread, &status);
	pthread_mutex_unlock(&this->thread_mutex_);
}

void ThreadManager::joinAll() {
	pthread_mutex_lock(&this->thread_mutex_);
	void * status;
	for (unsigned int i = 0; i < this->threads_.size(); i ++) {
		pthread_t temp = this->threads_.back();
		this->threads_.pop_back();
		pthread_join(temp, &status);
	}
	pthread_mutex_unlock(&this->thread_mutex_);
}

ThreadManager::~ThreadManager() {
	this->joinAll();
}
