// poj1163.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;


int a[105][105], n;
int dp[105];

int solve()
{
	for (int i = 0; i < n - 1; i++)
		dp[i] = a[n - 1][i];
	for (int i = n - 2; i >= 0; i--)
	{
		for (int j = 0; j <= i; j++)
			dp[j] = a[i][j] + max(dp[j], dp[j + 1]);
	}
	return dp[0];
}
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			cin >> a[i][j];
		}
	}
	cout << solve() << endl;
	//system("pause");
	return 0;
}

