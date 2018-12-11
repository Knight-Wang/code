// 蓄水池.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int a[1005], n, t;
int main()
{
	cin >> t;
	while (t--)
	{
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &a[i]);
		}
		int max_pos = 0;
		for (int i = 0; i < n; i++)
		{
			if (a[i] > a[max_pos])
			{
				max_pos = i;
			}
		}
		int cnt = 0, pos = 0;
		for (int i = 1; i <= max_pos; i++)
		{
			if (a[i] >= a[pos])
			{
				cnt += (i - pos) * a[pos];
				pos = i;
			}
		}
		pos = n - 1;
		for (int i = pos - 1; i >= max_pos; i--)
		{
			if (a[i] >= a[pos])
			{
				cnt += (pos - i) * a[pos];
				pos = i;
			}
		}
		cout << cnt << endl;
	}
	//system("pause");
	return 0;
}

