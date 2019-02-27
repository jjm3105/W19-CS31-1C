#include <iostream>
using namespace std;


int findDuplicate(const int A[], int n)
{
	bool isFound[500];

	for (int i = 0; i < 500; i++) {
		isFound[i] = false;
	}

	for (int i = 0; i < n; i++) {
		if (isFound[A[i]]) {
			return A[i];
		}
		isFound[A[i]] = true;
	}
	
	return 0;
}

int main()
{
	int A[7] = {1, 3, 5, 3, 2, 6, 1};
	cout << findDuplicate(A, 7) << endl;
}