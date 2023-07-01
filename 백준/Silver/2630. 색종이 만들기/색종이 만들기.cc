#include <iostream>
using namespace std;

int white = 0;
int blue = 0;

void cut(bool** paper, int n, int offsetx = 0, int offsety = 0)
{
	if (n <= 1)
	{
		if (paper[offsety][offsetx])
			blue++;
		else if (!paper[offsety][offsetx])
			white++;
		return;
	}

	int half = (n- 1) / 2;
	bool tmp = paper[offsety][offsetx];

	for (int i = offsetx; i < offsetx + n; i++)
	{
		for (int j = offsety; j < offsety + n; j++)
		{
			if (tmp != paper[j][i])
			{
				cut(paper, n / 2, offsetx, offsety);
				cut(paper, n / 2, offsetx + n / 2, offsety);
				cut(paper, n / 2, offsetx, offsety + n / 2);
				cut(paper, n / 2, offsetx + n / 2, offsety + n / 2);
				return;
			}
		}
	}

	if (tmp)
		blue++;
	else
		white++;
}


int main()
{
	int n;
	cin >> n;

	bool** paper = new bool* [n] {0};
	for (int i = 0; i < n; i++)
		paper[i] = new bool[n] {0};
	
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> paper[i][j];

	cut(paper, n);
	cout << white << '\n' << blue << '\n';
}