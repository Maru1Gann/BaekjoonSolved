#include <iostream>
#include <queue>
using namespace std;

void visit(queue<pair<int, int> >& Q, int** box, int y, int x, int cost, int m, int n)
{
	if (y >= n || y < 0)
		return;
	if (x >= m || x < 0)
		return;
	if (box[y][x] == -1)
		return;

	if (box[y][x] > cost || box[y][x] == 0)
	{
		box[y][x] = cost;
		Q.push({ y,x });
	}
}


int main()
{
	int m, n;
	cin >> m >> n;
	int** box = new int* [n];
	for (int i = 0; i < n; i++)
		box[i] = new int[m] {0};

	queue<pair<int, int> > Q;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> box[i][j];
			if (box[i][j] == 1)
				Q.push({ i,j });
		}
	}

	while (!Q.empty())
	{
		pair<int, int> tmp = Q.front(); Q.pop();
		int y = tmp.first;
		int x = tmp.second;
		int cost = box[y][x] + 1;

		visit(Q, box, y - 1, x, cost, m, n);
		visit(Q, box, y + 1, x, cost, m, n);
		visit(Q, box, y, x - 1, cost, m, n);
		visit(Q, box, y, x + 1, cost, m, n);
	}

	bool check = true;
	int max = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (box[i][j] > max)
				max = box[i][j];
			if (box[i][j] == 0)
				check = false;
		}
	}

	if (check)
		cout << max - 1;
	else
		cout << -1;


}