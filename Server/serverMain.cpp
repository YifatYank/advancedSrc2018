/*
 * serverMain.cpp
 *
 *  Created on: Dec 10, 2017
 *      Author: yifat
 */
#include "Server.h"
#define PORT 8002

int main(){
	Server server(PORT);
	server.start();
	server.stop();
	return 0;
}
