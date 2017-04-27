// hdu5122.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <iostream>
#include <cstdio>
using namespace std;

int a[1000005], n, t;

int main()
{
	int temp;
	int j = 0;
	cin >> t;
	while (t--)
	{
		scanf("%d", &n);
		int cnt = 0;
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &a[i]);
		}
		int minn = n + 1;
		for (int i = n - 1; i >= 0; i--)
		{
			if (a[i] < minn)
				minn = a[i];
			else
				cnt++;
		}
		printf("Case #%d: %d\n", ++j, cnt);
	}
	//system("pause");
	return 0;
}

