// CF_round386_A.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <iostream>
#include <cstdio>
using namespace std;

int min(int a, int b)
{
	return a < b ? a : b;
}
int a, b, c;
int main()
{
	cin >> a >> b >> c;
	int t = min(min(a, b / 2), c / 4);
	cout << t * 7 << endl;
	//system("pause");
	return 0;
}

