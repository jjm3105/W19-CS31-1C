#include <iostream>
#include "BigThree.h"
using namespace std;

// Write your other functions here:


BigThree::BigThree() {
	
}

BigThree::~BigThree() {

}

bool BigThree::placePiece(int r, int c) {

}

bool BigThree::isOTurn() {

}

char BigThree::getWinner() {

}

void BigThree::clear() {
	
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
