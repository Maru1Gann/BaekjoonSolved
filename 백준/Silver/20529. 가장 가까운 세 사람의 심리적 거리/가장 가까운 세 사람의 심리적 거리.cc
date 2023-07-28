#include <iostream>
using namespace std;

int calculateDistance(char* a, char* b, char* c)
{
	int count = 0;
	for (int i = 0; i < 4; i++)
	{
		if (a[i] != b[i])
			count++;
		if (a[i] != c[i])
			count++;
		if (b[i] != c[i])
			count++;
	}
	return count;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		if (n > 32)
		{
			string tmp;
			for (int i = 0; i < n; i++)
				cin >> tmp;
			cout << 0 << '\n';
			continue;
		}

		char** MBTI = new char* [n];
		for (int i = 0; i < n; i++)
		{
			MBTI[i] = new char[5];
			cin >> MBTI[i];
		}

		int minimal = 100;
		for (int i = 0; i < n; i++)
		{
			for (int j = i; j < n; j++)
			{
				for (int k = j; k < n; k++)
				{
					if (i == j || j == k || i == k)
						continue;
					else
						minimal = min(minimal, calculateDistance(MBTI[i], MBTI[j], MBTI[k]));
				}
			}
		}

		cout << minimal << '\n';

		for (int i = 0; i < n; i++)
		{
			delete MBTI[i];
		}
		delete[] MBTI;
	}

}