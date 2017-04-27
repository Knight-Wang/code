// hihocoder offer收割编程练习赛11（1）.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;

int ch[100005], ci[100005], co[100005];

bool check(int pos, int a, int b, int c)
{
	return ch[pos] <= a - 2 && ci[pos] <= b - 1 && co[pos] <= c - 1;
}

int main()
{
	string s;
	cin >> s;
	int n = s.length();
	ch[0] += (s[0] == 'h');
	ci[0] += (s[0] == 'i');
	co[0] += (s[0] == 'o');
	int last = 0, min_len = INF;
	for (int i = 1; i < n; i++)
	{
		ch[i] = ch[i - 1] + (s[i] == 'h');
		ci[i] = ci[i - 1] + (s[i] == 'i');
		co[i] = co[i - 1] + (s[i] == 'o');
		if (ch[i] >= 2 && ci[i] >= 1 && co[i] >= 1)
		{
			while (last < i && check(last, ch[i], ci[i], co[i]))
			{
				last++;
			}
			if (ch[i] - ch[last - 1] == 2 && ci[i] - ci[last - 1] == 1 && co[i] - co[last - 1] == 1) 
				min_len = min(min_len, i - last + 1);
		}
	}
	if (min_len != INF)
		cout << min_len << endl;
	else
		cout << -1 << endl;
	//system("pause");
	return 0;
}

