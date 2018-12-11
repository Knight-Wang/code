// 简易24点.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

const char op[4] = { '+', '-', '*', '/' };
const int INF = 0x3f3f3f3f;

int a[3];
char c[2];
string s[3];

int trans(string x)
{
	if (x == "A") return 1;
	if (x == "10") return 10;
	if (x == "J") return 11;
	if (x == "Q") return 12;
	if (x == "K") return 13;
	return x[0] - '0';
}

bool cal(int x, int y, int & res, char c)
{
	if (c == '/')
	{
		if (y == 0 || x % y) return false;
		res = x / y;
		return true;
	}
	if (c == '+') res = x + y;
	if (c == '-') res = x - y;
	if (c == '*') res = x * y;
	return true;
}

int main()
{
	while (cin >> s[0] >> s[1] >> s[2])
	{
		for (int i = 0; i < 3; i++)
			a[i] = trans(s[i]);
		bool flag = false;
		sort(a, a + 3);
		do
		{
			if (flag)
				break;
			for (int i = 0; i < 4; i++)
			{
				if (flag)
					break;
				for (int j = 0; j < 4; j++)
				{
					c[0] = op[i]; c[1] = op[j];
					int res = INF;
					if (cal(a[0], a[1], res, c[0]))
					{
						int res2 = INF;
						if (cal(res, a[2], res2, c[1]))
						{
							if (res2 == 24) flag = true;
						}
					}
				}
			}
		} while (next_permutation(a, a + 3));
		if (flag)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	//system("pause");
	return 0;
}

