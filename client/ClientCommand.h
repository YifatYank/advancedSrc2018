/**
 * Names       : Yifat Yankocivh
 * 				 Shoham Bar-Gad
 * IDs	       : 204709224
 * 				 315706614
 * User Names  : yankovy
 * 				 bagnosh
 *
 * Class Name  : ClientCommant.h
 * Description : Defines the methods of the ClientCommand interface
 */

#ifndef CLIENT_CLIENTCOMMAND_H_
#define CLIENT_CLIENTCOMMAND_H_

#include <vector>
#include <string>
using namespace std;


class ClientCommand {
public:
	/** Function name	: getName
	 *  Parameters		: none
	 *  Return value	: string
	 *  General flow	: returns command's name
	 */
	virtual string getName() = 0;

	/** Function name	: execute
	 *  Parameters		: string
	 *  Return value	: boolean
	 *  General flow	: executes command
	 */
	virtual bool execute(string command) = 0;

	/** Function name	: destructor
	 *  Parameters		: none
	 *  Return value	: none
	 *  General flow	: deletes command
	 */
	virtual ~ClientCommand(){}
};

#endif /* CLIENT_CLIENTCOMMAND_H_ */
