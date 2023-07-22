#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int* array = new int[n];

	for (int i = 0; i < n; i++)
		cin >> array[i];

	int v;
	int count = 0;
	cin >> v;

	for (int i = 0; i < n; i++)
		if (array[i] == v)
			count++;

	cout << count;
}