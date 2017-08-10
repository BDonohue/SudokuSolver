#include <iostream>
#include <string>
#include "SudokuBoard.h"
using namespace std;



main(){
	SudokuBoard board;
	board.clearBoard();
	board.setBoard();
	board.printBoard();
	board.setPrediction();

}
