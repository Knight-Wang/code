// poj1328.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

struct node
{
	double x, y;
};
node a[1005];
int n, d;
pair<double, double> p[1005];

int main()
{
	int T = 1;
	while (cin >> n >> d, n || d)
	{
		bool flag = true;
		if (d <= 0)
			flag = false;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i].x >> a[i].y;
			if (a[i].y > d)
				flag = false;
		}
		if (!flag)
		{
			cout << "Case " << T++ << ": -1" << endl;
			continue;
		}
		for (int i = 0; i < n; i++)
		{
			p[i].first = a[i].x - sqrt(d * d - a[i].y * a[i].y);
			p[i].second = a[i].x + sqrt(d * d -a[i].y * a[i].y);
		}
		sort(p, p + n);
		int cnt = 1;
		double now_right = p[0].second;
		for (int i = 1; i < n; i++)
		{
			if (p[i].first > now_right)
			{
				cnt++;
				now_right = p[i].second;
			}
			else if (p[i].second <= now_right)
			{
				now_right = p[i].second;
			}
		}
		cout << "Case " << T++ << ": " << cnt << endl;
	}
	//system("pause");
	return 0;
}

