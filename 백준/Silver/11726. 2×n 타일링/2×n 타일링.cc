#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	if (n == 1)
	{
		cout << 1;
		return 0;
	}
	if (n == 2)
	{
		cout << 2;
		return 0;
	}
	int n1 = 1, n2 = 2;

	bool flip = 1;

	for (int i = 3; i <= n; i++)
	{
		if (flip)
		{
			n1 += n2;
			n1 %= 10007;
		}
		else
		{
			n2 += n1;
			n2 %= 10007;
		}
		flip = !flip;
	}

	if (flip)
		cout << n2;
	else
		cout << n1;

}