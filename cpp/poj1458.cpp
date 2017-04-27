// poj1458.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <string>
using namespace std;

int dp[1005][1005];
int main()
{
	string x, y;
	while (cin >> x >> y)
	{
		memset(dp, 0, sizeof(dp));
		int lx = x.length();
		int ly = y.length();
		for (int i = 1; i <= lx; i++)
		{
			for (int j = 1; j <= ly; j++)
			{
				if (x[i - 1] == y[j - 1])
				{
					dp[i][j] = dp[i - 1][j - 1] + 1;
				}
				else
				{
					dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
				}
			}
		}
		cout << dp[lx][ly] << endl;
	}
	system("pause");
	return 0;
}

