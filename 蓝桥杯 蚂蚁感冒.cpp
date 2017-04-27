// 蓝桥杯 蚂蚁感冒.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int n, a[55];
int main()
{
	cin >> n;
	cin >> a[0];
	bool dir = true;
	if (a[0] < 0)
		dir = false;
	bool flag = false;
	for (int i = 1; i < n; i++)
	{
		cin >> a[i];
		if (dir && a[i] < 0 && abs(a[i]) > a[0] ||
			!dir && a[i] > 0 && a[i] < abs(a[0]))
			flag = true;
	}
	if (!flag)
		puts("1");
	else
	{
		int cnt = 1;
		for (int i = 1; i < n; i++)
		{
			if (dir)
			{
				cnt += (a[i] < 0 && abs(a[i]) > a[0] || a[i] > 0 && a[i] < a[0]);
			}
			else
			{
				cnt += (a[i] > 0 && a[i] < abs(a[0]) || a[i] < 0 && a[i] < a[0]);
			}
		}
		cout << cnt << endl;
	}
	//system("pause");
	return 0;
}

