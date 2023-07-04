#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int BFS(vector<int>* vec, int n)
{
	queue<int> Q;
	bool* visited = new bool[n + 1] {0};
	int compNum = 0;
	visited[0] = 1;
	for (int i = 1; i <= n; i++)
	{
		if (visited[i] == false)
		{
			Q.push(i);
			visited[i] == true;
			compNum++;
		}
			

		while (!Q.empty())
		{
			int cur = Q.front(); Q.pop();
			for (int j = 0; j < vec[cur].size(); j++)
			{
				if (visited[vec[cur][j]] == false)
				{
					visited[vec[cur][j]] = 1;
					Q.push(vec[cur][j]);
				}
			}
		}

	}

	return compNum;
}



int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);


	int n, m;
	cin >> n >> m;

	vector<int>* vec = new vector<int>[n + 1];
	while (m--)
	{
		int u, v;
		cin >> u >> v;
		vec[u].push_back(v);
		vec[v].push_back(u);
	}

	cout << BFS(vec, n);
}