// CF_round386_D.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <iostream>
#include <cstdio>
using namespace std;
int min(int a, int b)
{
	return a < b ? a : b;
}
int n, k, a, b;
char res[100005];
int main()
{
	cin >> n >> k >> a >> b;
	bool flag = true;
	int cnt = 0;
	int sta = 0;
	if (a > b)
		sta = 1;
	else
		sta = 2;
	while (a && b)
	{
		if (a > b)
		{
			if (sta == 1)
			{
				int x = 0;
				if (a < k)
				{
					x = a - b;
				}
				else
				{
					x = min(k, a - b);
				}
				for (int i = 0; i < x; i++)
				{
					res[cnt++] = 'G';
				}
				a -= x;
				sta = 2;
			}
			else
			{
				res[cnt++] = 'B';
				b--;
				sta = 1;
			}
		}
		else if (b > a)
		{
			if (sta == 2)
			{
				int x = 0;
				if (b < k)
				{
					x = b - a;
				}
				else
				{
					x = min(k, b - a);
				}
				for (int i = 0; i < x; i++)
				{
					res[cnt++] = 'B';
				}
				b -= x;
				sta = 1;
			}
			else
			{
				res[cnt++] = 'G';
				a--;
				sta = 2;
			}
		}
		else
		{
			if (sta == 1)
			{
				int x = 0;
				if (a < k)
				{
					x = a;
				}
				else
				{
					x = k;
				}
				for (int i = 0; i < x; i++)
				{
					res[cnt++] = 'G';
				}
				a -= x;
				sta = 2;
			}
			else
			{
				int x = 0;
				if (b < k)
				{
					x = b;
				}
				else
				{
					x = k;
				}
				for (int i = 0; i < x; i++)
				{
					res[cnt++] = 'B';
				}
				b -= x;
				sta = 1;
			}
		}
	}
	if (a)
	{
		if (a <= k)
		{
			for (int i = 0; i < a; i++)
			{
				res[cnt++] = 'G';
			}
		}
		else
		{
			cout << "NO" << endl;
			flag = false;
		}
	}
	else
	{
		if (b <= k)
		{
			for (int i = 0; i < b; i++)
			{
				res[cnt++] = 'B';
			}
		}
		else
		{
			cout << "NO" << endl;
			flag = false;
		}
	}
	if (flag)
	{
		for (int i = 0; i < n; i++)
		{
			cout << res[i];
		}
		cout << endl;
	}
	//system("pause");
	return 0;
}

