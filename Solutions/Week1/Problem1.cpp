#include<iostream>
using namespace std;

int main()
{
	double one, two, three;
	double result;

	cout << "Number: ";
	cin >> one;
	cout << "Number: ";
	cin >> two;
	cout << "Number: ";
	cin >> three;

	result = (one + two + three)/3;

	cout << "The average is " << result << "!" << endl;
}