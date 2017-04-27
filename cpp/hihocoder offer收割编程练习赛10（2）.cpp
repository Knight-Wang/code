// hihocoder offer收割编程练习赛10（2）.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
using namespace std;

const int mod = 1e9 + 7;

int n, dp[100005][2][4];

int dfs(int cur, int a, int l)
{ 
	if (cur == n)
		return 1;
	if (dp[cur][a][l] != -1)
		return dp[cur][a][l];
	int cnt = 0;
	if (a < 1)
	{
		if (l < 2)
		{
			cnt = (cnt + dfs(cur + 1, a + 1, 0)) % mod;
			cnt = (cnt + dfs(cur + 1, a, l + 1)) % mod;
			cnt = (cnt + dfs(cur + 1, a, 0)) % mod;
		}		  
		else	  
		{		  
			cnt = (cnt + dfs(cur + 1, a + 1, 0)) % mod;
			cnt = (cnt + dfs(cur + 1, a, 0)) % mod;
		}
	}
	else
	{
		if (l < 2)
		{
			cnt = (cnt + dfs(cur + 1, a, l + 1)) % mod;
			cnt = (cnt + dfs(cur + 1, a, 0)) % mod;
		}		   
		else	  
		{		  
			cnt = (cnt + dfs(cur + 1, a, 0)) % mod;
		}
	}
	return dp[cur][a][l] = cnt;
}

int main()
{
	cin >> n;
	memset(dp, -1, sizeof(dp));
	cout << dfs(0, 0, 0) << endl;
    //system("pause");
	return 0;
}