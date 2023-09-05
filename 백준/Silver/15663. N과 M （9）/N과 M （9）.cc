#include <iostream>
#include <algorithm>
using namespace std;

int n, m;

void pick(int* arr, bool* visited, int* out, int depth = 0)
{
	if (depth == m)
	{
		for (int i = 0; i < m; i++)
			cout << out[i] << " ";
		cout << '\n';
	}

	int prev = 0;
	for (int i = 0; i < n; i++)
	{
		if (visited[i] == false && arr[i] != prev)
		{
			visited[i] = true;
			prev = out[depth] = arr[i];
			pick(arr, visited, out, depth + 1);
			visited[i] = false;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

	int* arr = new int[n];
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	sort(arr, arr + n);

	int* out = new int[m];
	bool* visited = new bool[n] {false};
	pick(arr, visited, out);
}