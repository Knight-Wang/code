// CF_round_402_C.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

struct node
{
	int a, b;
};
node t[200005];
int n, k;
bool cmp(const node & x, const node & y)
{
	if (x.a >= x.b && y.a >= y.b)
	{
		return x.a - x.b < y.a - y.b;
	}
	else if (x.a < x.b && y.a >= y.b)
	{
		return true;
	}
	else if (x.a >= x.b && y.a < y.b)
	{
		return false;
	}
	else
	{
		return x.b - x.a > y.b - y.a;
	}
	
}
int main()
{
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &t[i].a);
	}
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &t[i].b);
	}
	sort(t, t + n, cmp);
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		if (i < k)
		{
			sum += t[i].a;
		}
		else
		{
			sum += min(t[i].a, t[i].b);
		}
	}
	cout << sum << endl;
	//system("pause");
	return 0;
}

