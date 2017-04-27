// CF_round_402_B.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <cstdio>
#include <string>
#include <iostream>
using namespace std;

int main()
{
	string s;
	int t;
	cin >> s >> t;
	int n = s.length();
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		if (s[i] == '0')
			cnt++;
	}
	if (cnt >= t)
	{
		int f = 0;
		int num0 = 0;
		for (int i = n - 1; i >= 0; i--)
		{
			if (s[i] == '0')
			{
				num0++;
				if (num0 == t)
					break;
			}
			else
			{
				f++;
			}
		}
		cout << f << endl;
	}
	else
		cout << n - 1 << endl;
	system("pause");
	return 0;
}

