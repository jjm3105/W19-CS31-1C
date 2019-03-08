#ifndef TICTACTOE
#define TICTACTOE

const int MAX_SIZE = 3;

class TicTacToe
{
public:
	TicTacToe();
	bool placePiece(int r, int c, bool OTurn);
	char getWinner();
	void clear();
	void display(int row);
private:
	char updateWinner();
	char board[MAX_SIZE][MAX_SIZE];
	char winner;
};

#endif
