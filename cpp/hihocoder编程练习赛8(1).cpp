// hihocoder�����ϰ��8(1).cpp : �������̨Ӧ�ó������ڵ㡣
//

//#include "stdafx.h"
#include <iostream>
#include <cstdio>
using namespace std;

typedef long long ll;
ll l, d, f;
int t;

ll gcd(ll x, ll y)
{
	return !y ? x : gcd(y, x % y);
}

bool test(ll x, ll y, ll z)
{
	return gcd(x, y) >= z;
}

int main()
{
	cin >> t;
	while (t--)
	{
		cin >> l >> f >> d;
		if (test(l, d, f))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	//system("pause");
	return 0;
}

