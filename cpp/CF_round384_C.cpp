// CF_round384_C.cpp : �������̨Ӧ�ó������ڵ㡣
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

