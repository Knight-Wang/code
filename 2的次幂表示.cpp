// 2的次幂表示.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int a[16], n;
void init()
{
	for (int i = 0; i <= 15; i++)
	{
		a[i] = (1 << i);
	}
}
void dfs(int n)
{
	if (n <= 1)
	{
		if (n == 1)
			cout << "2";
		else
			cout << "2(0)";
		return;
	}
	int res = lower_bound(a, a + 16, n) - a;
	int tmp = a[res] > n ? res - 1 : res;
	int cnt = 0;
	for (int i = tmp; i >= 0; i--)
	{
		int fuck = a[i];
		if (n & fuck)
		{
			//cout << fuck << endl;
			cnt += fuck;
			if (i != 0 && i != 1)
				cout << "2(";
			dfs(i);
			if (i != 0 && i != 1)
			    cout << ")";
			if (cnt != n)
				cout << "+";
		}
	}
}
int main()
{
	cin >> n;
	if (n == 1)
		cout << "2(0)" << endl;
	else
	{
		init();
		dfs(n);
	}
	//system("pause");
	return 0;
}

