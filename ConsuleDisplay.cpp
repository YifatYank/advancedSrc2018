/**
 * Name : Yifat Yankocivh
 * ID	: 204709224
 * User Name : yankovy
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

ConsuleDisplay::~ConsuleDisplay(){}
