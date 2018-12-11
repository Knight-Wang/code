// CF_round_402_D.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
using namespace std;

int a[200005], n, m;
string s, p;

bool check(int x)
{
	string tmp = s;
	for (int i = 0; i < x; i++)
	{
		tmp[a[i] - 1] = '*';
	}
	int i = 0, j = 0;
	while (i < n && j < m)
	{
		if (tmp[i] != p[j])
			i++;
		else
		{
			i++;
			j++;
		}
	}
	return j == m;
}

int search()
{
	int l = 0, r = n - 1, m;
	int res = 0;
	while (l <= r)
	{
		m = (l + r) >> 1;
		if (check(m))
		{
			res = m;
			l = m + 1;
		}
		else
		{
			r = m - 1;
		}
	}
	return res;
}

int main()
{
	cin >> s >> p;
	n = s.length();
	m = p.length();
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	cout << search() << endl;
	//system("pause");
	return 0;
}

