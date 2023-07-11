#include <iostream>
#include <queue>
using namespace std;

int n, m;

void visit(queue<pair<int, int> >& Q, int** map, int** output, int y, int x, int cost)
{
	if (y >= n || y < 0)
		return;
	if (x >= m || x < 0)
		return;
	if (map[y][x] == 0)
		return;

	if (cost < output[y][x])
	{
		output[y][x] = cost;
		Q.push({y , x});
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

	int** map = new int* [n];
	int** output = new int* [n];

	for (int i = 0; i < n; i++)
	{
		map[i] = new int[m] {0};
		output[i] = new int[m] {0};
	}
	
	pair<int, int> start = { 0, 0 };

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			output[i][j] = n * m;
			cin >> map[i][j];
			if (map[i][j] == 0)
				output[i][j] = 0;
			if (map[i][j] == 2)
				start = { i, j };
		}
	}

	queue<pair<int, int> > Q;
	output[start.first][start.second] = 0;
	Q.push(start);

	while (!Q.empty())
	{
		pair<int, int> tmp = Q.front(); Q.pop();
		int y = tmp.first;
		int x = tmp.second;
		int cost = output[y][x] + 1;
		visit(Q, map, output, y-1, x, cost);
		visit(Q, map, output, y + 1, x, cost);
		visit(Q, map, output, y, x - 1, cost);
		visit(Q, map, output, y, x + 1, cost);
	}


	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (output[i][j] == n * m)
				output[i][j] = -1;
			cout << output[i][j] << ' ';
		}
		cout << '\n';
	}
}