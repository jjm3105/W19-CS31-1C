#include <iostream>
using namespace std;

void eraseChar(char str[], char c) {
	int x = 0;

	while (str[x] != '\0') {
		if (str[x] == c) {
			for (int y = x; str[y] != '\0'; y++) {
				str[y] = str[y + 1];
			}
		}
	else
		x++;
	}
}

int main()
{
	char cstring[8] = "account";
	eraseChar(cstring, 'c');
	cout << cstring << endl;
}
