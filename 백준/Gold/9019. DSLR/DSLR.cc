#include <iostream>
#include <string>
#include <queue>
using namespace std;

const int MAX = 9999 + 1;
const int INF = MAX * 2;

int D(int num)
{
	return (num * 2) % MAX;
}
int S(int num)
{
	return (--num < 0) ? 9999 : num;
}
int L(int num)
{
	return (num % 1000) * 10 + num / 1000;
}
int R(int num)
{
	return num / 10 + (num % 10) * 1000;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;
	while (t--)
	{
		bool visited[MAX]{ 0 };
		queue<pair<int, string> > q;
		int a, b;
		cin >> a >> b;

		q.push({ a, "" });
		visited[a] = true;
		string output;
		while (!q.empty())
		{
			auto tmp = q.front(); q.pop();
			int current = tmp.first;
			string command = tmp.second;
			if (current == b)
			{
				output = command;
				break;
			}

			int d, s, l, r;
			d = D(current);
			s = S(current);
			l = L(current);
			r = R(current);
			if (visited[d] == false)
			{
				q.push({ d , command + 'D'});
				visited[d] = true;
			}
			if (visited[s] == false)
			{
				q.push({ s , command + 'S' });
				visited[s] = true;
			}
			if (visited[l] == false)
			{
				q.push({ l , command + 'L' });
				visited[l] = true;
			}
			if (visited[r] == false)
			{
				q.push({ r, command + 'R' });
				visited[r] = true;
			}
		}
		cout << output << '\n';
	}
}