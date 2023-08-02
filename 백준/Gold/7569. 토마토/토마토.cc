#include <iostream>
#include <queue>
using namespace std;

int m, n, h;

class Coordinate
{
public:
	int h, n, m;
	Coordinate()
	{
		h = n = m = 0;
	}
	Coordinate(int z, int y, int x)
	{
		h = z;
		n = y;
		m = x;
	}
};

void visit(queue<Coordinate>& Q, int*** box, Coordinate tmp, int cost)
{
	int z, y, x;
	z = tmp.h;
	y = tmp.n;
	x = tmp.m;

	if (z < 0 || z >= h)
		return;
	if (y < 0 || y >= n)
		return;
	if (x < 0 || x >= m)
		return;

	if (box[z][y][x] > cost)
	{
		box[z][y][x] = cost;
		Q.push(Coordinate(z, y, x));
	}
}

void visit6ways(queue<Coordinate>& Q, int*** box, Coordinate tmp)
{
	int z, y, x;
	z = tmp.h;
	y = tmp.n;
	x = tmp.m;
	int cost = box[z][y][x] + 1; //기존위치 + 1
	
	//상하
	visit(Q, box, Coordinate(z + 1, y, x), cost);
	visit(Q, box, Coordinate(z - 1, y, x), cost);

	//전후
	visit(Q, box, Coordinate(z, y + 1, x), cost);
	visit(Q, box, Coordinate(z, y - 1, x), cost);

	//좌우
	visit(Q, box, Coordinate(z, y, x + 1), cost);
	visit(Q, box, Coordinate(z, y, x - 1), cost);
}


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int*** box;
	cin >> m >> n >> h;

	const int INF = m * n * h + 100;

	queue<Coordinate> Q;

	box = new int** [h];
	for (int i = 0; i < h; i++)
	{
		box[i] = new int* [n];
		for (int j = 0; j < n; j++)
			box[i][j] = new int[m];
	}

	for (int i = 0; i < h; i++)
		for (int j = 0; j < n; j++)
			for (int k = 0; k < m; k++)
			{
				int tmp;
				cin >> tmp;
				if (tmp == 0)
					box[i][j][k] = INF;
				else
				{
					box[i][j][k] = tmp;
					if (tmp == 1)
						Q.push(Coordinate(i, j, k));
				}
			}

	int max = 0;
	while (!Q.empty())
	{
		Coordinate tmp;
		tmp = Q.front(); Q.pop();
		visit6ways(Q, box, tmp);
	}

	bool isRipe = true;

	for (int i = 0; i < h; i++)
		for (int j = 0; j < n; j++)
			for (int k = 0; k < m; k++)
			{
				int tmp = box[i][j][k];

				if (tmp == INF)
					isRipe = false;
				if (tmp > max)
					max = tmp;
			}


	if (isRipe)
		cout << max - 1;
	else
		cout << -1;
}