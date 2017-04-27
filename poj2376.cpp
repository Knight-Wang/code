// poj2376.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

pair<int, int> p[25005];
int n, t;

int main()
{
	cin >> n >> t;
	for (int i = 0; i < n; i++)
	{
		scanf("%d %d", &p[i].first, &p[i].second);
	}
	sort(p, p + n);
	bool flag = true;
	int now_end = 0;
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		if (p[i].second <= now_end)
			continue;
		if (p[i].first - now_end > 1)
		{
			flag = false;
			break;
		}
		int j = i, maxn = p[j].second;
		while (j < n && (p[j].first <= now_end || p[j].first - now_end <= 1))
		{
			maxn = max(maxn, p[j].second);
			j++;
		}
		now_end = maxn;
		cnt++;
		if (now_end >= t)
			break;
		i = j - 1;
	}
	if (now_end < t)
	{
		flag = false;
	}
	cout << (flag ? cnt : -1) << endl;
	//system("pause");
	return 0;
}