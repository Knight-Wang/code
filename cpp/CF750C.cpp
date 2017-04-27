// CF750C.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;

int n, minn = -INF, maxn = INF, c, x;
int main()
{
	scanf("%d", &n);
	bool flag = true;
	for (int i = 0; i < n; i++)
	{
		scanf("%d %d", &c, &x);
		if (x == 1)
		{
			minn = max(minn, 1900);
		}
		else if (x == 2)
		{
			maxn = min(maxn, 1899);
		}
		maxn += c;
		minn += c;
		if (maxn < minn)
		{
			flag = false;
			break;
		}
	}
	if (!flag)
		puts("Impossible");
	else if (maxn >= INF - 2e7)
		puts("Infinity");
	else
		printf("%d\n", maxn);
	//system("pause");
	return 0;
}

