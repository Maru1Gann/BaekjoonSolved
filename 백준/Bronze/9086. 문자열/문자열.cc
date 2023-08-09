#include <iostream>
#include <string>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		string input;
		cin >> input;
		cout << *input.begin() << *--input.end() << '\n';
	}
}