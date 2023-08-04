#include <iostream>
#include <queue>
using namespace std;

const int INF = 10000000;

int direct[101]{ 0 };
int cost[101];

int main()
{
	for (int i = 0; i < 101; i++)
		cost[i] = INF;
	cost[1] = 0;

	int n, m;
	cin >> n >> m;

	for (int i = n + m; i > 0; i--)
	{
		int a, b;
		cin >> a >> b;
		direct[a] = b;
	}

	queue<int> Q;
	Q.push(1);
	while (!Q.empty())
	{
		int current = Q.front(); Q.pop();
		int directed = direct[current];
		if (directed != 0)
		{
			if (cost[current] < cost[directed])
			{
				cost[directed] = cost[current];
				Q.push(directed);
			}
		}
		else
		{
			for (int i = 1; i <= 6; i++)
			{
				if (cost[current + i] > cost[current] + 1)
				{
					Q.push(current + i);
					cost[current + i] = cost[current] + 1;
				}
			}
		}
	}

	cout << cost[100];
}