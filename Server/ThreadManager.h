/*
 * ThreadManager.h
 *
 *  Created on: Dec 28, 2017
 *      Author: shomps
 */

#ifndef SRC_SERVER_THREADMANAGER_H_
#define SRC_SERVER_THREADMANAGER_H_

#include <pthread.h>
#include <vector>

using namespace std;

class ThreadManager {
private:
	vector<pthread_t> threads;
public:
	ThreadManager();
	void addThread(pthread_t thread);
	void join(pthread_t thread);
	void joinAll();
	virtual ~ThreadManager();
};

#endif /* SRC_SERVER_THREADMANAGER_H_ */
