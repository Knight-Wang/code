// CF527A.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;
ll solve(ll a, ll b)
{
	if (b == 0)
		return 0;
	return a / b + solve(b, a % b);
}
ll a, b;
int main()
{
	cin >> a >> b;
	cout << solve(a, b) << endl;
	//system("pause");
	return 0;
}

