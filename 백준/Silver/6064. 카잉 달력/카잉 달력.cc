#include <iostream>

using namespace std;

int gcd(int a, int b)
{
	if (b == 0)
		return a;
	else
		return gcd(b, a % b);
}

int lcm(int a, int b)
{
	return a * b / gcd(a, b);
}

int main()
{
	int t;
	cin >> t;
	while (t--) 
	{
		int m, n, x, y;
		cin >> m >> n >> x >> y;

		if (m < n)
		{
			swap(m, n);
			swap(x, y);
		}
		
		int limit = lcm(m, n);
		int count = x;
		int b = x;
		while (b > n)
			b -= n;

		while (1)
		{
			if (b == y)
				break;
			if (count > limit)
			{
				count = -1;
				break;
			}
			b += m;
			while (b > n)
				b -= n;
			count += m;
		}

		cout << count << '\n';
	}
}