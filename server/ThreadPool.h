/**
 * Names       : Yifat Yankocivh
 * 				 Shoham Bar-Gad
 * IDs	       : 204709224
 * 				 315706614
 * User Names  : yankovy
 * 				 bagnosh
 *
 * Class Name  : ThreadPool.h
 * Description : Defines the methods of ThreadPool
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

	/** Function name	: execute
	 * Parameters		: void* (generic pointer)
	 * Return value	    : void* (generic pointer)
	 * General flow	    : static method, executes task
	 */
	static void *execute(void *arg);

public:
	/** Function name	: constructor
	 * Parameters		: integer (number of desired threads)
	 * Return value	    : new ThreadPool
	 * General flow	    : constructs a ThreadPool
	 */
	ThreadPool(int threadsNum);

	/** Function name	: addTask
	 * Parameters		: pointer to Task
	 * Return value	    : none
	 * General flow	    : adds a Task to the queue
	 */
	void addTask(Task *task);

	/** Function name	: terminate
	 * Parameters		: none
	 * Return value	    : none
	 * General flow	    : terminates all threads
	 */
	void terminate();

	/** Function name	: destructor
	 * Parameters		: none
	 * Return value	    : none
	 * General flow	    : deletes the ThreadPool
	 */
	virtual ~ThreadPool();
};

#endif /* SRC_SERVER_THREADPOOL_H_ */
