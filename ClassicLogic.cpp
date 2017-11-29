/**
 * Names       : Yifat Yankocivh
 * 				 Shoham Bar-Gad
 * IDs	       : 204709224
 * 				 315706614
 * User Names  : yankovy
 * 				 bagnosh
 *
 * Class Name  : ClassicLogic.cpp
 * Description : Defines the guidelines used within the
 * 				 classic Othello game.
 */

#include "ClassicLogic.h"
using namespace std;

ClassicLogic::ClassicLogic(Board * board) {
	int half = board->getGameBoardWidth() / 2;
	this->game_board_ = board;
	this->game_board_->setCellValue(half, half, WHITE);
	this->game_board_->setCellValue(half + 1, half + 1, WHITE);
	this->game_board_->setCellValue(half, half + 1, BLACK);
	this->game_board_->setCellValue(half + 1, half, BLACK);
}

ClassicLogic::~ClassicLogic() {
	delete (this->game_board_);
}

bool ClassicLogic::playDirection(int x, int y, int xMove, int yMove,
		CellValue value, bool checkMode) {
	int isTurned;

	// If out of range
	if (this->game_board_->getCellValue(x, y) == BOEDER) {
		return false;
	}

	// If we reached an empty spot.
	if (this->game_board_->getCellValue(x, y) == EMPTY) {
		// 1 means false
		return false;
	}

	// If we reaches a cell with the current player's color
	if (this->game_board_->getCellValue(x, y) == value) {
		return true;
	}

	// We are in a cell with the opponent's color
	// Checks if there is a cell with the players color in the end
	isTurned = playDirection(x + xMove, y + yMove, xMove, yMove, value,
			checkMode);
	// If we have to turn the cell's color
	if (isTurned) {
		if (!checkMode) {
			this->game_board_->setCellValue(x, y, value);
		}
	}
	return isTurned;
}

bool ClassicLogic::playMove(Point move, CellValue value) {
	bool is_legal = false;

	this->game_board_->setCellValue(move.getX(), move.getY(), value);

	// Change up
	if ((this->game_board_->getCellValue(move.getX() - 1, move.getY()) != BOEDER)
			&& (this->game_board_->getCellValue(move.getX() - 1, move.getY())
					!= EMPTY)
			&& (this->game_board_->getCellValue(move.getX() - 1, move.getY())
					!= value)
			&& (this->playDirection(move.getX() - 1, move.getY(), -1, 0, value,
					false))) {
		is_legal = true;
	}

	// Change down
	if ((this->game_board_->getCellValue(move.getX() + 1, move.getY()) != BOEDER)
			&& (this->game_board_->getCellValue(move.getX() + 1, move.getY())
					!= EMPTY)
			&& (this->game_board_->getCellValue(move.getX() + 1, move.getY())
					!= value)
			&& (this->playDirection(move.getX() + 1, move.getY(), 1, 0, value,
					false))) {
		is_legal = true;
	}

	// Check left.
	if ((this->game_board_->getCellValue(move.getX(), move.getY() - 1) != BOEDER)
			&& (this->game_board_->getCellValue(move.getX(), move.getY() - 1)
					!= EMPTY)
			&& (this->game_board_->getCellValue(move.getX(), move.getY() - 1)
					!= value)
			&& (this->playDirection(move.getX(), move.getY() - 1, 0, -1, value,
					false))) {
		is_legal = true;
	}

	// Check right.
	if ((this->game_board_->getCellValue(move.getX(), move.getY() + 1) != BOEDER)
			&& (this->game_board_->getCellValue(move.getX(), move.getY() + 1)
					!= EMPTY)
			&& (this->game_board_->getCellValue(move.getX(), move.getY() + 1)
					!= value)
			&& (this->playDirection(move.getX(), move.getY() + 1, 0, 1, value,
					false))) {
		is_legal = true;
	}

	// Check up right
	if ((this->game_board_->getCellValue(move.getX() + 1, move.getY() + 1)
			!= BOEDER)
			&& (this->game_board_->getCellValue(move.getX() + 1,
					move.getY() + 1) != EMPTY)
			&& (this->game_board_->getCellValue(move.getX() + 1,
					move.getY() + 1) != value)
			&& (this->playDirection(move.getX() + 1, move.getY() + 1, 1, 1,
					value, false))) {
		is_legal = true;
	}

	// Check up left
	if ((this->game_board_->getCellValue(move.getX() + 1, move.getY() - 1)
			!= BOEDER)
			&& (this->game_board_->getCellValue(move.getX() + 1,
					move.getY() - 1) != EMPTY)
			&& (this->game_board_->getCellValue(move.getX() + 1,
					move.getY() - 1) != value)
			&& (this->playDirection(move.getX() + 1, move.getY() - 1, 1, -1,
					value, false))) {
		is_legal = true;
	}

	// Check down right
	if ((this->game_board_->getCellValue(move.getX() - 1, move.getY() + 1)
			!= BOEDER)
			&& (this->game_board_->getCellValue(move.getX() - 1,
					move.getY() + 1) != EMPTY)
			&& (this->game_board_->getCellValue(move.getX() - 1,
					move.getY() + 1) != value)
			&& (this->playDirection(move.getX() - 1, move.getY() + 1, -1, 1,
					value, false))) {
		is_legal = true;
	}

	// Check down left
	if ((this->game_board_->getCellValue(move.getX() - 1, move.getY() - 1)
			!= BOEDER)
			&& (this->game_board_->getCellValue(move.getX() - 1,
					move.getY() - 1) != EMPTY)
			&& (this->game_board_->getCellValue(move.getX() - 1,
					move.getY() - 1) != value)
			&& (this->playDirection(move.getX() - 1, move.getY() - 1, -1, -1,
					value, false))) {
		is_legal = true;
	}

	return is_legal;
}

vector<Point *> * ClassicLogic::getLegalMoves(CellValue value) {
	int height = this->game_board_->getGameBoardWidth();

	vector<Point *> * moves_list = new vector<Point *>();
	// Goes trough all the array cells and search for a legal move.
	for (int index = 1; index <= height; index++) {
		for (int jndex = 1; jndex <= height; jndex++) {
			if (this->game_board_->getCellValue(index, jndex) == EMPTY) {
				// Check up
				if ((this->game_board_->getCellValue(index - 1, jndex) != BOEDER)
						&& (this->game_board_->getCellValue(index - 1, jndex)
								!= EMPTY)
						&& (this->game_board_->getCellValue(index - 1, jndex)
								!= value)
						&& (this->playDirection(index - 1, jndex, -1, 0, value,
								true))) {
					Point * p = new Point(index, jndex);
					moves_list->push_back(p);
					// Check down
				} else if ((this->game_board_->getCellValue(index + 1, jndex)
						!= BOEDER)
						&& (this->game_board_->getCellValue(index + 1, jndex)
								!= EMPTY)
						&& (this->game_board_->getCellValue(index + 1, jndex)
								!= value)
						&& (this->playDirection(index + 1, jndex, 1, 0, value,
								true))) {
					Point * p = new Point(index, jndex);
					moves_list->push_back(p);
					// Check left.
				} else if ((this->game_board_->getCellValue(index, jndex - 1)
						!= BOEDER)
						&& (this->game_board_->getCellValue(index, jndex - 1)
								!= EMPTY)
						&& (this->game_board_->getCellValue(index, jndex - 1)
								!= value)
						&& (this->playDirection(index, jndex - 1, 0, -1, value,
								true))) {
					Point * p = new Point(index, jndex);
					moves_list->push_back(p);
					// Check right.
				} else if ((this->game_board_->getCellValue(index, jndex + 1)
						!= BOEDER)
						&& (this->game_board_->getCellValue(index, jndex + 1)
								!= EMPTY)
						&& (this->game_board_->getCellValue(index, jndex + 1)
								!= value)
						&& (this->playDirection(index, jndex + 1, 0, 1, value,
								true))) {
					Point * p = new Point(index, jndex);
					moves_list->push_back(p);
					// Check up right
				} else if ((this->game_board_->getCellValue(index + 1,
						jndex + 1) != BOEDER)
						&& (this->game_board_->getCellValue(index + 1,
								jndex + 1) != EMPTY)
						&& (this->game_board_->getCellValue(index + 1,
								jndex + 1) != value)
						&& (this->playDirection(index + 1, jndex + 1, 1, 1,
								value, true))) {
					Point * p = new Point(index, jndex);
					moves_list->push_back(p);
					// 	Check up left
				} else if ((this->game_board_->getCellValue(index + 1,
						jndex - 1) != BOEDER)
						&& (this->game_board_->getCellValue(index + 1,
								jndex - 1) != EMPTY)
						&& (this->game_board_->getCellValue(index + 1,
								jndex - 1) != value)
						&& (this->playDirection(index + 1, jndex - 1, 1, -1,
								value, true))) {
					Point * p = new Point(index, jndex);
					moves_list->push_back(p);
					// 	Check down right
				} else if ((this->game_board_->getCellValue(index - 1,
						jndex + 1) != BOEDER)
						&& (this->game_board_->getCellValue(index - 1,
								jndex + 1) != EMPTY)
						&& (this->game_board_->getCellValue(index - 1,
								jndex + 1) != value)
						&& (this->playDirection(index - 1, jndex + 1, -1, 1,
								value, true))) {
					Point * p = new Point(index, jndex);
					moves_list->push_back(p);
					// 	Check down left
				} else if ((this->game_board_->getCellValue(index - 1,
						jndex - 1) != BOEDER)
						&& (this->game_board_->getCellValue(index - 1,
								jndex - 1) != EMPTY)
						&& (this->game_board_->getCellValue(index - 1,
								jndex - 1) != value)
						&& (this->playDirection(index - 1, jndex - 1, -1, -1,
								value, true))) {
					Point * p = new Point(index, jndex);
					moves_list->push_back(p);
				}
			}
		}
	}
	return moves_list;
}

Board * ClassicLogic::getBoard() {
	return this->game_board_;
}

Board * ClassicLogic::swapBoard(Board * board) {
	Board * temp = this->game_board_;
	this->game_board_ = board;
	return temp;
}
