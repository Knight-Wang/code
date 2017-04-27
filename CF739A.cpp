// CF739A.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <iostream>
#include <cstdio>
using namespace std;
const int INF = 0x3f3f3f3f;
int n, m, k = INF, l, r;
int min(int a, int b)
{
	return a < b ? a : b;
}
int main()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		scanf("%d %d", &l, &r);
		k = min(k, r - l + 1);
	}
	cout << k << endl;
	for (int i = 0; i < n; i++)
	{
		printf("%d ", i % k);
	}
	puts("");
	return 0;
}

