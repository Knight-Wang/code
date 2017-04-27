// poj2393.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
struct node
{
	ll c, y;
};
node a[10005];
ll n, s;

int main()
{
	cin >> n >> s;
	for (ll i = 0; i < n; i++)
	{
		scanf("%d %d", &a[i].c, &a[i].y);
	}
	ll sum = a[0].y * a[0].c;
	for (ll i = 1; i < n; i++)
	{
		sum += min(a[i].c * a[i].y, (a[i - 1].c + s)* a[i].y);
	}
	cout << sum << endl;
	//system("pause");
	return 0;
}

