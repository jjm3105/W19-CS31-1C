#include <iostream>
#include "BigThree.h"
using namespace std;

BigThree::BigThree() {
	for (int i = 0; i < BIG_MAX_SIZE; i++)
		boards[i] = new TicTacToe;
	clear();
}

BigThree::~BigThree() {
	for (int i = 0; i < BIG_MAX_SIZE; i++)
		delete boards[i];
}

bool BigThree::placePiece(int r, int c) {
	if (winner != '?')
		return false;

	if (!boards[boardPos]->placePiece(r, c, OTurn))
		return false;

	OTurn = !OTurn;

	winner = updateWinner();

	int temp = 3*(r-1) + (c-1);
	
	if (boards[temp]->getWinner() != '?') {
		if (boards[boardPos]->getWinner() != '?')
			boardPos = firstOpen();
	}
	else
		boardPos = temp;

	return true;
}

bool BigThree::isOTurn() {
	return OTurn;
}

char BigThree::getWinner() {
	return winner;
}

void BigThree::clear() {
	for (int i = 0; i < BIG_MAX_SIZE; i++)
		boards[i]->clear();
	boardPos = 4;
	OTurn = true;
	winner = '?';
}

void BigThree::display() {
	cout << endl;
	for (int i = 0; i < MAX_SIZE; i++) {
		for (int j = 0; j < MAX_SIZE; j++) {
			for (int k = 0; k < MAX_SIZE; k++) {
				int pos = 3*i + k;
				if (boards[pos]->getWinner() == 'O')
					cout << OWIN[j];
				else if (boards[pos]->getWinner() == 'X')
					cout << XWIN[j];
				else if (boards[pos]->getWinner() == '=')
					cout << DRAW[j];
				else
					boards[pos]->display(j);

				if (pos == boardPos) {
					if (pos == 2 || pos == 5 || pos == 8)
						continue;
					cout << "|";
				}
				else if (pos == (boardPos - 1)) {
					if (pos == 2 || pos == 5 || pos == 8)
						continue;
					cout << "|";
				}
				else
					cout << " ";
			}
			cout << endl;
		}
		if (i == 0) {
			switch (boardPos) {
				case 0: cout << "¯¯¯        " << endl; break;
				case 3: cout << "___        " << endl; break;
				case 1: cout << "    ¯¯¯    " << endl; break;
				case 4: cout << "    ___    " << endl; break;
				case 2: cout << "        ¯¯¯" << endl; break;
				case 5: cout << "        ___" << endl; break;
				default: cout << endl;
			}
		}
		else if (i == 1) {
			switch (boardPos) {
				case 3: cout << "¯¯¯        " << endl; break;
				case 6: cout << "___        " << endl; break;
				case 4: cout << "    ¯¯¯    " << endl; break;
				case 7: cout << "    ___    " << endl; break;
				case 5: cout << "        ¯¯¯" << endl; break;
				case 8: cout << "        ___" << endl; break;
				default: cout << endl;
			}
		}
		else
			cout << endl;
	}
}

char BigThree::updateWinner() {
	// Check row
	for (int i = 0; i < MAX_SIZE; i++) {
		if (boards[3*i + 0]->getWinner() == boards[3*i + 1]->getWinner())
			if (boards[3*i + 1]->getWinner() == boards[3*i + 2]->getWinner()) {
				char pos = boards[3*i + 0]->getWinner();
				if (pos == 'O' || pos == 'X')
					return pos;
			}
	}
	// Check column
	for (int i = 0; i < MAX_SIZE; i++) {
		if (boards[0*3 + i]->getWinner() == boards[1*3 + i]->getWinner())
			if (boards [1*3 + i]->getWinner() == boards[2*3 + i]->getWinner()) {
				char pos = boards[0*3 + i]->getWinner();
				if (pos == 'O' || pos == 'X')
					return pos;
			}
	}
	// Check diagonal
	if (boards[0]->getWinner() == boards[4]->getWinner())
		if (boards [4]->getWinner() == boards[8]->getWinner()) {
			char pos = boards[0]->getWinner();
			if (pos == 'O' || pos == 'X')
				return pos;
		}
	if (boards[2]->getWinner() == boards[4]->getWinner())
		if (boards [4]->getWinner() == boards[6]->getWinner()) {
			char pos = boards[2]->getWinner();
			if (pos == 'O' || pos == 'X')
				return pos;
		}

	for (int i = 0; i < BIG_MAX_SIZE; i++) {
		if (boards[i]->getWinner() == '?')
			return '?';
	}

	return '=';
}

int BigThree::firstOpen() {
	for (int i = 0; i < BIG_MAX_SIZE; i++) {
		if (boards[i]->getWinner() == '?')
			return i;
	}
	return -1;
}