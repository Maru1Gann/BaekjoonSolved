#include <iostream>
using namespace std;


int main()
{
    ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    
	int n, m;
	cin >> n >> m;
	bool* input = new bool[m];
	for (int i = 0; i < m; i++)
	{
		char tmp;
		cin >> tmp;
		if (tmp == 'I')
			input[i] = 1;
		else
			input[i] = 0;
	}

	int i = 0;
	int count = 0;
	int length = 0;
	int offset = 2 * n + 1;


	for (int i = 0; i < m; i++)
	{
		if (input[i] == 0)
			continue;
		else 
			length = 1;

		while (i < m - 1)
		{
			if (input[i] != input[i + 1])
			{
				length++;
				i++;
			}
			else
				break;
		}

		if (length % 2 == 0)
			length--;
		if (length >= offset)
		{
			count++;
			count += (length - offset) / 2;
		}
	}


	cout << count;
}