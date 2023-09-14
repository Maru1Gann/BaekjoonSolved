#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);

	int n;
	cin >> n;
	int* cur = new int[n] {0};
	int* note = new int[n] {0};
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= i; j++)
			cin >> cur[j];

		for (int j = 0; j <= i; j++)
		{
			if (j == 0)
				cur[j] += note[j];
			else if (j == i)
				cur[j] += note[j - 1];
			else
				cur[j] += max(note[j - 1], note[j]);
		}
		copy(cur, cur + n, note);
	}

	int out = 0;
	for (int i = 0; i < n; i++)
		if (note[i] > out)
			out = note[i];
	cout << out;
}