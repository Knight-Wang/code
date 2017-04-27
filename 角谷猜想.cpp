// 角谷猜想.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	int n, x;
	cin >> n;
	while (n--)
	{
		cin >> x;
		int cnt = 0;
		while (x != 1)
		{
			if (x & 1)
			{
				x = x * 3 + 1;
				cnt++;
			}
			else
			{
				x >>= 1;
			}
		}
		cout << cnt << endl;
	}
	//system("pause");
	return 0;
}

