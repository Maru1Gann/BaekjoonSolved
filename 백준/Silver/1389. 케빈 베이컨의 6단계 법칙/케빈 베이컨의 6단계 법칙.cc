#include <iostream>
using namespace std;

const int INF = 10000;

int main()
{
	int n, m;
	cin >> n >> m;

	int** matrix = new int* [n + 1];
	for (int i = 0; i <= n; i++)
	{
		matrix[i] = new int[n + 1];

		for (int j = 0; j <= n; j++)
			matrix[i][j] = INF;

		matrix[i][i] = 0;
	}

	//0번 인덱스는 사용 안 함.

	while (m--)
	{
		int a, b;
		cin >> a >> b;
		matrix[a][b] = 1;
		matrix[b][a] = 1;
	}

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			for (int k = 1; k <= n; k++)
				matrix[j][k] = min(matrix[j][k], matrix[j][i] + matrix[i][k]);


	int min = INF;
	int num = 0;

	for (int i = 1; i <= n; i++)
	{
		int sum = 0;
		
		for (int j = 1; j <= n; j++)
			sum += matrix[i][j];


		if (min > sum)
		{
			min = sum;
			num = i;
		}
	}


	cout << num;
}