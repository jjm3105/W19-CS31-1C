#include<iostream>
using namespace std;

int main()
{
	int first, second;
	string command;
	int result;

	cout << "Enter your first number: ";
	cin >> first;
	cout << "Enter your second number: ";
	cin >> second;
	cout << "Enter your command: ";
	cin.ignore(10000, '\n');
	getline(cin, command);

	if (command == "Add") {
		result = first + second;
	}
	else if (command == "Subtract") {
		result = first - second;
	}
	else if (command == "Multiply") {
		result = first * second;
	}
	else if (command == "Divide") {
		result = first / second;
	}
	else {
		cout << "Error! Please enter a valid command." << endl;
		return 0;
	}

	cout << "Result: " << result << endl;
}