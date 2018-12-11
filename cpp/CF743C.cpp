// CF_round384_C.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;
int main()
{
	ll n, x, y, z;
	cin >> n >> x >> y >> z;
	if (n == 1)
		cout << "-1" << endl;
	else
		cout << n << " " << n + 1 << " " << n * (n + 1) << endl;
	return 0;
}

