#include <iostream>
using namespace std;

int main()
{
	int a, b;
	cin >> a >> b;

	bool check = false;

	if (a < 0)
	{
		a *= -1;
		check = !check;
	}
	if (b < 0)
	{
		b *= -1;
		check = !check;
	}

	unsigned int a1, b1;
	a1 = a;
	b1 = b;

	if (check)
		cout << a1 + b1;
	else
		(a1 > b1) ? (cout << a1 - b1) : (cout << b1 - a1);

}