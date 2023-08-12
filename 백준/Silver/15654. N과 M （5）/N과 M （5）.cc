#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int n, m;

void pick(int* list, bool* picked, int depth = 0, string up = "")
{
	if (depth >= m)
	{
		cout << up + '\n';
		return;
	}

	bool* tmpPicked = new bool[n];
	copy(picked, picked + n, tmpPicked);

	for (int i = 0; i < n; i++)
	{
		if (tmpPicked[i] == false)
		{
			string tmp = to_string(list[i]) + " ";
			tmpPicked[i] = true;
			pick(list, tmpPicked, depth + 1, up + tmp);
		}
		copy(picked, picked + n, tmpPicked);
	}
}

int main()
{
	cin >> n >> m;
	int* list = new int[n];
	for (int i = 0; i < n; i++)
		cin >> list[i];
	sort(list, list + n);
	bool* picked = new bool[n] {0};

	pick(list, picked);
}