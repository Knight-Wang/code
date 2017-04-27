// Cw的嘲讽.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <iostream>
#include <cstdio>
using namespace std;

long long x;
int main()
{
	cin >> x;
	cout << (x & (x + 1)) << endl;
	//cout << (x & (x - 1)) << endl;
	//system("pause");
	return 0;
}

