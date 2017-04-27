// 最大最小公倍数.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <iostream>
#include <cstdio>
typedef long long ll;
using namespace std;
ll n;
ll max(ll a, ll b)
{
	return a > b ? a : b;
}
ll lcm(ll a, ll b)
{
	if (b == 0)
		return a;
	return lcm(b, a % b);
}
ll gcd(ll a, ll b)
{
	return a / lcm(a, b) * b;
}
ll work(int n)
{
	ll tmp = max(gcd(gcd(n - 3, n - 2), n), gcd(gcd(n - 3, n - 1), n));
	return max(tmp, gcd(gcd(n - 2, n - 1), n));
}
int main()
{
	cin >> n;
	if (n & 1)
	{
		cout << n*(n - 1)*(n - 2) << endl;
	}
	else
	{
		cout << max((n - 1)*(n - 2)*(n - 3), work(n)) << endl;
	}
	//system("pause");
	return 0;

}

