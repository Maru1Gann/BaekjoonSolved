#include <iostream>
#include <queue>
using namespace std;
const int MAX = 100000;

int main()
{
	int n, k;
	cin >> n >> k;
	int* note = new int[MAX + 1];
	for (int i = 0; i <= MAX; i++)
		note[i] = MAX + 1;

	note[n] = 0;

	queue<int> Q;
	Q.push(n);
	while (!Q.empty())
	{
		int temp = Q.front(); Q.pop();
		int cost = note[temp] + 1;
		if (temp - 1 >= 0 && note[temp - 1] > cost)
		{
			note[temp - 1] = cost;
			Q.push(temp - 1);
		}
		if (temp + 1 <= MAX && note[temp + 1] > cost)
		{
			note[temp + 1] = cost;
			Q.push(temp + 1);
		}
		if (temp * 2 <= MAX && note[temp * 2] > cost)
		{
			note[temp * 2] = cost;
			Q.push(temp * 2);
		}
	}
	cout << note[k];
}