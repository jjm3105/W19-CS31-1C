#include <iostream>
#include <string> // not necessary
using namespace std;

int main()
{
	string dessert = "";
	string topping = "";
	string price = "";

	cout << "Ice Cream or Gelato? ";
	getline(cin, dessert);
	cout << "Syrup, Oreos, or Grapes? ";
	getline(cin, topping);

	if (dessert == "Ice Cream") {
		if (topping == "Syrup") {
			price = "4.95";
		}
		else if (topping == "Oreos") {
			price = "2.18";
		}
		else if (topping == "Grapes") {
			price = "10.25";
		}
		else {
			cout << "That topping is not on the menu." << endl;
			return 0;
		}
	}
	else if (dessert == "Gelato") {
		if (topping == "Syrup") {
			price = "3.99";
		}
		else if (topping == "Oreos") {
			price = "5.99";
		}
		else if (topping == "Grapes") {
			price = "12.99";
		}
		else {
			cout << "That topping is not on the menu." << endl;
			return 0;
		}
	}
	else {
		cout << "That dessert is not on the menu." << endl;
		return 0;
	}

	cout << "Thank you for coming to Howard's Cold Comforts. That will be $" << price << "." << endl; 
}
