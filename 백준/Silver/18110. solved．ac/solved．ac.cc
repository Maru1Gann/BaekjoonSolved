#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
	int n;
	cin >> n;
	if (n == 0)
	{
		cout << 0;
		return 0;
	}

	int* opinion = new int[n];
	float avgCalc = n * 0.15;		//30% 절사평균
	int offset = round(avgCalc);		//위 아래에서 빼야하는 인원 수.
	for (int i = 0; i < n; i++)
		cin >> opinion[i];

	sort(opinion, opinion + n);

	float avg = 0;
	for (int i = offset; i < n - offset; i++)
		avg += opinion[i];
	cout << round(avg / (n - offset * 2));
}