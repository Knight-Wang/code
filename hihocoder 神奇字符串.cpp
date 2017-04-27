// hihocoder 神奇字符串.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
#include <cstring>
using namespace std;

const int INF = 0x3f3f3f3f;

void str_swap(string & x, int i, int j)
{
	char tmp = x[i];
	x[i] = x[j];
	x[j] = tmp;
}

int cal(string x, string y)
{
	int s = x.length();
	int t = y.length();
	if (s != t)
		return INF;
	int cnt = 0;
	for (int i = 0; i < t; i++)
	{
		if (x[i] == y[i])
			continue;
		bool flag = false;
		for (int j = i + 1; j < s; j++)
		{
			if (x[j] == y[i])
			{
				for (int k = j; k > i; k--)
				{
					str_swap(x, k, k - 1);
					cnt++;
				}
				flag = true;
				break;
			}
		}
		if (!flag)
		{
			return INF;
		}
	}
	return cnt;
}

int main()
{
	string a, b;
	cin >> a >> b;
	int n = b.length();
	int minn = INF;
	for (int i = 0; i <= n; i++)
	{
		for (char c = 'a'; c <= 'z'; c++)
		{
			string tmp = b;
			tmp.insert(i, 1, c);
			minn = min(minn, cal(a, tmp));
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (char c = 'a'; c <= 'z'; c++)
		{
			string tmp = b;
			tmp.erase(i, 1);
			minn = min(minn, cal(a, tmp));
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (char c = 'a'; c <= 'z'; c++)
		{
			string tmp = b;
			tmp[i] = c;
			minn = min(minn, cal(a, tmp));
		}
	}
	cout << minn << endl;
	//system("pause");
	return 0;
}

