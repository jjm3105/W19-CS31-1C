#include <iostream>
using namespace std;


bool translate(string& str)
{
	int count = 0;

	for (int i = 0; i < str.size(); i++) {
		if (isalpha(str[i])) {
			str[i] = toupper(str[i]);

			if (str[i] < 'M') {
				str[i] = '0';
			}
			else {
				str[i] = '1';
				count++;
			}
		}
	}

	if (count % 2 == 1)
		return true;
	
	return false;
}

int main()
{
	string s = "CS is the best"; 
	string f = "CS31 Winter 19";
	cout << translate(s) << endl;
	cout << s << endl;
	cout << translate(f) << endl;
	cout << f << endl;
}