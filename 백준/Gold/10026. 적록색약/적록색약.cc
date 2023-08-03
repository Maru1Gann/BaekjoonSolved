#include <iostream>
#include <string>
#include <queue>
using namespace std;

int n, count1, count2;


void visit(queue<pair <int, int> >& Q, char** pic, bool** visited, char color, int y, int x)
{
	if (y < 0 || y >= n)
		return;
	if (x < 0 || x >= n)
		return;

	if (color == pic[y][x] && visited[y][x] == false)
	{
		Q.push({ y, x });
		visited[y][x] = true;
	}
		
}

void visit4ways(queue<pair <int, int> >& Q, char** pic, bool** visited, pair<int, int> coord)
{
	int y = coord.first;
	int x = coord.second;
	char color = pic[y][x];
	visit(Q, pic, visited, color, y - 1, x);
	visit(Q, pic, visited, color, y + 1, x);
	visit(Q, pic, visited, color, y, x - 1);
	visit(Q, pic, visited, color, y, x + 1);
}



int main()
{
	cin >> n;
	char** pic = new char* [n];
	bool** visited = new bool* [n];

	for (int i = 0; i < n; i++)
	{
		pic[i] = new char[n];
		visited[i] = new bool[n] {0};
		string tmp;
		cin >> tmp;
		for (int j = 0; j < tmp.length(); j++)
			pic[i][j] = tmp[j];
	}

	queue<pair <int, int> > Q;
	count1 = count2 = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (visited[i][j] == false)
			{
				Q.push({ i,j });
				visited[i][j] = true;
				count1++;

				while (!Q.empty())
				{
					pair<int, int> coord = Q.front(); Q.pop();
					visit4ways(Q, pic, visited, coord);
				}
			}
		}
	}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			if (pic[i][j] == 'G')
				pic[i][j] = 'R';
			visited[i][j] = false;
		}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (visited[i][j] == false)
			{
				Q.push({ i,j });
				visited[i][j] = true;
				count2++;

				while (!Q.empty())
				{
					pair<int, int> coord = Q.front(); Q.pop();
					visit4ways(Q, pic, visited, coord);
				}
			}
		}
	}

	cout << count1 << ' ' << count2;
}