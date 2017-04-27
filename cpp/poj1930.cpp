// poj1930.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

const int INF = 0x3f3f3f3f;

int gcd(int a, int b)
{
	return !b ? a : gcd(b, a % b);
}

int lcm(int a, int b)
{
	return a / gcd(a, b) * b;
}

int toNum(string s)
{
	int n = s.length();
	int res = 0;
	for (int i = 0; i < n; i++)
	{
		res += s[i] - '0';
		if (i != n - 1)
			res *= 10;
	}
	return res;
}

int main()
{
	string s;
	while (cin >> s, s != "0")
	{
		s = s.substr(2, s.length() - 5);
		int n = s.length();
		int minn = INF;
		int minm = 0;
		for (int i = 0; i < n; i++)
		{
			int x = toNum(s.substr(i, n - i));
			int y = 9;
			for (int j = 0; j < n - i - 1; j++)
			{
				y *= 10;
				y += 9;
			}
			for (int j = 0; j < i; j++)
			{
				y *= 10;
			}
			int p = toNum(s.substr(0, i));
			int q = 1;
			for (int j = 0; j < i; j++)
			{
				q *= 10;
			}
			int l = lcm(y, q);
			int tmp = l / y * x + l / q * p;
			int g = gcd(tmp, l);
			tmp /= g;
			l /= g;
			if (l < minn)
			{
				minn = l;
				minm = tmp;
			}
		}
		cout << minm << "/" << minn << endl;
	}
	//system("pause");
	return 0;
}

