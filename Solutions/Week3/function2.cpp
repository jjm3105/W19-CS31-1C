#include<iostream>
using namespace std;


bool Palindrome(int x, int y)
{
	int reverse = 0;

	while (x > 0)
	{
		reverse *= 10;
		reverse += x % 10;
		x /= 10;
	}

	return reverse == y;
}

int main()
{
	if (Palindrome(625, 526))
		cout << "True" << endl;
	else
		cout << "False" << endl;
}