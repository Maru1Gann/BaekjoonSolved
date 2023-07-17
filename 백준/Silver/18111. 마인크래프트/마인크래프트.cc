#include <iostream>
#include <algorithm>
using namespace std;


//높이 0~256
//설치 1초 제거 2초


int check(int* floor, int level, int b, int size) { //높이 받아서 만드는데 걸리는 시간 반환
	int sec = 0;
	for (int i = size - 1; i >= 0; i--) {
		if (floor[i] > level) { //땅파기
			b += floor[i] - level;
			sec += (floor[i] - level)*2;
		}
		else if (floor[i] < level && b >= level - floor[i]){ //쌓기
			b -= level - floor[i];
			sec += level - floor[i];
		}
	}

	return sec;
}



int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m, b; //n세로 m가로 b가진 블럭
	cin >> n >> m >> b;
	int size = n * m;

	int* floor = new int[size];

	int sum = 0;
	int min = 256;

	for (int i = 0; i < size; i++) {
		cin >> floor[i];
		sum += floor[i];
		if (floor[i] < min)
			min = floor[i];
	}
		

	sort(floor, floor + size);
	

	int max = (sum + b) / size;
	if (max > 256)
		max = 256;


	int cur, prev, out1, out2;
	int level = min;
	cur = check(floor, level, b, size);
	out1 = cur; out2 = level;
	while (level < max) {
		prev = cur;
		cur = check(floor, ++level, b, size);
		if (cur <= out1)
		{
			out1 = cur;
			out2 = level;
		}
	}


	cout << out1 << " " << out2;

 }