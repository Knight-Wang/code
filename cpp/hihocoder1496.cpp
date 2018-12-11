// hihocoder offer收割编程练习赛12（4）.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;

int a[100005], n;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		ll maxn = 0;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		sort(a, a + n);
		for (int i = 1; i < n; i++)
		{
			maxn = max(maxn, (ll)a[i] * a[i - 1] * (a[i] & a[i - 1]));
		}
		cout << maxn << endl;
	}
	//system("pause");
	return 0;
}

