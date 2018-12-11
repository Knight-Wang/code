// 51nod 威佐夫游戏 V2.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;

const ll tmp[3] = { 618033988, 749894848, 204586834 };
const ll mod = 1e9;

int main()
{
	int t;
	ll a, b;
	cin >> t;
	while (t--)
	{
		cin >> a >> b;
		if (a < b)
			swap(a, b);
		ll x = a - b;
		ll c = a - b;
		ll p = c / mod, l = c % mod;
		ll a1 = l * tmp[2];
		ll a2 = p * tmp[2] + l * tmp[1] + a1 / mod;
		ll a3 = p * tmp[1] + l * tmp[0] + a2 / mod;
		ll a4 = c + p * tmp[0] + a3 / mod;
		cout << (a4 == b ? 'B' : 'A') << endl;
	}
	//system("pause");
	return 0;
}

