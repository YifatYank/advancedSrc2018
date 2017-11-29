/**
 * Names       : Yifat Yankocivh
 * 				 Shoham Bar-Gad
 * IDs	       : 204709224
 * 				 315706614
 * User Names  : yankovy
 * 				 bagnosh
 *
 * Class Name  : ConsuleDisplay.cpp
 * Description : Implements the methods used to display
 * 				 the surface of the game on the console.
 */

#include "ConsuleDisplay.h"
#include <iostream>
using namespace std;

ConsuleDisplay::ConsuleDisplay(){}

void ConsuleDisplay::Display(const Board &bord){
	int index, jndex;

	cout << " |";
	for(index = 1; index <= bord.getGameBoardWidth(); ++index) {
		cout << " " << index << " |";
	}

	cout << endl;

	cout << "--";
	for(int i = 0; i< bord.getGameBoardWidth(); ++i){
		cout << "----";
	}
	cout << endl;

	for(index = 1; index <= bord.getGameBoardWidth(); ++index) {
		cout << index << "|";
		for(jndex = 1; jndex <= bord.getGameBoardWidth(); ++ jndex) {
			switch(bord.getCellValue(index, jndex)) {
				case(EMPTY): {
					cout << "   |";
					break;
				} case(WHITE): {
					cout << " O |";
					break;
				} case(BLACK): {
					cout << " X |";
					break;
				} default: {
					break;
				}
			}
		}
		cout << endl;
		cout << "--";
		for(int i = 0; i< bord.getGameBoardWidth(); ++i){
			cout << "----";
		}
		cout << endl;
	}
}

GameType ConsuleDisplay::DisplayOpenMenu() {
	char c;
	cout << "Which type of game would you like to play?" << endl;
	cout << "Wanna play against computer? (type c)" << endl;
	cout << "Wanna play against a friend? (type t)" << endl;
	cin >> &c;

	if(c == 't'){
		return TWO_PLAYERS;
	} else {
		return AGAINST_COMPUTER;
	}

	return TWO_PLAYERS;
}

ConsuleDisplay::~ConsuleDisplay(){}
