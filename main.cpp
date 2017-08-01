#include <iostream>
#include <string>
#include "SudokuBoard.h"
using namespace std;

main(){
	SudokuBoard board;
	board.clearBoard();
	board.printBoard();
	board.setBoard();
	board.printBoard();
}