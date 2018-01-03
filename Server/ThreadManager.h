/**
 * Names       : Yifat Yankocivh
 * 				 Shoham Bar-Gad
 * IDs	       : 204709224
 * 				 315706614
 * User Names  : yankovy
 * 				 bagnosh
 *
 * Class Name  : ThreadManager.h
 * Description : Defines the methods of ThreadManager
 */

#ifndef SRC_SERVER_THREADMANAGER_H_
#define SRC_SERVER_THREADMANAGER_H_

#include <pthread.h>
#include <vector>

using namespace std;

class ThreadManager {
private:
	vector<pthread_t> threads_;
	pthread_mutex_t thread_mutex_;
public:

	/** Function name	: constructor
	 * Parameters		: none
	 * Return value	    : new ThreadManager
	 * General flow	    : constructs a ThreadManager
	 */
	ThreadManager();

	/** Function name	: addThread
	 * Parameters		: pthread
	 * Return value	    : none
	 * General flow	    : adds a thread
	 */
	void addThread(pthread_t thread);

	/** Function name	: joinThread
	 * Parameters		: pthread
	 * Return value	    : none
	 * General flow	    : joins a thread
	 */
	void join(pthread_t thread);

	/** Function name	: joinAll
	 * Parameters		: none
	 * Return value	    : none
	 * General flow	    : joins all threads
	 */
	void joinAll();

	/** Function name	: likkAll
	 * Parameters		: none
	 * Return value	    : none
	 * General flow	    : kills all threads
	 */
	void killAll();

	/** Function name	: destructor
	 * Parameters		: none
	 * Return value	    : none
	 * General flow	    : deletes ThreadManager
	 */
	virtual ~ThreadManager();
};

#endif /* SRC_SERVER_THREADMANAGER_H_ */
