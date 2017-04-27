// CF791A.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;
int main()
{
	ll a, b, cnt = 0;
	cin >> a >> b;
	while (a <= b)
	{
		a *= 3;
		b *= 2;
		cnt++;
	}
	cout << cnt << endl;
	//system("pause");
	return 0;
}

