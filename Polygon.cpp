// Polygon.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

const int INF = 0x3f3f3f3f;

int n, a[55];
char c[55];
struct node
{
	int minn, maxn;
};
node dp[55][55];
struct ans
{
	int res, index;
};
int cal(int a, int b, char c)
{
	return c == 't' ? a + b : a * b;
}
int myMax(int a, int b, int c, int d)
{
	return max(a, max(b, max(c, d)));
}
int myMin(int a, int b, int c, int d)
{
	return min(a, min(b, min(c, d)));
}
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> c[i] >> a[i];
	}
	vector<ans> Ans;
	for (int t = 0; t < n; t++)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = i; j < n; j++)
			{
				dp[i][j].minn = INF;
				dp[i][j].maxn = -INF;
			}
		}
		vector<int> x;
		vector<char> y;
		for (int j = t; j < n; j++)
		{
			x.push_back(a[j]);
			if (j != t)
				y.push_back(c[j]);
		}
		for (int j = 0; j < t; j++)
		{
			x.push_back(a[j]);
			y.push_back(c[j]);
		}
		for (int i = n - 1; i >= 0; i--)
		{
			for (int j = i; j < n; j++)
			{
				if (j == i)
					dp[i][j].minn = dp[i][j].maxn = x[i];
				if (j == i + 1)
				{
					dp[i][j].maxn = dp[i][j].minn = cal(x[i], x[j], y[i]);
				}
				else
				{
					for (int k = i; k < j; k++)
					{
						node l = dp[i][k], r = dp[k + 1][j];
						if (y[k] == 't')
						{
							dp[i][j].minn = min(dp[i][j].minn, cal(l.minn, r.minn, 't'));
							dp[i][j].maxn = max(dp[i][j].maxn, cal(l.maxn, r.maxn, 't'));
						}
						else
						{
							dp[i][j].minn = min(dp[i][j].minn, myMin(cal(l.minn, r.minn, 'x'), cal(l.minn, r.maxn, 'x'), cal(l.maxn, r.minn, 'x'), cal(l.maxn, r.maxn, 'x')));
							dp[i][j].maxn = max(dp[i][j].maxn, myMax(cal(l.minn, r.minn, 'x'), cal(l.minn, r.maxn, 'x'), cal(l.maxn, r.minn, 'x'), cal(l.maxn, r.maxn, 'x')));
						}
					}
				}
			}
		}
		ans as;
		as.res = dp[0][n - 1].maxn;
		as.index = t + 1;
		Ans.push_back(as);
	}
	int maxn = -INF, maxIndex = -1;
	for (int i = 0; i < n; i++)
	{
		if (Ans[i].res > maxn)
		{
			maxn = Ans[i].res;
			maxIndex = Ans[i].index;
		}
	}
	vector<int> p;
	for (int i = 0; i < n; i++)
	{
		if (Ans[i].res == maxn)
		{
			p.push_back(Ans[i].index);
		}
	}
	cout << maxn << endl;
	for (int i = 0; i < p.size(); i++)
	{
		cout << p[i] << " ";
	}
	cout << endl;
	//system("pause");
	return 0;
}

