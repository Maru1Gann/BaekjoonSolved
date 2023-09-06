#include <iostream>
#include <algorithm>
using namespace std;

int n, m;

void pick(int* arr, int* out, int start = 0, int depth = 0)
{
	if (depth == m)
	{
		for (int i = 0; i < m; i++)
			cout << out[i] << " ";
		cout << '\n';
		return;
	}

	int prev = 0;
	for (int i = start; i < n; i++)
	{
		if (arr[i] != prev)
		{
			prev = out[depth] = arr[i];
			pick(arr, out, i, depth + 1);
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
	pick(arr, out);
}