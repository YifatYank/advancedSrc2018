/**
 * Names       : Yifat Yankocivh
 * 				 Shoham Bar-Gad
 * IDs	       : 204709224
 * 				 315706614
 * User Names  : yankovy
 * 				 bagnosh
 *
 * Class Name  : StartCommand.h
 * Description : Defines the methods of StartCommand
 */

#ifndef SERVER_STARTCOMMAND_H_
#define SERVER_STARTCOMMAND_H_

#include "Command.h"
#include "GameMaster.h"

class StartCommand: public Command {
private:
	string name_;
	GameMaster & games_;

public:
	/** Function name	: constructor
	 * Parameters		: pointers to GameMaster
	 * Return value	    : new StartCommand
	 * General flow	    : constructs a StartCommand
	 */
	StartCommand(GameMaster & games_master);

	/** Function name	: execute
	 * Parameters		: vector<string>
	 * Return value	    : boolean
	 * General flow	    : executes command
	 */
	virtual bool execute(vector <string> args);

	/** Function name	: getName
	 * Parameters		: none
	 * Return value	    : string
	 * General flow	    : returns command's name
	 */
	virtual string getName();

	/** Function name	: destructor
	 * Parameters		: none
	 * Return value	    : none
	 * General flow	    : deletes the StartCommand
	 */
	virtual ~StartCommand();
};

#endif /* SERVER_STARTCOMMAND_H_ */
