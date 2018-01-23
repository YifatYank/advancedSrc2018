/**
 * Names       : Yifat Yankocivh
 * 				 Shoham Bar-Gad
 * IDs	       : 204709224
 * 				 315706614
 * User Names  : yankovy
 * 				 bagnosh
 *
 * Class Name  : JoinCommand.h
 * Description : Defines the methods of JoinCommand
 */

#ifndef SERVER_JOINCOMMAND_H_
#define SERVER_JOINCOMMAND_H_

#include "Command.h"
#include "GameMaster.h"
#include "SocketManager.h"
#include "ThreadManager.h"

class JoinCommand: public Command {
private:
	string name_;
	GameMaster & games_;
	SocketManager * sockets_;
	ThreadManager * threads_;

public:
	/** Function name	: constructor
	 * Parameters		: pointers to GameMaster, SocketManager
	 * Return value	    : new JoinCommand
	 * General flow	    : constructs a JoinCommand
	 */
	JoinCommand(GameMaster & games_master, SocketManager * sockets, ThreadManager * threads);

	/** Function name	: getName
	 * Parameters		: none
	 * Return value	    : string
	 * General flow	    : returns command's name
	 */
	virtual string getName();

	/** Function name	: execute
	 * Parameters		: vector<string>
	 * Return value	    : boolean
	 * General flow	    : executes command
	 */
	virtual bool execute(vector <string> args);

	/** Function name	: destructor
	 * Parameters		: none
	 * Return value	    : none
	 * General flow	    : deletes the JoinCommand
	 */
	virtual ~JoinCommand();

	/** Function name	: executeThread
	 * Parameters		: void* (generic pointer)
	 * Return value	    : none
	 * General flow	    : static method. executes thread
	 */
	static void * executeThread(void * params);
};

typedef struct {
	int client_socket1;
	int client_sokcet2;
	JoinCommand * command;
} params_to_join_command_thread;

#endif /* SERVER_JOINCOMMAND_H_ */
