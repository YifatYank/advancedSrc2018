/**
 * Name : Yifat Yankocivh
 * ID	: 204709224
 * User Name : yankovy
 */

#include "ConsolePlayer.h"
#include <iostream>
#include <limits>

ConsolePlayer::ConsolePlayer(CellValue cell_value): value_(cell_value) {
	this->display_ = new ConsuleDisplay();
	this->game_ = NULL;
}

Point ConsolePlayer::move(vector<Point *> * moves, Point opponent_move){
	int x_choise, y_choise;
	bool is_valid = false;

	Board &borad_holder = (*this->game_);
	this->display_->Display(borad_holder);

	if (this->value_ == WHITE){
		cout << "O It's your move." << endl;
	} else {
		cout << "X It's your move." << endl;
	}

	if(moves->size() == 0){
		delete(moves);
		cout << "No possible moves, play passes back to the other player." << endl;
		Point p(0,0);
		return p;
	}

	while(!is_valid) {
		cout << "Your possible moves: ";

		vector<Point *>::iterator it = moves->begin();

		cout << "(" << (*it)->getX() << "," << (*it)->getY() << ")";
		it++;
		for(;it!=moves->end(); it++){
			cout << ",(" << (*it)->getX() << "," << (*it)->getY() << ")";
		}
		cout << endl;

		cout << endl << "Please enter your move row,col:" << endl;
		cin >> x_choise >> y_choise;

		if(!x_choise || !y_choise) {
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
		}
		// Checks if the move the user chose is valid.
		for(it = moves->begin();
				it!=moves->end(); it++) {
			if((*it)->getX() == x_choise && (*it)->getY() == y_choise) {
				is_valid = true;
				break;
			}
		}
		if(!is_valid){
			cout << "Your choise is not valid, please enter a valid choise." << endl << endl;
		}
	}

	// free the points vector
	while(moves->size() != 0){
		Point * p = moves->back();
		moves->pop_back();
		delete(p);
	}

	delete(moves);

	Point p(0,0);
	p.setX(x_choise);
	p.setY(y_choise);
	return p;
}

ConsolePlayer::~ConsolePlayer() {
	delete(this->display_);
}

CellValue ConsolePlayer::getValue () const{
	return this->value_;
}

void ConsolePlayer::setBoard(Board * board) {
	this->game_ = board;
}
