// 蓝桥杯 数字游戏.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;

ll n, k, t, s = 1;

int main()
{
	cin >> n >> k >> t;
	for (ll i = 1; i < t; i++)
	{
		ll tmp = 0;
		if ((i * n) & 1)
		{
			tmp = i * n + 1;
			tmp /= 2;
			tmp %= k;
			tmp *= i * n % k;
		}
		else
		{
			tmp = i * n;
			tmp /= 2;
			tmp %= k;
			tmp *= (i * n + 1) % k;
		}
		tmp += 1;
		tmp %= k;
		s += tmp;
	}
	cout << s << endl;
	//system("pause");
	return 0;
}

