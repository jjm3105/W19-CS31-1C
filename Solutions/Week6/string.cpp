#include <iostream>
#include <string>
using namespace std;

int pivot(string array[], int size, string pole)
{
	int ind = 0;
	int cur = 0;
	int count = 0;

	while (ind < size)
	{
		if (array[ind] < pole)
		{
			// switch
			string temp = array[cur];
			array[cur] = array[ind];
			array[ind] = temp;

			count++;
			cur++;
		}

		ind++;
	}

	return count;
}

void printArray(string array[], int size)
{
	for (int i = 0; i < size; i++)
		cout << array[i] << ", ";
	cout << endl;
}

int main()
{
	string capitals[8] = {
			"Montgomery", "Phoenix", "Denver", "Tallahassee",
			"Honolulu", "Springfield", "Santa Fe", "Columbus"
		};
	cout << pivot(capitals, 5, "Madison") << endl;
	printArray(capitals, 5);
}