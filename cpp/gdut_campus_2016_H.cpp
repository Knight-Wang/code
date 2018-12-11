// tmk买礼物.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;

int a[100005], t, n;

int main()
{
	cin >> t;
	while (t--)
	{
		ll r = 0;
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &a[i]);
		}
		sort(a, a + n);
		for (int i = 0; i < n; i++)
		{
			if (a[i] > r + 1)
				break;
			r += a[i];
		}
		printf("%lld\n", r);
	}
	//system("pause");
	return 0;
}

