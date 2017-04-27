// CF617A.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <cstdio>
#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	cout << n / 5 + (n % 5 ? 1 : 0) << endl;
	//system("pause");
	return 0;
}

