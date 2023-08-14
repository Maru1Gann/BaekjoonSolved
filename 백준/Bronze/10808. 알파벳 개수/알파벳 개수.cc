#include <iostream>
using namespace std;

int main()
{
	string tmp;
	cin >> tmp;
	int alphabet[26]{ 0 };
	for (int i = 0; i < tmp.length(); i++)
		alphabet[tmp[i] - 'a']++;
	for (int i = 0; i < 26; i++)
		cout << alphabet[i] << ' ';
}