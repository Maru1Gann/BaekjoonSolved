#include <iostream>
#include <string>
using namespace std;

class ACarray 
{
private:
	int n;
	int* array;
	int front;
	int rear;
	bool flipped;
public:
	ACarray(int n, string arr)
	{
		this->n = n;
		array = new int[n];
		front = 0;
		rear = n - 1;
		flipped = false;

		int j = 0;
		for (int i = 0; i < arr.length(); i++)
		{
			if (!(arr[i] >= '0' && arr[i] <= '9'))
				continue;

			string tmp;
			while (arr[i] >= '0' && arr[i] <= '9')
			{
				tmp += arr[i];
				i++;
			}
			array[j] = stoi(tmp);
			j++;
		}
	}
	void R();
	bool D();		//error시 false 반환
	void print();

	~ACarray()
	{
		delete[] array;
	}
};

void ACarray::R()
{
	flipped = !flipped;
}

bool ACarray::D()
{
	if (front > rear)
		return false;
	if (n <= 0)
		return false;

	if (flipped == false)
		front++;
	else
		rear--;
	n--;
	return true;
}

void ACarray::print()
{
	cout << '[';
	if (n > 0)
	{
		if (flipped == false)
		{
			cout << array[front];
			for (int i = front + 1; i <= rear; i++)
				cout << ',' << array[i];
		}
		else
		{
			cout << array[rear];
			for (int i = rear - 1; i >= front; i--)
				cout << ',' << array[i];
		}
	}
	cout << "]\n";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;
	cin.ignore();
	while (t--)
	{
		string p;
		int n;
		string arr;
		cin >> p >> n >> arr;


		ACarray* RD = new ACarray(n, arr);
		bool success = true;
		for (int i = 0; i < p.length(); i++)
		{
			if (p[i] == 'R')
				RD->R();
			else if (p[i] == 'D')
				success = RD->D();
		}
		//cout << "\t\t";
		if (success)
			RD->print();
		else
			cout << "error\n";

		delete RD;
	}
}