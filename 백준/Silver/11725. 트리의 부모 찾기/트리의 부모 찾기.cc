#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<int>* adjlist = new vector<int>[n + 1];
	for (int i = 1; i <= n-1; i++)
	{
		int a, b;
		cin >> a >> b;
		adjlist[a].push_back(b);
		adjlist[b].push_back(a);
	}

	queue<int> q;
	bool* visited = new bool[n + 1] {false};
	int* parent = new int[n + 1] {0};

	q.push(1);
	visited[1] = true;

	while (!q.empty())
	{
		int current = q.front(); q.pop();
		for (int i = 0; i < adjlist[current].size(); i++)
		{
			int next = adjlist[current][i];
			if (visited[next])
				parent[current] = next;
			else
			{
				q.push(next);
				visited[next] = true;
			}
		}
	}

	for (int i = 2; i < n + 1; i++)
		cout << parent[i] << '\n';
}