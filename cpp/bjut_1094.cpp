// Cw买气球.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
typedef long long ll;

const int MAXN = 1000000;

ll a[MAXN + 5], s[MAXN + 5], m;
int k, n;

int main()
{
	scanf("%d", &k);
	for (int i = 0; i < k; i++)
	{
		scanf("%lld", &a[i]);
	}
	s[0] = a[0];
	for (int i = 1; i < k; i++)
	{
		s[i] = s[i - 1] + a[i];
	}
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%lld", &m);
		int index = upper_bound(s, s + k, m) - s;
		printf("%d\n", index);
	}
	//system("pause");
	return 0;
}

