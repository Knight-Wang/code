// 因式分解.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;
bool isPrime(ll x)
{
	for (ll i = 2; i * i <= x; i++)
	{
		if (x % i == 0)
			return false;
	}
	return x != 1;
}
void dfs(ll x)
{
	if (isPrime(x))
	{
		cout << x << endl;
		return;
	}
	for (ll i = 2; i * i <= x; i++)
	{
		if (isPrime(i) && x % i == 0)
		{
			cout << i << "*";
			dfs(x / i);
			break;
		}
	}
	
}
int main()
{
	ll t;
	cin >> t;
	dfs(t);
	//system("pause");
	return 0;
}

