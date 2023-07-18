#include <iostream>
#include <queue>
using namespace std;

int n, m;
int c = 0;

void visit(queue<pair<int, int> >& Q, char** campus, bool** visited, int y, int x)
{
	if (y < 0 || y >= n)
		return;
	if (x < 0 || x >= m)
		return;
	if (campus[y][x] == 'X' || campus[y][x] == 'I')
		return;


	if (campus[y][x] == 'P' && visited[y][x] == false)
	{
		c++;
		Q.push({ y,x });
		visited[y][x] = true;
	}
	else if (campus[y][x] == 'O' && visited[y][x] == false)
	{
		Q.push({ y,x });
		visited[y][x] = true;
	}

}


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	char** campus = new char* [n];
	bool** visited = new bool* [n];

	for (int i = 0; i < n; i++)
	{
		campus[i] = new char[m];
		visited[i] = new bool[m] {0};
	}
		

	pair<int, int> start;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> campus[i][j];
			if (campus[i][j] == 'I')
				start = { i, j };
		}
	}

	queue<pair<int, int> > Q;
	Q.push(start);
	visited[start.first][start.second] = true;

	while (!Q.empty())
	{
		pair<int, int> tmp;
		tmp = Q.front(); Q.pop();
		int y = tmp.first;
		int x = tmp.second;
		visit(Q, campus, visited, y - 1, x);
		visit(Q, campus, visited, y + 1, x);
		visit(Q, campus, visited, y, x - 1);
		visit(Q, campus, visited, y, x + 1);
	}

	if (c == 0)
		cout << "TT";
	else
		cout << c;
}