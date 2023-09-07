#include<iostream>
#include <queue>
using namespace std;

int main()
{
	int a, b;
	cin >> a >> b;


	queue<pair<long long , int> > q;		// pair<number, cost>
	q.push({ a,1 });
	int result = -1;

	while (!q.empty())
	{
		pair<long long , int> tmp = q.front(); q.pop();
		long long cur = tmp.first;
		int curCost = tmp.second;

		if (cur > b)
			continue;
		if (cur == b)
		{
			if (curCost < result || result == -1)
				result = curCost;
			continue;
		}


		long long des = cur * 2;
		int desCost = curCost + 1;
		q.push({ des,desCost });

		des = cur * 10 + 1;
		q.push({ des,desCost });
	}

	cout << result;
}