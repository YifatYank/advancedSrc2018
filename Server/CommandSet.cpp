/*
 * CommandSet.cpp
 *
 *  Created on: Dec 27, 2017
 *      Author: yifat
 */

#include "CommandSet.h"

CommandSet::CommandSet() {
}

CommandSet::~CommandSet() {
	this->commands.clear();
}

void CommandSet::addCommad(Command * command){
	this->commands[command->getName()] = command;
}
