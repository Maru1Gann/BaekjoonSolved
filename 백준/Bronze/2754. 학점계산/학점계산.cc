#include <iostream>
using namespace std;

int main()
{
	float score = 0;
	string grade;
	cin >> grade;

	switch (grade[0])
	{
	case 'A':
		score = 4;
		break;
	case 'B':
		score = 3;
		break;
	case 'C':
		score = 2;
		break;
	case 'D':
		score = 1;
		break;
	case 'F':
		score = 0;
		break;
	}

	if (grade.length() > 1)
	{
		switch (grade[1])
		{
		case '+':
			score += 0.3f;
			break;
		case '0':
			break;
		case '-':
			score -= 0.3f;
			break;
		}

	}
	cout << fixed;
	cout.precision(1);
	cout << score;
}