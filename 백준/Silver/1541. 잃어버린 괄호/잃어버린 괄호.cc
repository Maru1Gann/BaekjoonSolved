#include <iostream>
#include <string>
using namespace std;

int main()
{
	string input;
	cin >> input;


	int cut = 0;
	int sum = 0;
	bool isMinus = false;
	for (int i = 0; i <= input.length(); i++)
	{
		if (i == input.length())
		{
			int tmp1 = stoi(input.substr(cut, i - cut));
			if (isMinus)
				sum -= tmp1;
			else
				sum += tmp1;
		}
		else if (input[i] >= '0' && input[i] <= '9')
			continue;
		else
		{
			int tmp2 = stoi(input.substr(cut, i - cut));
			cut = i + 1;

			if (isMinus)
				sum -= tmp2;
			else
				sum += tmp2;
		}


		if (input[i] == '-')
			isMinus = true;
	}

	cout << sum;
}