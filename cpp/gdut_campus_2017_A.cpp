// 两只老虎.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	int t, x, y, z;
	cin >> t;
	while (t--)
	{
		cin >> x >> y >> z;
		cout << x / 2 - z / 4 + y << endl;
	}
	//system("pause");
	return 0;
}

