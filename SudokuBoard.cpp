#include "SudokuBoard.h"
#include <stdio.h>
#include <math.h>
#include <iostream>
using namespace std;

bool checkNumber(int value, int numToCheck);

SudokuBoard::SudokuBoard(){
	setBoard();
}

void SudokuBoard::clearBoard(){
	for(int i = 0; i < 9; i++){
		for(int j = 0; j < 9; j++){
			board[i][j] = 0;
			boardPrediction[i][j] = 511;
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
	//loop through numbers to get rid of predictions
	int l, m;	//used to calculate which box to work in
	for(int i = 0; i < 9; i++){
		l = (i / 3) * 3;
		for(int j = 0; j < 9; j++){
			m = (j / 3) * 3;
			//Only go through spaces with numbers on it
			if(board[i][j]){
				for(int k = 0; k < 9; k++){
					//Eliminate Predictions in Row
					if(checkNumber(boardPrediction[i][k],board[i][j])){
						//cout << i << " " << j << "      " << i << " " << k << "      " << boardPrediction[i][k] << " " << pow(2,board[i][j] - 1) << " ";
						boardPrediction[i][k] -= pow(2,board[i][j] - 1);
						//cout << boardPrediction[i][k] << endl;
					} 
					//Eliminate Predictions in Column
					if(checkNumber(boardPrediction[k][j],board[i][j])){
						//cout << i << " " << j << "      " << k << " " << j << "      " << boardPrediction[k][j] << " " << pow(2,board[i][j] - 1) << " ";
						boardPrediction[k][j] -= pow(2,board[i][j] - 1);
						//cout << boardPrediction[k][j] << endl;
					} 
					/*
					//Eliminate Predictions in Boxes
					if(checkNumber(boardPrediction[l+k/3][m+k%3],board[i][j])){
						boardPrediction[l+k/3][m+k%3] -= pow(2,board[i][j]);	
					}
					*/
				}
			}
		}
	}

	for(int i = 0; i < 9; i++){
		for(int j = 0; j < 9; j++){
			if(!board[i][j]){
				cout << boardPrediction[i][j] << "     ";
			} else {
				cout << "      ";
			}

		}
		cout << endl;
	}
	/*
	int l, m;
	for(int i = 0; i < 9; i++){
		for(int j = 0; j < 9; j++){
			//If a board space already has a number, no point in checking for it
			if(board[i][j] == 0){
				boardPrediction[i][j][0] = 9;
				//Make everything possible
				for(int k = 1; k < 10; k++){
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
				l = (i / 3) * 3;
				m = (j / 3) * 3;
				for(int k = 0; k < 9; k++){
					if(board[l+k/3][m+k%3]){
						boardPrediction[i][j][board[l+k/3][m+k%3]] = 0;
					}	
				}
			} else {
				boardPrediction[i][j][0] = 0;
			}
		}
	}

	for(int i = 0; i < 9; i++){
		for(int j = 0; j < 9; j++){
			if(boardPrediction[i][j][0]){
				for(int k = 1; k < 10; k++){
					if(!boardPrediction[i][j][k]){
						boardPrediction[i][j][0]--;
					}
				}
			}
		}
	}
	*/
	/*
	for(int k = 1; k < 10; k++){
		cout << k << endl << endl;
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
					cout << boardPrediction[i][j][k];
				} else {
					cout << " ";
				}
			}
			cout << "|" << endl;
		}
		cout << " ----------------- " << endl;
		cout << endl << endl << endl;
	}
	*/
}

void SudokuBoard::usePrediction(){
	/*
	//Check for slots that can only have one piece
	int numbersPossible;
	for(int i = 0; i < 9; i++){
		for(int j = 0; j < 9; j++){
			if(board[i][j] == 0){
				if(boardPrediction[i][j][0] == 1){
					cout << i << " " << j << endl;
					//REPLACE NUMBER
					//REDO PIECES
				}
			}
		}
	}
	
	for(int k = 1; k < 10; k++){
		//Check Columns
		for(int i = 0; i < 9; i++){
			for(int j = 0; j < 9; j++){
				if(boardPrediction[i][10][k] == 1){
					//Reduce It
				}
				if(boardPrediction[10][j][k] == 1){
					//Reduce it

				}
			}
		}
		//Check Rows
		//Check Tables
	}
	*/
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


bool checkNumber(int value, int numToCheck){
	return (value / ((int)(pow(2,numToCheck - 1)))) % 2;
}