/*
 * AIPlayer.cpp
 *
 *  Created on: Nov 27, 2017
 *      Author: shomps
 */

#include "AIPlayer.h"
#include <iostream>
#include <limits>
#include <math.h>

AIPlayer::AIPlayer(CellValue value, GameLogic * logic, int width) {
	this->value_ = value;
	if(this->value_== WHITE) {
		this->opp_value_= BLACK;
	} else {
		this->opp_value_ = WHITE;
	}

	this->display_ = new ConsuleDisplay();
	this->game_ = new Board(width);
	this->logic_ = logic;
}

Point AIPlayer::move(vector<Point*>* moves, Point last_move) {
	//define opponent's color
	CellValue opponent;
	opponent = (this->value_ == WHITE) ? BLACK : WHITE;
	//play last turn
	logic_->playMove(last_move, opponent);
	//set bookmark values
	Point bestMove(0,0);
	int minScore = (int) pow(this->game_->getGameBoardWidth(), 2);

	vector<Point*>::iterator m = moves->begin();

	for (; m != moves->end(); m++) {
		//copy actual board to save current state
		Board * tem = game_->copyBoard();
		//replace actual board with tem, hold actual
		Board * hold = this->logic_->swapBoard(tem);
		//simulate turn:
		//change operable board
		Point point(0,0);

		logic_->playMove(point, this->value_);
		//get opponent's possible moves
		vector<Point*> * opMoves = logic_->getLegalMoves(this->opp_value_);
		//our best possible score
		int maxScore = -(int) pow(this->game_->getGameBoardWidth(), 2);

		vector<Point*>::iterator n = opMoves->begin();

		for (; n != opMoves->end(); n++) {
			//replace operable board with temmie, hold temp on bold
			Board * temmie = tem->copyBoard();
			Board * bold = this->logic_->swapBoard(tem);

			Point p((*n)->getX(),(*n)->getY());

			logic_->playMove(p, opponent);
			int score = (logic_->getBoard()->getBlackCellsNumber())
					- (logic_->getBoard()->getWhiteCellsNumber());
			if (score > maxScore) {
				maxScore = score;
			}
			//delete temmie
			Board * goner = this->logic_->swapBoard(temmie);
			delete(goner);
		}
		delete(opMoves);
		if (maxScore < minScore) {
			minScore = maxScore;
			bestMove.setX((*m)->getX());
			bestMove.setY((*m)->getY());
		}
		Board * goner = this->logic_->swapBoard(hold);
		delete(goner);
	}
	Point ret(bestMove.getX(), bestMove.getY());
	delete(moves);
	return ret;
}

CellValue AIPlayer::getValue() const {
	return this->value_;
}

void AIPlayer::setBoard(Board* board) {
	this->game_ = board;
}

AIPlayer::~AIPlayer() {
}
