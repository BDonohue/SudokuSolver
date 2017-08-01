class SudokuBoard{
	public:
		explicit SudokuBoard();
		void clearBoard();
		void printBoard();
		void setBoard();
	private:
		int board[9][9];
};