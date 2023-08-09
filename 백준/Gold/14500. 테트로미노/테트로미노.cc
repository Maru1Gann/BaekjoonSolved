#include <iostream>
#include <queue>
using namespace std;

int n, m;

enum Direction
{
	none = 0,
	N = 1,
	E = 2,
	S = 3,
	W = 4
};


class Record
{
public:
	int y, x, last, count, cost;
	Record(int y, int x, int cost, int last = none, int count = 0)
	{
		this->y = y;
		this->x = x;
		this->cost = cost;
		this->last = last;
		this->count = count;
	}
};

int getException(int** paper, int y, int x)
{
	int a, b, c, d, e, f;
	a = b = c = d = e = f = 0;
	if (y - 1 >= 0 && y + 1 < n)
	{
		int tmp = paper[y][x] + paper[y - 1][x] + paper[y + 1][x];		//세로로 세 개.
		if (x + 1 < m)
			a = tmp + paper[y][x + 1];
		if (x - 1 >= 0)
			b = tmp + paper[y][x - 1];
		e = max(a, b);
	}
	if (x - 1 >= 0 && x + 1 < m)
	{
		int tmp = paper[y][x] + paper[y][x - 1] + paper[y][x + 1];
		if (y - 1 >= 0)
			c = tmp + paper[y - 1][x];
		if (y + 1 < n)
			d = tmp + paper[y + 1][x];
		f = max(c, d);
	}

	return max(e, f);
}

void visit(queue<Record>& q, int** paper, Record current, int direction)
{
	int y = current.y;
	int x = current.x;

	if (direction == N)
		y--;
	else if (direction == E)
		x++;
	else if (direction == S)
		y++;
	else if (direction == W)
		x--;
	
	if (y < 0 || y >= n)
		return;
	if (x < 0 || x >= m)
		return;

	int cost = current.cost + paper[y][x];
	int last = direction + 2;
	if (last > 4)
		last -= 4;
	//마지막 위치 방향 표시(다음 방문지 입장에서).
	int count = current.count + 1;
	Record dest(y, x, cost, last, count);
	q.push(dest);

}

void vist4ways(queue<Record>& q, int** paper, Record current)
{
	if (current.count >= 3)
		return;

	for (int i = 1; i <= 4; i++)
	{
		if (current.last != i)
			visit(q, paper, current, i);
	}
}

int getCost(int** paper, int startY, int startX)
{
	
	
	queue<Record> q;
	Record start(startY, startX, paper[startY][startX]);
	q.push(start);
	int max = getException(paper, startY, startX);
	while (!q.empty())
	{
		Record tmp = q.front(); q.pop();
		int cost = tmp.cost;
		if (max < cost)
			max = cost;

		vist4ways(q, paper, tmp);
	}

	return max;
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	int** paper = new int* [n];
	for (int i = 0; i < n; i++)
	{
		paper[i] = new int[m];
		for (int j = 0; j < m; j++)
			cin >> paper[i][j];
	}

	int max = 0;
	for(int i = 0; i<n; i++)
		for (int j = 0; j < m; j++)
		{
			int tmp = getCost(paper, i, j);
			if (tmp > max)
				max = tmp;
		}
	cout << max;
}