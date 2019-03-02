#ifndef TICTACTOE
#define TICTACTOE

const int MAX_SIZE = 3;

class TicTacToe
{
public:
	TicTacToe();
	bool placePiece(int r, int c);
	bool isOTurn();
	char getWinner();
	void clear();
	void display();
private:
	char updateWinner();
	char board[MAX_SIZE][MAX_SIZE];
	char winner;
	bool Oturn;
};

#endif