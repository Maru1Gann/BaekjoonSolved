#include <iostream>
#include <string>
using namespace std;

int n, m;

void pick(int start = 1, int depth = 0, string out = "")
{
	if (depth >= m)
	{
		cout << out << '\n';
		return;
	}

	for (int i = start; i <= n; i++)
	{
		string tmp = to_string(i) + " ";
		pick(i + 1, depth + 1, out + tmp);
	}
		
}

int main()
{

	cin >> n >> m;
	pick();
}