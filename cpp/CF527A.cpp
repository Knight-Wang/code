// CF527A.cpp : �������̨Ӧ�ó������ڵ㡣
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

