/**
 * Names       : Yifat Yankocivh
 * 				 Shoham Bar-Gad
 * IDs	       : 204709224
 * 				 315706614
 * User Names  : yankovy
 * 				 bagnosh
 *
 * Class Name  : ListCommand.h
 * Description : Defines the methods of ListCommand
 */

#ifndef SRC_SERVER_LISTCOMMAND_H_
#define SRC_SERVER_LISTCOMMAND_H_

#include "Command.h"
#include "GameMaster.h"

class ListCommand: public Command {
private:
	string name_;
	GameMaster & games_;

public:

	/** Function name	: constructor
	 * Parameters		: pointers to GameMaster
	 * Return value	    : new ListCommand
	 * General flow	    : constructs a ListCommand
	 */
	ListCommand(GameMaster & games_master);

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
	 * General flow	    : deletes the ListCommand
	 */
	virtual ~ListCommand();
};

#endif /* SRC_SERVER_LISTCOMMAND_H_ */
