#ifndef BIGTHREE
#define BIGTHREE

#include "TicTacToe.h"

const int BIG_MAX_SIZE = 9;
const std::string OWIN[MAX_SIZE] = { "/¯\\", "| |", "\\_/" };
const std::string XWIN[MAX_SIZE] = { "\\ /", " X ", "/ \\" };
const std::string DRAW[MAX_SIZE] = { "___", "   ", "¯¯¯" };

class BigThree
{
public:
	BigThree();
	~BigThree();
	bool placePiece(int r, int c);
	bool isOTurn();
	char getWinner();
	void clear();
	void display();
private:
	TicTacToe* boards[BIG_MAX_SIZE];
	int boardPos;	
};

#endif
