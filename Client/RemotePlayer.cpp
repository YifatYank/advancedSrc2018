/*
 * RemotePlayer.cpp
 *
 *  Created on: Dec 10, 2017
 *      Author: yifat
 */

#include "RemotePlayer.h"
#include <iostream>
using namespace std;

#define BLACK_PLAYER 1
#define WHITE_PLAYER 2

RemotePlayer::RemotePlayer() : value_(WHITE) , client_(Client()), first_t_(true) {
	// Initiates the connection to the remote player
	try {
		this->client_.connectToServer();
	} catch (const char * msg) {
		cout << "Cannot start the communication to the server, reason: " << msg
				<< endl;
	}

	int player = 1;
	// Get from the server the the local player's type, and set the remote player's
	// type as the opposite of the local player's type.
	try {
		player = this->client_.reciveInt();
	} catch (const char * msg) {
		cout << msg << endl;
	}

	if (player == BLACK_PLAYER) {
		this->value_ = WHITE;
	} else if (player == WHITE_PLAYER) {
		this->value_ = BLACK;
	}
}

CellValue RemotePlayer::getValue() const {
	return this->value_;
}

Point RemotePlayer::move(vector<Point *> * moves, Point opponent_move,
		Board &board) {
	int x_coord = 0, y_coord = 0;

	moves->clear();
	delete (moves);

	// Send to the other player, the local player's last move,
	// and get his move
	try {
		// If this is not the first turn of the first player.
		if(!(this->first_t_ && opponent_move == Point(NO_MOVE,NO_MOVE))) {
			this->client_.sendInt(opponent_move.getX());
			this->client_.sendInt(opponent_move.getY());
		}

		x_coord = this->client_.reciveInt();
		y_coord = this->client_.reciveInt();
	} catch (const char *msg) {
		cout << msg << endl;
	}

	this->first_t_ = false;
	return Point(x_coord,y_coord);
}

RemotePlayer::~RemotePlayer() {
}
