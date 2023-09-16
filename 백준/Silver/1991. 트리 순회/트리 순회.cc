#include <iostream>
#include <queue>
#include <stack>
using namespace std;

int n;

class Node
{
public:
	char name;
	Node* leftC = NULL;
	Node* rightC = NULL;
	Node(char name)
	{
		this->name = name;
	}
};

class Tree 
{
public:
	Node* root;
	void push(Node* node, char leftC, char rightC)
	{
		if (leftC != '.')
			node->leftC = new Node(leftC);
		if (rightC != '.')
			node->rightC = new Node(rightC);
	}
	void make(char** input)
	{
		this->root = new Node(input[0][0]);
		push(this->root, input[0][1], input[0][2]);
		queue<Node*> q;
		q.push(root->leftC);
		q.push(root->rightC);

		for (int i = 1; i < n; i++)
		{
			int count = 0;
			while (1)
			{
				if (q.front() == NULL)
				{
					q.pop();
					continue;
				}
				if (q.empty() || q.front()->name == input[i][0] || count > q.size())
					break;
				q.push(q.front());
				q.pop();
				count++;
			}

			if (q.empty())
				break;
			Node* tmp = q.front(); q.pop();
			push(tmp, input[i][1], input[i][2]);
			q.push(tmp->leftC);
			q.push(tmp->rightC);
		}
	}

	void preorder(Node* node)
	{
		if (!node)
			return;
		cout << node->name;
		preorder(node->leftC);
		preorder(node->rightC);
	}
	void inorder(Node* node)
	{
		if (!node)
			return;
		inorder(node->leftC);
		cout << node->name;
		inorder(node->rightC);
	}
	void postorder(Node* node)
	{
		if (!node)
			return;
		postorder(node->leftC);
		postorder(node->rightC);
		cout << node->name;
	}
};



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	char** input = new char*[n];

	for (int i = 0; i < n; i++)
	{
		input[i] = new char[3];
		for (int j = 0; j < 3; j++)
			cin >> input[i][j];
	}

	Tree tree;
	tree.make(input);
	tree.preorder(tree.root);
	cout << '\n';
	tree.inorder(tree.root);
	cout << '\n';
	tree.postorder(tree.root);
}