#include <iostream>
using namespace std;

int main() 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;
	int* array = new int[n+1];

	array[0] = 0;
	cin >> array[1];
	for (int i = 2; i <= n; i++)
	{
		int tmp;
		cin >> tmp;
		array[i] = array[i - 1] + tmp;
	}

	while (m--)
	{
		int i, j;
		cin >> i >> j;
		cout << array[j] - array[i-1] << '\n';
	}

}