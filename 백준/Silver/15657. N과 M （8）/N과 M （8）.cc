#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int n, m;
int* list;

void pick(int start = 0, int depth = 0, string out = "")
{
	if (depth >= m)
	{
		cout << out + '\n';
		return;
	}

	for (int i = start; i < n; i++)
	{
		string tmp = out + to_string(list[i]) + ' ';
		pick(i, depth + 1, tmp);
	}
}


int main()
{
	cin >> n >> m;
	list = new int[n];
	for (int i = 0; i < n; i++)
		cin >> list[i];
	sort(list, list + n);
	pick();
}