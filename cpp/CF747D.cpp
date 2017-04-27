// CF747D.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <queue>
#include <functional>
#include <vector>
using namespace std;

int a[200005], n, k;
int find_non_negtive_start(int pos)
{
	for (int i = pos; i < n; i++)
	{
		if (a[i] >= 0)
			return i;
	}
	return -1;
}
int find_non_negtive_end(int pos)
{
	for (int i = pos; i < n; i++)
	{
		if (a[i] < 0)
			return i - 1;
	}
	return -1;
}
int find_negtive_start(int pos)
{
	for (int i = pos; i < n; i++)
	{
		if (a[i] < 0)
			return i;
	}
	return -1;
}
int find_negtive_end(int pos)
{
	for (int i = pos; i < n; i++)
	{
		if (a[i] >= 0)
			return i - 1;
	}
	return -1;
}
int main()
{
	priority_queue<int, vector<int>, greater<int> > q;
	cin >> n >> k;
	int cnt = 0, cnt_negtive = 0;
	int start = -1, begin = -1;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		if (a[i] < 0)
		{
			cnt++;
			if (begin == -1)
				begin = i;
		}
		else
		{
			if (begin != -1 && start == -1)
				start = i;
		}
	}
	if (cnt > k)
	{
		cout << "-1" << endl;
		return 0;
	}
	if (cnt == 0)
	{
		cout << "0" << endl;
		return 0;
	}
	if (start == -1)
	{
		cout << "1" << endl;
		return 0;
	}
	if (begin == -1)
	{
		cout << "0" << endl;
		return 0;
	}
	cnt_negtive = cnt;
	cnt = 0;
	while (1)
	{
		int pos = find_negtive_end(begin + 1);
		if (pos == -1)
		{
			cnt++;
			break;
		}
		cnt++;
		begin = find_negtive_start(pos + 1);
		if (begin == -1)
			break;
	}
	cnt *= 2;
	int res = -1;
	while (1)
	{
		int pos = find_non_negtive_end(start + 1);
		if (pos == -1)
		{
			res = n - start;
			break;
		}
		q.push(pos - start + 1);
		start = find_non_negtive_start(pos + 1);
		if (start == -1)
		{
			break;
		}
	}
	k -= cnt_negtive;
	while (!q.empty())
	{
		if (k >= q.top())
		{
			k -= q.top();
			q.pop();
			cnt -= 2;
		}
		else
		{
			break;
		}
	}
	if (k >= res) 
	{
		cnt--;
	}
	cout << cnt << endl;
	//system("pause");
	return 0;
}

