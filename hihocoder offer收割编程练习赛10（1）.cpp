// hihocoder offer收割编程练习赛10（1）.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int main()
{
	int t;
	cin >> t;
	string str;
	for (int i = 0; i < t; i++)
	{
		cin >> str;
		int n = str.length();
		int cnt_a = 0;
		bool flag = true;
		for (int j = 0; j < n; j++)
		{
			if (str[j] == 'A')
			{
				cnt_a++;
				if (cnt_a > 1)
				{
					flag = false;
					break;
				}
			}
			if (str[j] == 'L')
			{
				if (j <= n - 3 && str[j + 1] == 'L' && str[j + 2] == 'L')
				{
					flag = false;
					break;
				}
			}
		}
		cout << (flag ? "YES" : "NO") << endl;
	}
	//system("pause");
	return 0;
}

