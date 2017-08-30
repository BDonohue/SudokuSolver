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
						boardPrediction[i][k] -= pow(2,board[i][j] - 1);
					} 
					//Eliminate Predictions in Column
					if(checkNumber(boardPrediction[k][j],board[i][j])){
						boardPrediction[k][j] -= pow(2,board[i][j] - 1);
					} 
					
					//Eliminate Predictions in Boxes
					if(checkNumber(boardPrediction[l+k/3][m+k%3],board[i][j])){
						boardPrediction[l+k/3][m+k%3] -= pow(2,board[i][j] - 1);	
					}
					
				}
			}
		}
	}
}

void SudokuBoard::usePrediction(){
	for(int i = 0; i < 9; i++){
		for(int j = 0; j < 9; j++){
			if(!board[i][j]){
				//CHECK SPACES THAT HAVE ONLY ONE NUMBER AVAILABLE
				//If the number of ones is 2+, it will cancel out
				//If number Prediction is 0, and countOfOnes is still positive, we have found the correct prediction
				int countOfOnes = 2;
				int onePosition = 0;
				int numberPrediction = boardPrediction[i][j];
				while(countOfOnes){
					if(!numberPrediction){
						//cout << i << " " << j << " " << onePosition << endl;
						addNumber(i,j,onePosition);
						break;
					}
					countOfOnes -= numberPrediction % 2;
					numberPrediction = numberPrediction / 2;
					onePosition++;
				}
			}
		}
	}


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

	if(numbersFilled != 81){
		usePrediction();
	}
}

void SudokuBoard::addNumber(int i, int j, int number){
	board[i][j] = number;
	numbersFilled++;
	int l, m;	//used to calculate which box to work in
	l = (i / 3) * 3;
	m = (j / 3) * 3;
	for(int k = 0; k < 9; k++){
		//Eliminate Predictions in Row
		if(checkNumber(boardPrediction[i][k],board[i][j])){
			boardPrediction[i][k] -= pow(2,board[i][j] - 1);
		} 
		//Eliminate Predictions in Column
		if(checkNumber(boardPrediction[k][j],board[i][j])){
			boardPrediction[k][j] -= pow(2,board[i][j] - 1);
		} 
		//Eliminate Predictions in Boxes
		if(checkNumber(boardPrediction[l+k/3][m+k%3],board[i][j])){
			boardPrediction[l+k/3][m+k%3] -= pow(2,board[i][j] - 1);	
		}
	}
}

void SudokuBoard::setBoard(){
	numbersFilled = 36;

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