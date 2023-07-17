#include <iostream>
#include <vector>

using namespace std;

class MaxHeap
{
private:
	vector<int> v;
public:
	void push(int);
	int pop();
	int compareChild(int);
	MaxHeap()
	{
		v.push_back(0);	//index는 1부터 시작.
	}
};

void MaxHeap::push(int x)
{
	v.push_back(x);
	int current = v.size() - 1;	//마지막 원소의 index;
	int parent = current / 2;
	while (v[current] > v[parent] && current != 1)
	{
		swap(v[current], v[parent]);
		current = parent;
		parent = current / 2;
	}
}

int MaxHeap::compareChild(int current)
{
	int x = current * 2;
	int y = x + 1;

	if (x <= 0 || y <= 0)								//입력값 오류.
		return -1;

	if (v.size() - 1 < x)									//자식이 없을 경우.
		return -1;

	if (v.size() - 1 >= x && v.size() - 1 < y)	//leftC만 존재.
		return 0;

	if (v[x] > v[y])
		return 0;
	else
		return 1;
}


int MaxHeap::pop()
{
	if (v.size() == 1)
		return 0;

	int output = v[1];
	swap(v[1], v[v.size() - 1]);
	v.erase(v.end() - 1);

	int current = 1;
	int leftC = current * 2;
	int rightC = leftC + 1;

	while (1)
	{
		int tmp = compareChild(current);

		if (tmp == -1)
			break;

		if (tmp == 0)
		{
			if (v[current] < v[leftC])
			{
				swap(v[current], v[leftC]);
				current = leftC;
				leftC = current * 2;
				rightC = leftC + 1;
			}
			else
				break;
		}

		if (tmp == 1)
		{
			if (v[current] < v[rightC])
			{
				swap(v[current], v[rightC]);
				current = rightC;
				leftC = current * 2;
				rightC = leftC + 1;
			}
			else
				break;
		}
	}

	return output;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	MaxHeap mheap;
	int n;
	cin >> n;
	while (n--)
	{
		int tmp;
		cin >> tmp;
		if (tmp == 0)
			cout << mheap.pop() << '\n';
		else
			mheap.push(tmp);
	}
}