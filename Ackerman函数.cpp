// Ackerman函数.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAXM = 3;
const int MAXN = 1000;
int a[10 * MAXM][10 * MAXN], m, n;

int solve(int m, int n)
{
	if (a[m][n] != -1)
		return a[m][n];
	if (m == 0)
		return a[m][n] = n + 1;
	else if (n == 0)
		return a[m][n] = solve(m - 1, 1);
	return a[m][n] = solve(m - 1, solve(m, n - 1));
}
int main()
{
	cin >> m >> n;
	memset(a, -1, sizeof(a));
	cout << solve(m, n) << endl;
	//system("pause");
	return 0;
}