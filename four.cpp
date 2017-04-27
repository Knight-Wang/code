// four.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int dp[105], w[105], v[105], n, m;

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> w[i] >> v[i];
	}
	for (int i = n - 1; i >= 0; i--)
	{
		for (int j = m; j >= w[i]; j--)
		{
			dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
		}
	}
	cout << dp[m] << endl;
	//system("pause");
	return 0;
}

