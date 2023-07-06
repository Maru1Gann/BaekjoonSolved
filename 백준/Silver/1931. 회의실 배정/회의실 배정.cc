#include <iostream>
#include <algorithm>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b)
{
	if (a.second == b.second)
		return a.first < b.first;

	return a.second < b.second;
}

int main()
{
	int n;
	cin >> n;
	pair<int,  int>* meeting = new pair<int, int>[n];
	int max = 0;
	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;

		if (b > max)
			max = b;

		meeting[i] = { a, b };
	}

	sort(meeting, meeting + n, compare);

	int count = 0;
	int last = 0;
	for (int i = 0; i < n; i++)
	{
		if (last <= meeting[i].first)
		{
			last = meeting[i].second;
			count++;
		}
	}

	cout << count;
}