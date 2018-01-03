/*
 * RemotePlayer.h
 *
 *  Created on: Dec 10, 2017
 *      Author: yifat
 */

#ifndef REMOTEPLAYER_H_
#define REMOTEPLAYER_H_

#include "Player.h"
#include "Client.h"

class RemotePlayer: public Player {
private:
	Client & client_;
	CellValue value_;
	bool first_t_; //Indicates weather it is the first step of the user.

public:
	RemotePlayer(Client & client);
	RemotePlayer(CellValue value, Client & client);

	/** Function name	: getValue
	 *  Parameters		: None.
	 *  Return value	: a player's value, their "color".
	 *  General flow	: The function returns the player's value,
	 *  				  the player's color.
	 */
	virtual CellValue getValue() const;

	/** Function name	: move
	 *  Parameters      : list of possible moves, last move of  the opponent,
	 *  				  game board.
	 *  Return value	: The point chosen between the points provided.
	 *  General flow	: The function lets the user choose their next move,
	 *  				  checks if the point is legal,
	 *  				  and returns the point finally chosen.
	 */
	virtual Point move(vector<Point *> * moves, Point opponent_move,
			Board &board);

	virtual ~RemotePlayer();
};

#endif /* REMOTEPLAYER_H_ */
