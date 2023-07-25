#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;


class AbsoluteHeap
{
private:
	vector<int> v;
public:
	AbsoluteHeap()
	{
		v.push_back(0);		// 0번 인덱스 사용 안함.
	}
	void push(int);
	int pop();
	int checkChild(int);
};

void AbsoluteHeap::push(int a)
{
	v.push_back(a);
	int current = v.size() - 1;
	int parent = current / 2;
	while (parent >= 1)
	{
		if (abs(v[parent]) > abs(v[current]) || 
			(abs(v[parent]) == abs(v[current]) && v[parent] > v[current]) )
		{
			swap(v[parent], v[current]);
			current = parent;
			parent = current / 2;
		}
		else
			break;
	}
}

int AbsoluteHeap::checkChild(int current)
{
	int child = current * 2;

	if (child > v.size() - 1)
		return -1;
	else if (child + 1 > v.size() - 1)
		return child;


	if (abs(v[child]) < abs(v[child + 1]))
		return child;
	else if (abs(v[child]) == abs(v[child + 1]) && v[child] < v[child + 1])
		return child;
	else
		return child+1;
}


int AbsoluteHeap::pop()
{
	if (v.size() == 1)
		return 0;

	int popped = v[1];
	swap(v[1], v[v.size() - 1]);
	v.erase(v.end() - 1);
	int current = 1;
	int child = checkChild(current);
	while (child != -1)
	{
		if (abs(v[current]) > abs(v[child]) || 
			(abs(v[current]) == abs(v[child]) && v[current] > v[child]))
		{
			swap(v[current], v[child]);
			current = child;
			child = checkChild(current);
		}
		else
			break;
	}

	return popped;
}


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	AbsoluteHeap h;
	while (n--)
	{
		int input;
		cin >> input;
		if (input == 0)
			cout << h.pop() << '\n';
		else
			h.push(input);
	}
}