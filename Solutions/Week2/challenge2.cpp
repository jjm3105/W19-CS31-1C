#include <iostream>
using namespace std;

int main()
{
	int N = 0;
	cout << "Number? ";
	cin >> N;

	int curr = 0;
	int next = 1;
	for (int i = 0; i < N; i++)
	{
		int temp = curr + next;
		curr = next;
		next = temp;
	}

	cout << curr << endl;
}