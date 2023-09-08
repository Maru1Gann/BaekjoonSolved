#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n;
	cin >> n;
	int note[2][3]{ 0 };

	cin >> note[0][0] >> note[0][1] >> note[0][2];

	for (int i = 1; i < n; i++)
	{
		int r, g, b;
		cin >> r >> g >> b;
		note[1][0] = r + min(note[0][1], note[0][2]);
		note[1][1] = g + min(note[0][0], note[0][2]);
		note[1][2] = b + min(note[0][0], note[0][1]);

		for (int i = 0; i < 3; i++)
			note[0][i] = note[1][i];
	}

	cout << min(note[0][0], min(note[0][1], note[0][2]));
}