#include <iostream>
#include "TicTacToe.h"
using namespace std;

TicTacToe::TicTacToe() {
	clear();
}

bool TicTacToe::placePiece(int r, int c, bool OTurn) {
	if (winner != '?')
		return false;

	if (r > MAX_SIZE || r < 1)
		return false;
	if (c > MAX_SIZE || c < 1)
		return false;
	if (board[r-1][c-1] != '.')
		return false;

	char place = 'O';
	if (!OTurn)
		place = 'X';
	
	board[r-1][c-1] = place;
	OTurn = !OTurn;

	winner = updateWinner();

	return true;
}

char TicTacToe::getWinner() {
	return winner;
}

void TicTacToe::clear() {
	for (int i = 0; i < MAX_SIZE; i++) {
		for (int j = 0; j < MAX_SIZE; j++) {
			board[i][j] = '.';
		}
	}
	winner = '?';
}

void TicTacToe::display(int row) {
	for (int j = 0; j < MAX_SIZE; j++) {
		cout << board[row][j];
	}
}

char TicTacToe::updateWinner() {
	// Check row
	for (int i = 0; i < MAX_SIZE; i++) {
		if (board[i][0] == board[i][1])
			if (board[i][1] == board[i][2]) {
				char pos = board[i][0];
				if (pos == 'O' || pos == 'X')
					return pos;
			}
	}
	// Check column
	for (int i = 0; i < MAX_SIZE; i++) {
		if (board[0][i] == board[1][i])
			if (board [1][i] == board[2][i]) {
				char pos = board[0][i];
				if (pos == 'O' || pos == 'X')
					return pos;
			}
	}
	// Check diagonal
	if (board[0][0] == board[1][1])
		if (board [1][1] == board[2][2]) {
			char pos = board[0][0];
			if (pos == 'O' || pos == 'X')
				return pos;
		}
	if (board[0][2] == board[1][1])
		if (board [1][1] == board[2][0]) {
			char pos = board[0][2];
			if (pos == 'O' || pos == 'X')
				return pos;
		}

	for (int i = 0; i < MAX_SIZE; i++) {
		for (int j = 0; j < MAX_SIZE; j++) {
			if (board[i][j] == '.')
				return '?';
		}
	}

	return '=';
}