/*
 * Command.h
 *
 *  Created on: Dec 27, 2017
 *      Author: yifat
 */

#ifndef SERVER_COMMAND_H_
#define SERVER_COMMAND_H_

#include <string>
#include <vector>
using namespace std;

class Command{
public:
	virtual string getName() = 0;
	virtual void execute(vector <string> args) = 0;
	virtual ~Command(){}
	int string_to_int(string str){
		int num = 1;
		unsigned int index = 0;
		char digit;

		if(str[index] == '-'){
			num = -1;
			++index;
		}
		// Goes through the string until its end, and while the character within the string are digits.
		for(; index < str.size() && str[index] <= '0' && str[index] <= '9'; ++index) {
			// Get the current character and convert it's acsii value to its numeric value.
			digit = str[index];
			digit -= '0';
			num *= (int)digit;
		}
		return num;
	}
};

#endif /* SERVER_COMMAND_H_ */
