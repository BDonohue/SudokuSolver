class SudokuBoard{
	public:
		explicit SudokuBoard();
		void clearBoard();				//initiate board with 0's
		void setBoard();				//add board with sample sudoku puzzle
		void printBoard();				//print board to screen
		void setPrediction();			//set up Predictions
		void usePrediction();			//Any predictions that have only 1 number can go
	private:
		long board[9][9];				//official board
		long boardPrediction[9][9][10];	//numbers that could potentially be on there
		//How to store board predictions:
		//Number if possible is # * 10^#
		//If a 3 is possible, then the number has a 3000 or 3 * 10 ^ 3
		//So 9,876,543,210 means that every number is possible on said space
};