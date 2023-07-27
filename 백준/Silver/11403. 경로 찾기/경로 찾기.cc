#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;

	bool** adjMatrix = new bool* [n];
	for (int i = 0; i < n; i++)
	{
		adjMatrix[i] = new bool[n];
		for (int j = 0; j < n; j++)
			cin >> adjMatrix[i][j];
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < n; k++)
			{
				if (adjMatrix[j][i] && adjMatrix[i][k])
					adjMatrix[j][k] = true;
			}
		}
	}


	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << adjMatrix[i][j] << ' ';
		cout << '\n';
	}
		
}