#include <iostream>
#include <string>
using namespace std;


int largest(int x, int y, int z)
{
	if (x > y) {
		if (x > z)
			return x;
		else
			return z;
	}
	else {
		if (y > z)
			return y;
		else
			return z;
	}
}

int main()
{
	cout << largest(3, 7, 3) << endl;
	cout << largest(8, 4, 8) << endl;
}
