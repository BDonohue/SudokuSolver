#include "SudokuBoard.h"
#include <iostream>
using namespace std;

SudokuBoard::SudokuBoard(){
	setBoard();
}

void SudokuBoard::clearBoard(){
	for(int i = 0; i < 9; i++){
		for(int j = 0; j < 9; j++){
			board[i][j] = 0;
		}
	}
}

void SudokuBoard::printBoard(){
	for(int i = 0; i < 9; i++){
		if(i % 3 == 0){
			cout << " ----------------- " << endl;
		}
		for(int j = 0; j < 9; j++){
			if(j % 3 == 0){
				cout << "|";
			} else {
				cout << " ";
			}
			if(board[i][j] == 0){
				cout << " ";
			} else {
				cout << board[i][j];
			}
		}
		cout << "|" << endl;
	}
	cout << " ----------------- " << endl;
}

void SudokuBoard::setBoard(){
	board[0][0] = 5;
	board[0][1] = 3;
	board[0][3] = 6;
	board[0][5] = 2;
	board[0][6] = 8;
	board[0][7] = 9;

	board[1][0] = 6;
	board[1][2] = 9;
	board[1][5] = 7;
	board[1][7] = 2;

	board[2][0] = 8;

	board[3][2] = 2;
	board[3][3] = 1;
	board[3][6] = 7;
	board[3][7] = 8;

	board[4][0] = 7;
	board[4][2] = 5;
	board[4][3] = 9;
	board[4][5] = 3;
	board[4][6] = 6;
	board[4][8] = 4;

	board[5][6] = 3;

	board[6][0] = 4;
	board[6][3] = 2;
	board[6][5] = 1;
	board[6][6] = 9;

	board[7][2] = 1;
	board[7][3] = 4;
	board[7][5] = 6;
	board[7][7] = 3;
	board[7][8] = 8;
	
	board[8][1] = 7;
	board[8][2] = 3;
	board[8][3] = 5;
	board[8][5] = 8;
	board[8][7] = 6;
}