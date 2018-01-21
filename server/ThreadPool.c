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


