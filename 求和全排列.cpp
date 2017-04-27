// 求和全排列.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int n, m;
int a[1005];

int dfs(int cur, int rem, int flag)
{
	if (rem == 0)
	{
		if (flag)
		{
			for (int i = 0; i < cur - 1; i++)
				cout << a[i] << "+";
			cout << a[cur - 1] << endl;
		}
		return 1;
	}
	int cnt = 0;
	for (int i = min(a[cur - 1], rem); i >= 1; i--)
	{
		a[cur] = i;
		cnt += dfs(cur + 1, rem - i, flag);
	}
	return cnt;
}

int main()
{
	cin >> n >> m;
	int cnt = 0;
	for (int i = min(n, m); i >= 1; i--)
	{
		a[0] = i;
		cnt += dfs(1, n - i, 0);
	}
	cout << cnt << endl;
	for (int i = min(n, m); i >= 1; i--)
	{
		a[0] = i;
		dfs(1, n - i, 1);
	}
	//system("pause");
	return 0;
}

