/**
 * Names       : Yifat Yankocivh
 * 				 Shoham Bar-Gad
 * IDs	       : 204709224
 * 				 315706614
 * User Names  : yankovy
 * 				 bagnosh
 *
 * Class Name  : Command.h
 * Description : Defines the methods of the Command interface.
 */

#ifndef SERVER_COMMAND_H_
#define SERVER_COMMAND_H_

#include <string>
#include <vector>
using namespace std;

class Command{
public:
	/** Function name	: getName
	 * Parameters		: none
	 * Return value	    : string
	 * General flow	    : returns command's name
	 */
	virtual string getName() = 0;

	/** Function name	: execute
	 * Parameters		: vector<string>
	 * Return value	    : boolean
	 * General flow	    : executed the command
	 */
	virtual bool execute(vector <string> args) = 0;

	/** Function name	: destructor
	 * Parameters		: none
	 * Return value	    : none
	 * General flow	    : destroys the command
	 */
	virtual ~Command(){}

	/** Function name	: stringToInt
	 * Parameters		: string
	 * Return value	    : integer
	 * General flow	    : converts a string into an integer
	 */
	int string_to_int(string str){
		int num = 1;
		unsigned int index = 0;
		char digit;

		if(str[index] == '-'){
			num = -1;
			++index;
		}
		// Goes through the string until its end, and while the character within the string are digits.
		for(; index < str.size() && str[index] >= '0' && str[index] <= '9'; ++index) {
			// Get the current character and convert it's acsii value to its numeric value.
			digit = str[index];
			digit -= '0';
			num *= (int)digit;
		}
		return num;
	}
};

#endif /* SERVER_COMMAND_H_ */
