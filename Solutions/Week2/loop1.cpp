#include<iostream>
using namespace std;

int main()
{
	int N;

	cout << "Give a number: ";
	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		if (i % 3 == 0)
			cout << i << endl;
	}

	cout << "Finish." << endl;
}