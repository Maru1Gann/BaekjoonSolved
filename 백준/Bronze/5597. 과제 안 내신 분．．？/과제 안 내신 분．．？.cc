#include <iostream>
using namespace std;

int main()
{
	bool attendance[31]{ 0 };
	for (int i = 1; i <= 28; i++)
	{
		int tmp;
		cin >> tmp;
		attendance[tmp] = 1;
	}

	for (int i = 1; i <= 30; i++)
		if (attendance[i] == 0)
			cout << i << '\n';
}