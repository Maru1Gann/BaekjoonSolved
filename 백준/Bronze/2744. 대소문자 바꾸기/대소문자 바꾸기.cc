#include <iostream>
using namespace std;

int main()
{
	string input;
	cin >> input;
	for (int i = 0; i < input.length(); i++)
	{
		if (isupper(input[i]))
			input[i] = tolower(input[i]);
		else
			input[i] = toupper(input[i]);
	}
	cout << input;
}