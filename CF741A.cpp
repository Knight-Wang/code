// CF741A.cpp : 定义控制台应用程序的入口点。
//
//#include "stdafx.h"
#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
int a[105];
bool vis[105];
int n, tmp = 0;
int gcd(int a, int b)
{
	if (b == 0)
		return a;
	return gcd(b, a % b);
}
int lcm(int a, int b)
{
	return a / gcd(a, b) * b;
}
void dfs(int cur)
{	
	tmp++;
	vis[cur] = true;
	if (vis[a[cur]])
		return;
	dfs(a[cur]);
}
int main()
{
	cin >> n;
	bool flag = false;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		if (vis[a[i]])
		{
			flag = true;
		}
		else
		{
			vis[a[i]] = true;
		}
	}
	if (flag)
	{
		cout << "-1" << endl;
		//system("pause");
		return 0;
	}
	memset(vis, 0, sizeof(vis));
	int res = 1;
	for (int i = 1; i <= n; i++)
	{
		if (vis[a[i]])
		{
			continue;
		}
		else
		{
			tmp = 0;
			dfs(a[i]);
			if (!(tmp & 1))
				tmp >>= 1;
			res = lcm(res, tmp);
		}
	}
	cout << res << endl;
	//system("pause");
	return 0;
}

