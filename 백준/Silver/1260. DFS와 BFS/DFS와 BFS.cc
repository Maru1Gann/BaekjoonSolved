#include <iostream>
#include <stack>
#include <queue>
using namespace std;

class node
{
public:
	int indx;
	node* next;
	node(int a = 0, node* next = NULL)
	{
		indx = a;
		this->next = next;
	}
};

class adjlist
{
private:
	int n, v;
	node* list;

public:
	adjlist(int n, int v)
	{
		this->n = n;
		this->v = v;
		list = new node[n+1];
		for (int i = 0; i <= n; i++)
			list[i].indx = i;
	}

	void push(int a, int b)
	{
		node* tmp = &list[a];

		while (tmp->next && b >= tmp->next->indx)
		{
			if (tmp->next->indx == b)
				return;
			tmp = tmp->next;
		}
			
		if (tmp->next == NULL)
			tmp->next = new node(b);
		else
			tmp->next = new node(b, tmp->next);
	}

	void print() 
	{
		for (int i = 0; i <= n; i++)
		{
			node* tmp = &list[i];
			cout << tmp->indx << " ";
			while (1)
			{
				if (!tmp->next)
					break;
				tmp = tmp->next;
				cout << tmp->indx << " ";
			}
			cout << '\n';
		}
	}

	void DFS()
	{
		bool* visited = new bool[n+1] {0};
		stack<int> stck;
		int cur = v;
		while (1)
		{
			node* tmp = &list[cur];

			while (tmp->next && visited[tmp->indx])
				tmp = tmp->next;

			if (!visited[tmp->indx])
			{
				stck.push(cur);
				cur = tmp->indx;
				visited[cur] = true;
				cout << cur << ' ';
			}
			else if (!stck.empty())
			{
				cur = stck.top(); stck.pop();
			}
			else
				break;
		}
	}

	void BFS()
	{
		bool* visited = new bool[n + 1] {0};
		queue<int> Q;
		Q.push(v);
		visited[v] = true;

		while (!Q.empty())
		{
			int cur = Q.front(); Q.pop();
			visited[cur] = true;
			cout << cur << ' ';
			node* tmp = &list[cur];

			while (tmp->next)
			{
				tmp = tmp->next;
				if (!visited[tmp->indx])
				{
					Q.push(tmp->indx);
					visited[tmp->indx] = true;
				}
			}

		}//End of while(!Q.empty())

	}	//End of BFS()

}; //End of adjlist class


int main() 
{
	int n, m, v;
	cin >> n >> m >> v;
	adjlist list(n, v);
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		list.push(a, b);
		list.push(b, a);
	}

	//cout << "\n";
	//list.print();
	//cout << "\n\n";
	list.DFS();
	cout << "\n";
	list.BFS();
}