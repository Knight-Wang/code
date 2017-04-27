// N!.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;
ll f[21], x;
void init()
{
	f[0] = 1;
	for (int i = 1; i <= 20; i++)
	{
		f[i] = f[i - 1] * (ll)i;
	}
}
int main()
{
	init();
	int t;
	cin >> t;
	while (t--)
	{
		cin >> x;
		cout << f[x] << endl;
	}
	//system("pause");
	return 0;
}

