#include <iostream>
#include <queue>
using namespace std;

int n, m, INF;

void visit(queue<pair<int, int> >& Q, int** cost, int currentCost, int y, int x)
{
	if (y >= n || y < 0)
		return;
	if (x >= m || x < 0)
		return;

	if (cost[y][x] > currentCost)
	{
		cost[y][x] = currentCost;
		Q.push({ y,x });
	}
}


int main()
{
	cin >> n >> m;
	INF = (n + 1) * (m + 1);
	int** cost = new int* [n];


	for (int i = 0; i < n; i++)
	{
		cost[i] = new int[m];

		string tmp;
		cin >> tmp;

		for (int j = 0; j < m; j++)
		{
			if (tmp[j] == '0')
				cost[i][j] = -1;
			else
				cost[i][j] = INF;
		}
	}

	cost[0][0] = 1;
	queue<pair<int, int> > Q;
	Q.push({ 0, 0 });
	
	while (!Q.empty())
	{
		pair<int, int> tmp = Q.front(); Q.pop();
		int y = tmp.first;
		int x = tmp.second;
		int currentCost = cost[y][x] + 1;

		visit(Q, cost, currentCost, y + 1, x);
		visit(Q, cost, currentCost, y - 1, x);
		visit(Q, cost, currentCost, y, x + 1);
		visit(Q, cost, currentCost, y, x - 1);
	}

	cout << cost[n - 1][m - 1];
}