#include<iostream>
#include<string>
using namespace std;

string lookAndSay(string number)
{
	string ans = "";

	for (int i = 0; i < number.size(); i += 2)
	{
		int num = number[i] - '0';
		char digit = number[i+1];

		for (int j = 0; j < num; j++)
		{
			ans += digit;
		}
	}

	return ans;
}

int lookAndSay(int number)
{
	int ans = 0;
	int pow = 1;

	while (number > 0)
	{
		int digit = number % 10;
		number /= 10;
		int num = number % 10;
		number /= 10;

		for (int i = 0; i < num; i++)
		{
			ans += digit * pow;
			pow *= 10;
		}
	}

	return ans;
}

int main()
{
	cout << lookAndSay(311322) << endl;
	cout << lookAndSay("311322") << endl;
}