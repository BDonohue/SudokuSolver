#include "SudokuBoard.h"
#include <stdio.h>
#include <math.h>
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

void SudokuBoard::setPrediction(){
	for(int i = 0; i < 9; i++){
		for(int j = 0; j < 9; j++){
			//If a board space already has a number, no point in checking for it
			if(board[i][j] == 0){
				//Make everything possible
				for(int k = 0; k < 10; k++){
					boardPrediction[i][j][k] = 1;
				}
				//Check Rows
				for(int k = 0; k < 9; k++){
					if(board[i][k]){
						boardPrediction[i][j][board[i][k]] = 0;
					}
				}
				//Check Columns
				for(int k = 0; k < 9; k++){
					if(board[k][j]){
						boardPrediction[i][j][board[k][j]] = 0;	
					}
				}
				//Check Boxes
				/*
				for(int k = 0; k < 9; k++){
					if(board[i+k%3][j+((k/3)*9)]){
						boardPrediction[i][j][board[i+k%3][j+((k/3)*9)]] = 0;
					}	
				}
				*/
			} else {
				boardPrediction[i][j][0] = 0;
			}
		}
	}

	for(int k = 0; k < 10; k++){
		cout << k << endl << endl;
		for(int i = 0; i < 9; i++){
			for(int j = 0; j < 9; j++){
				if(board[i][j] == 0){
					cout << boardPrediction[i][j][k] << " ";
				} else {
					cout << "  ";
				}
			}
			cout << endl;
		}
		cout << endl << endl << endl;
	}
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