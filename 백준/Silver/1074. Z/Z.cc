#include <iostream>
using namespace std;

int power2(int a)
{
	if (a == 0)
		return 1;
	return 2 * power2(--a);
}

int get(int len, int r, int c)
{
	if (len == 1)
		return 0;

	int half = len / 2;
	int x = c + 1 - half;
	int y = -(r + 1 - half);
	if (x <= 0)
		x--;
	if (y >= 0)
		y++;

	int offset = half * half;
	if (x > 0 && y > 0)			//1사분면
		offset;
	else if (x < 0 && y > 0)	//2사분면
		offset = 0;
	else if (x < 0 && y < 0)	//3사분면
		offset = offset * 2;
	else								//4사분면
		offset = offset * 3;

	return offset + get(half, r%half, c%half);
}



int main()
{
	int n, r, c;
	cin >> n >> r >> c;
	cout << get(power2(n), r, c);
}