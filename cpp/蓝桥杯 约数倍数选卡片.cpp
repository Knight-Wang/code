// 蓝桥杯 约数倍数选卡片.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 105;
int a[MAXN], b[MAXN], m = 0;
vector<int> ok[MAXN];

bool check(int x, int y)
{
	int p = min(x, y);
	int q = max(x, y);
	return !(q % p);
}

void init()
{
	for (int i = 1; i < MAXN; i++)
	{
		if (a[i])
		{
			for (int j = 1; j < MAXN; j++)
			{
				if (a[j] && check(i, j))
					ok[i].push_back(j);
			}
		}
	}
}

bool dfs(int last)
{
	for (int i = ok[last].size() - 1; i >= 0; i--)
	{
		int tmp = ok[last][i];
		if (a[tmp])
		{
			a[tmp]--;
			bool res = dfs(tmp);
			a[tmp]++;
			if (!res)
				return true;
		}
	}
	return false;
}

int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	string x;
	int t;
	stringstream s;
	getline(cin, x);
	s << x;
	while (s >> t)  a[t]++;
	init();
	s.clear();
	getline(cin, x);
	s << x;
	while (s >> b[m++]);
	m--;
	sort(b, b + m);
	int * end = unique(b, b + m);
	bool flag = true;
	for (int i = 0; i < end - b; i++)
	{
		a[b[i]]--;
		bool res = dfs(b[i]);
		a[b[i]]++;
		if (!res)
		{
			cout << b[i] << endl;
			flag = false;
			break;
		}
	}
	if (flag)
		cout << -1 << endl;
//	system("pause");
	return 0;
}
