// CF_round_403_B.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;
struct node
{
	double pos;
	double speed;
};
node a[60005];
int n;
double minn, maxn;
bool check(double t)
{
	minn = a[0].pos - t * a[0].speed;
	maxn = a[0].pos + t * a[0].speed;
	for (int i = 1; i < n; i++)
	{
		double tmp_l = a[i].pos - t * a[i].speed;
		double tmp_r = a[i].pos + t * a[i].speed;
		minn = max(minn, tmp_l);
		maxn = min(maxn, tmp_r);
	}
	return maxn - minn >= 1e-7;
}

double solve()
{
	double l = 0.0, r = 1000000005, res = 1000000005;
	for (int i = 0; i < 10000; i++)
	{
		double mid = (l + r) / 2.0;
		if (check(mid))
		{
			r = mid;
			res = mid;
		}
		else
		{
			l = mid;
		}
	}
	return res;
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i].pos;
	}
	for (int i = 0; i < n; i++)
	{
		cin >> a[i].speed;
	}
	cout << setprecision(7) << solve() << endl;
	//system("pause");
	return 0;
}

