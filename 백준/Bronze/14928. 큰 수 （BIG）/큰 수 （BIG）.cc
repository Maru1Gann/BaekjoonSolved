#include <iostream>
#include <string>
using namespace std;

int main()
{
	string dividend;
	cin >> dividend;
	int divider = 20000303;
	int result = 0;

	for (int i = 0; i < dividend.length(); i++)
	{
		int num = dividend[i] - '0';
		result *= 10;
		result = (result + num) % divider;
	}

	cout << result;
}