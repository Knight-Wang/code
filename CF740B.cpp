// CF740B.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <iostream>
#include <cstdio>
using namespace std;
int a[105], n, m;
int s[105][105];
int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n - i + 1; j++)
		{
			s[i][j] = s[i][j - 1] + a[i + j - 1];
		}
	}
	int l, r;
	int res = 0;
	while (m--)
	{
		scanf("%d %d", &l, &r);
		if (s[l][r - l + 1] > 0)
			res += s[l][r - l + 1];
	}
	printf("%d\n", res);
	//system("pause");
	return 0;
}

