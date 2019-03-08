#include <iostream>
using namespace std;

void MergeAndSort(int* array_one, int* array_two, int N, int* merged)
{
	int index1 = 0, index2 = 0;
	for (int index = 0; index < 2*N; index++) {
		if (index1 > N) {
			merge[index] = array_two[index2];
			index2++;
		}	
		else if (index2 > N) {
			merge[index] = array_one[index1];
			index1++;
		}

		int one = array_one[index1];
		int two = array_two[index2];
		if (one < two) {
			merged[index] = one;
			index1++;
		}
		else {
			merged[index] = two;
			index2++;
		}
	}
}

void print_array(int* array, int N)
{
	for (int i = 0; i < N; i++)
		cout << array[i] << " ";
	cout << endl;
}


int main()
{
	const int N = 5;
	int odd[N] = { 1, 3, 5, 7, 9 };
	int even[N] = { 2, 4, 6, 8, 10 };
	int merged[2*N];

	MergeAndSort(odd, even, N, merged);

	print_array(merged, 2*N);
}