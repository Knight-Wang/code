// 四平方和.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int n;
int ok[5000005];
int main()
{
	cin >> n;
	for (int i = 0; i * i <= n; i++)
	{
		for (int j = 0; j * j <= n; j++)
		{
			if (i * i + j * j <= n)
				ok[i * i + j * j] = 1;
		}
	}
	bool flag = false;
	for (int i = 0; i * i <= n; i++)
	{
		for (int j = i; j * j <= n; j++)
		{
			if (!ok[i * i + j * j])
				continue;
			for (int k = j; k * k <= n; k++)
			{
				int tmp = n - i * i - j * j - k * k;
				int x = sqrt(tmp);
				if (x * x == tmp)
				{
					cout << i << " " << j << " " << k << " " << x << endl;
					flag = true;
					break;
				}
			}
			if (flag)
				break;
		}
		if (flag)
			break;
	}
	system("pause");
	return 0;
}

