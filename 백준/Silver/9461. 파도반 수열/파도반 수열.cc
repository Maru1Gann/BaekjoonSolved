#include <iostream>
using namespace std;

long long topdown(int a, long long* p)
{
	if (p[a] != 0) return p[a];
	else return p[a] = topdown(a - 1, p) + topdown(a - 5, p);
}


int main() 
{
	long long p[101] = { 0 };
	p[1] = p[2] = p[3] = 1;
	p[4] = p[5] = 2;

	int t;
	cin >> t;
	while (t--)
	{
		int target;
		cin >> target;
		cout << topdown(target, p) << '\n';
	}

}