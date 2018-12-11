// CF_round384_B.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
ll n, k;
ll solve(ll now, ll pos)
{
	if (pos == (ll)1 << (now - 1))
	{
		return now;
	}
	if (pos > (ll)1 << (now - 1))
		solve(now - 1, ((ll)1 << now) - pos);
	else
		solve(now - 1, pos);
}
int main()
{ 
	cin >> n >> k;
	cout << solve(n, k) << endl;
	//system("pause");
	return 0;
}

