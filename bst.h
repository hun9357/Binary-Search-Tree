#pragma once
#include<iostream>
#include<queue>

using namespace std;

class BST
{
private:
	class node {
	public:
		int data;
		int position;
		node*left;
		node*right;
		node(int x)
		{
			data = x;
			left = nullptr;
			right = nullptr;
		}
	};
	node*root;
public:
	BST()
	{
		root = nullptr;
	}
	void insert(int i)
	{
		insert(root, i);
	}
	void insert(node*&p, int i)
	{
		if (p == nullptr)
		{
			p = new node(i);
		}
		else
		{
			if (i > p->data)
			{
				insert(p->right, i);
			}
			else
			{
				insert(p->left, i);
			}
		}
	}
	int rmax(node*&p)
	{
		if (p == nullptr)
		{
			return 0;
		}
		if (p->right == nullptr)
		{
			int x = p->data;
			node*temp = p;
			p = p->left;
			delete temp;
			return x;
		}
		else
		{
			return rmax(p->right);
		}
	}
	void remove(int i)
	{
		remove(root, i);
	}

	void remove(node*&p, int i)
	{
		if (p == nullptr) {}
		if (i > p->data)
		{
			remove(p->right, i);
		}
		else if (i < p->data)
		{
			remove(p->left, i);
		}
		else
		{
			if (p->right == nullptr)
			{
				node*tmp = p;
				p = p->left;
				delete tmp;
			}
			else if (p->left == nullptr)
			{
				node*tmp = p;
				p = p->right;
				delete tmp;
			}
			else
			{
				int x = rmax(p->left);
				p->data = x;
			}
		}

	}
	void display()
	{
		display(root);
	}
	void display(node*p)
	{
		if (p == nullptr)
		{
		}
		else
		{
			cout << p->data << endl;
			display(p->left);
			display(p->right);
		}
	}
	void level()
	{
		int lp = 0;
		int	rp = 0;
		queue<node*> q;
		q.push(root);
		while (!q.empty())
		{
			node*p = q.front();
			q.pop();
			if (p->data == root->data)
			{
				cout << 1 << endl;
			}
			else if (p->data > root->data)
			{
				cout << 2*rp+1<< endl;
			}
			else
			{
				cout << 2*lp << endl;
			}
			if (p->left != nullptr)
			{
				q.push(p->left);
				lp++;
			}
			if (p->right != nullptr)
			{
				q.push(p->right);
				rp++;
			}
		}
	}
};
