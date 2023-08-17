#include <iostream>
using namespace std;

int n;

void update(int* A, int* note, int current = 0)
{
	int max = 0;
	int pin = 0;
	for (int i = 0; i < current; i++)
	{
		if (note[i] > max && A[i] < A[current])
			max = note[i];
	}
	note[current] = max + 1;
}


int main()
{	
	cin >> n;
	int* A = new int[n];
	for (int i = 0; i < n; i++)
		cin >> A[i];

	int* note = new int[n] {0};
	for (int i = 0; i < n; i++)
		update(A, note, i);

	int max = 0;
	for (int i = 0; i < n; i++)
		if (note[i] > max)
			max = note[i];

	cout << max;
}