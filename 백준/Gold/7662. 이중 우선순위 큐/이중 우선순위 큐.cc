#include <iostream>
#include <set>
using namespace std;

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
		multiset<int> dpq;
		while (k--)
		{
			char input1;
			int input2;
			cin >> input1 >> input2;
			if (input1 == 'I')
				dpq.insert(input2);
			else if (input1 == 'D' && input2 == -1 && !dpq.empty())
				dpq.erase(dpq.begin());
			else if (input1 == 'D' && input2 == 1 && !dpq.empty())
				dpq.erase(--dpq.end());
		}
		if (dpq.empty())
			cout << "EMPTY";
		else
		{
			cout << * --dpq.end() << ' ' << *dpq.begin();
		}
		cout << '\n';
	}
}