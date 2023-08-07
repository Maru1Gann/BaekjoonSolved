#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <string>
using namespace std;

class DualPriorityQueue
{
private:
	priority_queue<int, vector<int>, less<int>> maxHeap;
	priority_queue<int, vector<int>, greater<int>> minHeap;
	map<int, int> countMap;
public:
	void push(int);
	pair<int, bool> popMax();
	pair<int, bool> popMin();
};

void DualPriorityQueue::push(int num)
{
	maxHeap.push(num);
	minHeap.push(num);

	auto iter = countMap.find(num);
	if (iter != countMap.end())
		iter->second++;
	else
		countMap.insert({ num, 1 });
}

pair<int, bool> DualPriorityQueue::popMax()
{
	if (maxHeap.empty())
		return { 0,false };

	while (1)
	{
		int top = maxHeap.top(); maxHeap.pop();
		if (countMap[top] > 0)
		{
			countMap[top]--;
			return { top,true };
		}
		if (maxHeap.empty())
			return { 0,false };
	}
}

pair<int, bool> DualPriorityQueue::popMin()
{
	if (minHeap.empty())
		return { 0,false };

	while (1)
	{
		int top = minHeap.top(); minHeap.pop();
		if (countMap[top] > 0)
		{
			countMap[top]--;
			return { top,true };
		}
		if (minHeap.empty())
			return { 0,false };
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;
	while (t--)
	{
		int k;
		cin >> k;
		cin.ignore();
		DualPriorityQueue dpq;
		while (k--)
		{
			string input;
			getline(cin, input);
			if (input[0] == 'I')
				dpq.push(stoi(input.substr(1)));
			else if (input[0] == 'D')
			{
				int input2 = stoi(input.substr(1));
				if (input2 == -1)
					dpq.popMin();
				else if (input2 == 1)
					dpq.popMax();
			}
		}

		pair<int, bool> output1 = dpq.popMax();
		pair<int, bool> output2 = dpq.popMin();
		if (output1.second && output2.second)
			cout << output1.first << ' ' << output2.first;
		else if (output1.second && !output2.second)
			cout << output1.first << ' ' << output1.first;
		else if (!output1.second && output2.second)
			cout << output2.first << ' ' << output2.first;
		else
			cout << "EMPTY";
		cout << '\n';
	}
}
