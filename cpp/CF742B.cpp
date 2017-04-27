// CF742B.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
int n, x, a[100005];
int main()
{
	cin >> n >> x;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	sort(a, a + n);
	ll cnt = 0;
	for (int i = 0; i < n; i++)
	{
		int tmp = a[i] ^ x;
		if (binary_search(a + i + 1, a + n, tmp))
		{
			int l = lower_bound(a + i + 1, a + n, tmp) - a - i - 1;
			int r = upper_bound(a + i + 1, a + n, tmp) - a - i - 1;
			cnt += r - l;
		}
	}
	cout << cnt << endl;
	//system("pause");
	return 0;
}

