#include <iostream>
#include <string>
#include <stdio.h>
#include <math.h>
#include "SudokuBoard.h"
using namespace std;

main(){

	cout << "i   1 2 3 4 5 6 7 8 9 " << endl;
	for(int i = 0; i < 512; i++){
		cout << i << "   ";
		for(int j = 0; j < 9; j++){
			cout << (i / ((int)(pow(2,j))))%2 << " ";
		}
		cout << endl;
		//cout << i << "   " << (i / 16)%2 << endl;


		//<< "     " << i % 16 << "     " << i / 16 << "     " << i / 16 + i % 16 << endl;
	}

	/*
	SudokuBoard board;
	board.clearBoard();
	board.setBoard();
	board.printBoard();
	board.setPrediction();
	*/
}