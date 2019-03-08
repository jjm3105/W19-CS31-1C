#include <iostream>
#include "TicTacToe.h"
#include "BigThree.h"
using namespace std;


bool PlayGame(int& num, int& OWins, int& XWins) {
	BigThree Game;
	Game.display();
	num++;

	string input;
	int row, column;
	bool quit = false;

	while (Game.getWinner() == '?') {
		if (Game.isOTurn())
			cout << "It is O's Turn!" << endl;
		else
			cout << "It is X's Turn!" << endl;
		
		cout << "Input row and column: ";
		getline(cin, input);

		if (input == "quit") {
			quit = true;
			break;
		}

		if (input.size() != 2) {
			cout << "Please input as {row}{column}. Ex: 11" << endl;
			continue;
		}
		
		row = input[0] - '0';
		column = input[1] - '0';

		bool valid = Game.placePiece(row, column);

		Game.display();
		if (!valid)
			cout << "invalid position!" << endl;
	}

	if (Game.getWinner() == 'O') {
		OWins++;
		cout << "Player O won!" << endl;
	}
	else if (Game.getWinner() == 'X') {
		XWins++;
		cout << "Player X won!" << endl;	
	}
	else if (Game.getWinner() == '=') {	
		cout << "It's a draw!" << endl;
	}
	else if (quit){
		char winner, loser;
		if (Game.isOTurn()) {
			XWins++;
			winner = 'X';
			loser = 'O';
		}
		else {
			OWins++;
			winner = 'O';
			loser = 'X';
		}
		cout << "Player " << loser << " resigned. Player "
			 << winner << " won the game." << endl;
	}
	else {
		cout << "Error! Game should be still going!" << endl;
	}

	cout << endl;
	cout << "Continue? (y/n) ";

	while (1) {
		string cont_game;
		getline(cin, cont_game);

		if (cont_game == "y")
			return true;
		else if (cont_game == "n")
			return false;
		else
			cout << "Please write (y/n) ";
	}
}



int main()
{
	bool cont = true;
	int num = 0, OWins = 0, XWins = 0;

	while (cont) {
		cont = PlayGame(num, OWins, XWins);
	}

	cout << endl;
	cout << "Player O: " << OWins << endl;
	cout << "Player X: " << XWins << endl;

	if (OWins == XWins)
		cout << "It's an overall draw!" << endl;
	else if (OWins > XWins)
		cout << "Player O wins!" << endl;
	else
		cout << "Player X wins!" << endl;

	cout << endl;
	cout << "Thank you for playing!" << endl;
}
