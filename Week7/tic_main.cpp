#include <iostream>
#include "TicTacToe.cpp"
using namespace std;

int main() {
	TicTacToe game;
	game.display();

	string input;
	int row, column;

	while (game.getWinner() == '?') {
		cout << "Input row and column: ";
		getline(cin, input);
		if (input.size() != 2) {
			cout << "Please input as {row}{column}. Ex: 11" << endl;
			continue;
		}
		row = input[0] - '0';
		column = input[1] - '0';

		if (!game.placePiece(row, column))
			cout << "invalid position!" << endl;

		game.display();
	}

	if (game.getWinner() == 'O') {
		cout << "Player 1 won!" << endl;
	}
	else if (game.getWinner() == 'X') {
		cout << "Player 2 won!" << endl;	
	}
	else {	
		cout << "It's a draw!" << endl;
	}
}