#include <iostream>
using namespace std;

//(a*b)%c == {(a%c)*(b%c)}%c

long long a, b, c;

long long getRemainder(long long int x, long long n) //x^n
{
	if (n == 1)
		return x % c;

	long long out = getRemainder(x, n / 2);
	if (n % 2 == 0)
		return (out * out) % c;
	else
		return (out * out) % c * x % c;
}


int main()
{
	cin >> a >> b >> c;

	cout << getRemainder(a, b);
}