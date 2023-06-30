#include <iostream>
#include <vector>
using namespace std;

class priority_heap
{
private:
	vector<unsigned int> v;
public:
	void push(unsigned int x);
	unsigned int pop();
	priority_heap()
	{
		v.push_back(0);
	}
};

void priority_heap::push(unsigned int x)
{
	v.push_back(x);
	int indx = v.size() - 1;

	while (indx > 1)
	{
		int parent = indx / 2;
		if (v[indx] <= v[parent])
		{
			swap(v[indx], v[parent]);
			indx = parent;
		}
		else
			break;
	}

	//cout << "pushed:";
	//for (int i = 1; i < v.size(); i++)
	//{
	//	cout << v[i] << ' ';
	//}
	//cout << '\n';
}

unsigned int priority_heap::pop()
{
	int indx = v.size() - 1;
	if (indx == 0)
		return 0;

	unsigned int rtrn = v[1];
	swap(v[indx], v[1]);
	v.erase(--v.end());

	indx = 1;
	int child = indx * 2;
	while (child <= v.size()-1) //마지막 원소인 경우까지만.
	{
		if (child == v.size() - 1) //마지막 원소인 경우.
		{
			if (v[indx] > v[child])
				swap(v[indx], v[child]);
			break;
		}									//크기 작으면 바꾸고 끝.
		else
		{
			if (v[child + 1] < v[child]) //right < left
				child++;						//left로 이동.
			if (v[indx] > v[child])			//child와 비교.
			{
				swap(v[indx], v[child]);
				indx = child;
				child = indx * 2;
			}
			else 
				break;							//비교했는데 indx가 child들보다 작으면 종료.
		}
	}

	//cout << "popped:";
	//for (int i = 1; i < v.size(); i++)
	//{
	//	cout << v[i] << ' ';
	//}
	//cout << '\n';

	return rtrn;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	priority_heap pheap;
	while(n--)
	{
		int x;
		cin >> x;
		if (x == 0)
			cout << pheap.pop() << '\n';
		else
			pheap.push(x);
	}
}