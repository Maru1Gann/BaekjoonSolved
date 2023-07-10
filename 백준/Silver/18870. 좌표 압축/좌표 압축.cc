#include <iostream>
#include <set>
#include <map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	int* input = new int[n];

	for (int i = 0; i < n; i++)
		cin >> input[i];

	map<int, int> output;

	for (int i = 0; i < n; i++)
		output.insert({ input[i], 0});

	int count = 0;

	for (auto it = output.begin(); it != output.end(); it++)
		it->second = count++;

	for (int i = 0; i < n; i++)
		cout << output.find(input[i])->second << " ";
}