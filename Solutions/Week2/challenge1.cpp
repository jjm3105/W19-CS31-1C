#include<iostream>
using namespace std;

int main()
{
	int first, second;

	cout << "Enter the frist time: ";
	cin >> first;
	cout << "Enter the second time: ";
	cin >> second;

	int hr_diff = (second - first);
	int hour = (hr_diff + 2400) % 2400;
	hour /= 100;

	int min_diff = (second % 100) - (first % 100);
	int mins = (min_diff + 60) % 60;

	cout << hour << " hours and " << mins << " minutes." << endl;
}