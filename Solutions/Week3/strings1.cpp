#include<iostream>
using namespace std;

int main()
{
	string s = "";
	cout << "Input: ";
	getline(cin, s);

	int count = 0;

	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '(')
			count++;
		else if (s[i] == ')')
			count--;
	}

	for (int i = 0; i < count; i++)
	{
		cout << ")";
	}

	cout << endl;
}