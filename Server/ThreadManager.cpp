/*
 * ThreadManager.cpp
 *
 *  Created on: Dec 28, 2017
 *      Author: shomps
 */

#include "ThreadManager.h"

using namespace std;

ThreadManager::ThreadManager() {
	this->threads = vector<pthread_t>();
}

void ThreadManager::addThread(pthread_t thread) {
	this->threads.push_back(thread);
}

void ThreadManager::join(pthread_t thread) {
	vector<pthread_t>::iterator it;
	for (it = this->threads.begin(); it != this->threads.end(); it++) {
		if (*it == thread) {
			void *status;
			pthread_t som = *it;
			//pthread_join(som,&status);
			this->threads.erase(it);
		}
	}
}

void ThreadManager::joinAll() {
	vector<pthread_t>::iterator it;
	for (it = this->threads.begin(); it != this->threads.end(); it++) {
			void *status;
			pthread_t threadno = *it;
			//pthread_join(threadno, &status);
			this->threads.erase(it);
	}
}
ThreadManager::~ThreadManager() {
	this->threads.clear();
}
