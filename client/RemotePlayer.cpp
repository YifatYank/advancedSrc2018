/**
 * Names       : Yifat Yankocivh
 * 				 Shoham Bar-Gad
 * IDs	       : 204709224
 * 				 315706614
 * User Names  : yankovy
 * 				 bagnosh
 *
 * Class Name  : RemotePlayer.h
 * Description : Implements the methods of the RemotePlayer class.
 */

#include "ConsuleDisplay.h"
#include "RemotePlayer.h"
#include <iostream>

#define BLACK_PLAYER 1
#define WHITE_PLAYER 2


RemotePlayer::RemotePlayer(Client & client): client_(client), value_(WHITE), first_t_(true) {
}

RemotePlayer::RemotePlayer(CellValue value, Client & client) : client_(client), value_(value), first_t_(true){
}

CellValue RemotePlayer::getValue() const {
	return this->value_;
}


RemotePlayer::~RemotePlayer(){

}

Point RemotePlayer::move(vector<Point *> * moves, Point opponent_move,
		Board &board) {
	int x_coord = 0, y_coord = 0;

	// Send to the other player, the local player's last move,
	// and get his move
	try {
		// If this is not the first turn of the first player.
		if (!(this->first_t_ && opponent_move == Point(NO_MOVE, NO_MOVE))) {
			this->client_.sendInt(opponent_move.getX());
			this->client_.sendInt(opponent_move.getY());
		}

        ConsuleDisplay console = ConsuleDisplay();
        console.Display(board);
        cout << "Waiting for other player's move..." << endl;

		// If the opponent next move i the game next move
		// the remote opponent wont return an answer so we deals with these case localy.
		if (board.getEmptyCellsNumber() == 1 && moves->size() == 1) {
			x_coord = moves->back()->getX();
			y_coord= moves->back()->getY();
		} else {
			// Waiting for the opponent to send his moves.
			x_coord = this->client_.reciveInt();
			y_coord = this->client_.reciveInt();

			// If the server has closed
			if(x_coord == -2 || y_coord == -2){
				cout << "The server was closed" << endl;
			}
		}

	} catch (const char *msg) {
		cout << msg << endl;
	}

	moves->clear();
	delete (moves);
	this->first_t_ = false;
	return Point(x_coord, y_coord);
}
