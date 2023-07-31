#include <iostream>
#include <string>
#include <cmath>
using namespace std;

bool check(int num, bool* enabled)
{
	string n = to_string(num);
	for (int i = 0; i < n.length(); i++)
	{
		int tmp = n[i] - '0';
		if (enabled[tmp] == false)
			return false;
	}

	return true;
}

int costCheck(int n, int cost)
{
	if (cost > abs(n - 100))
		return abs(n - 100);
	else
		return cost;
}

int main()
{
	int n;
	int m;
	cin >> n >> m;
	if (m == 0)
	{
		string tmp = to_string(n);
		cout << costCheck(n, tmp.length());
		return 0;
	}
	if (m == 10)
	{
		int tmp;
		while (m--)
			cin >> tmp;
		cout << abs(n - 100);
		return 0;
	}


	bool enabled[10];
	for (int i = 0; i < 10; i++)
		enabled[i] = true;
	while (m--)
	{
		int tmp;
		cin >> tmp;
		enabled[tmp] = false;
	}

	int down = -10000000;
	int up = 10000000;
	for (int i = n; i >= 0; i--)
	{
		if (check(i, enabled))
		{
			down = i;
			break;
		}
	}
	for (int i = n; n - down > i - n; i++)
	{
		if (check(i, enabled))
		{
			up = i;
			break;
		}
	}

	int x;
	int cost;
	if (n - down < up - n)
	{
		x = down;
		cost = n - down;
	}
	else
	{
		x = up;
		cost = up - n;
	}

	cost =  to_string(x).length() + cost;
	cout << costCheck(n, cost);
}