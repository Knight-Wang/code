// 树的转换.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <string>
#include <stack>
using namespace std;

struct node
{
	char d;
	node * l;
	node * r;
};
string x;
int n;
stack<node * > s;

void build(int now, node * cur)
{
	if (now == n)
	{
		return;
	}
	if (x[now] >= 'A' && x[now] <= 'Z')
	{
		cur->d = x[now];
		build(now + 1, cur);
	}
	else if (x[now] == '(')
	{
		cur->l = new node();
		cur->l->l = cur->l->r = NULL;
		s.push(cur);
		build(now + 1, cur->l);
	}
	else if (x[now] == ')')
	{
		node * father = s.top();
		s.pop();
		build(now + 1, father);
	}
	else if (x[now] == ',')
	{
		cur->r = new node();
		cur->r->l = cur->r->r = NULL;
		build(now + 1, cur->r);
	}
}

void dfs(node * cur)
{
	if (!cur)
		return;
	if (cur->r)
		cout << "0 ";
	else
		cout << "1 ";
	cout << cur->d << " ";
	if (cur->l)
		cout << "0\n";
	else
		cout << "1\n";
	dfs(cur->l);
	dfs(cur->r);
}

int main()
{
	cin >> x;
	n = x.length();
	node * root = new node();
	root->l = root->r = NULL;
	s.push(root);
	build(0, root);
	dfs(root);
	//system("pause");
	return 0;
}

