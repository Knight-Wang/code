// CF628C.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int n, m;
string s;
char res[100005];
int main()
{
	cin >> n >> m >> s;
	int index = -1;
	for (int i = 0; i < n; i++)
	{
		int tmp = s[i] - 'a';
		res[i] = 'a';
		if ('z' - s[i] > tmp)
		{
			tmp = 'z' - s[i];
			res[i] = 'z';
		}
		if (m > tmp)
			m -= tmp;
		else
		{
			res[i] = (s[i] - m >= 'a' ? s[i] - m : s[i] + m);
			index = i;
			m = 0;
			break;
		}
	}
	if (m)
	{
		puts("-1");
	}
	else
	{
		for (int i = 0; i <= index; i++)
		{
			printf("%c", res[i]);
		}
		for (int i = index + 1; i < n; i++)
		{
			printf("%c", s[i]);
		}
		puts("");
	}
	//system("pause");
	return 0;
}

