// cz_vino和他的书架（新）.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <iostream>
#include <cstdio>
using namespace std;
int n, t[105], w[105], dp[205], s_t = 0;
int min(int a, int b)
{
	return a < b ? a : b;
}
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> t[i] >> w[i];
		s_t += t[i];
	}
	for (int i = 0; i <= s_t; i++)
	{
		dp[i] = s_t;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= s_t; j++)
		{
			if (j + t[i] + w[i] <= s_t)
				dp[j] = min(dp[j + t[i] + w[i]] - t[i], dp[j]);
		}
	}
	cout << dp[0] << endl;
	//system("pause");
	return 0;
}

