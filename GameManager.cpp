/*
 * GameManager.cpp
 *
 *  Created on: Nov 27, 2017
 *      Author: yifat
 */

#include "GameManager.h"
#include "ConsolePlayer.h"
#include "ClassicLogic.h"

GameManager::GameManager(Player * white, Player * black, int width){
	this->white_= white;
	this->black_= black;
	this->game_board_ = new Board(width);
	this->logic_= new ClassicLogic(this->game_board_, this->white_, this->black_);
	this->display_ = new ConsuleDisplay();
	this->winner_ = EMPTY;
}

GameManager::~GameManager() {
	delete(this->game_board_);
}

void GameManager::play() {
	bool is_running = true;
	Point p(-1,-1);
	while(is_running) {
		bool is_valid_move = false, has_played;

		// Play white player.
		// Get all the possible moves for the white player.
		vector<Point *> * moves = this->logic_->getLegalMoves(this->white_->getValue());

		// If the white player does not have legal moves.
		if(moves->size() == 0) {
			has_played = false;
			if(this->game_board_->getEmptyCellsNumber() != 0) {
				this->white_->move(moves,p);
			}
		} else {
			Point p(0,0);
			has_played = true;
			is_valid_move = false;
			while(!is_valid_move) {
				p = this->white_->move(moves,p);
				is_valid_move = this->logic_->playMove(p, this->white_->getValue());

				// If the user has enter an in valid move.
				// Get the list of possible moves, again.
				if(!is_valid_move){
					moves = this->logic_->getLegalMoves(this->white_->getValue());
				}
			}
	//
		}

		// Play Black player.
		// Get all the possible moves for the black player.
		moves = this->logic_->getLegalMoves(this->black_->getValue());

		// If the black player does not have legal moves.
		if(moves->size() == 0) {
			if(this->game_board_->getEmptyCellsNumber() != 0) {
				this->black_->move(moves,p);
			}
			// If the white player does not have legal moves as well.
			if(!has_played) {
				is_running = false;
			}
		} else {
			is_valid_move = false;
			while(!is_valid_move) {
				p = this->black_->move(moves,p);
				is_valid_move = this->logic_->playMove(p, this->black_->getValue());

				// If the user has enter an in valid move.
				// Get the list of possible moves, again.
				if(!is_valid_move) {
					moves = this->logic_->getLegalMoves(this->black_->getValue());
				}
			}
		}
	}

	const Board &holder = (*this->game_board_);
	this->display_->Display(holder);
	if(this->game_board_->getWhiteCellsNumber() > this->game_board_->getBlackCellsNumber()) {
		this->winner_ = this->white_->getValue();
		//cout << "Player O has won!" << endl;
	} else {
		this->winner_ = this->black_->getValue();
		//cout << "Player X has won!" << endl;
	}
}

CellValue GameManager::getWinner() {
	return this->winner_;
}