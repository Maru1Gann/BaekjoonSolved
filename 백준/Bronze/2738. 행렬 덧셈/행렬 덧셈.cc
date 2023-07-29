#include <iostream>
using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	int** matrix = new int* [n];
	for (int i = 0; i < n; i++)
		matrix[i] = new int[m] {0};

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < m; k++)
			{
				int tmp;
				cin >> tmp;
				matrix[j][k] += tmp;
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cout << matrix[i][j] << ' ';
		cout << '\n';
	}
	
}