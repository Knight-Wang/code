// GB2016B.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int n;
string tmp;
int a;
int main()
{
	cin >> n;
	int cnt = 0;
	bool flag = true;
	for (int i = 0; i < n; i++)
	{
		cin >> a >> tmp;
		if (i == 0 && tmp[0] != 'S')
			flag = false;
		if (i != 0 && cnt == 0 && tmp[0] != 'S')
			flag = false;
		if (i != 0 && cnt == 20000 && tmp[0] != 'N')
			flag = false;
		if (!flag)
			continue;
		if (tmp[0] == 'S')
		{
			if (cnt + a > 20000)
				flag = false;
			else
				cnt += a;
		}
		else if (tmp[0] == 'N')
		{
			if (cnt - a < 0)
				flag = false;
			else
				cnt -= a;
		}
	}
	if (cnt == 0 && flag)
	{
		puts("YES");
	}
	else
	{
		puts("NO");
	}
	//system("pause");
	return 0;
}

