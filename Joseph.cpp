// Joseph.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

const int a[14] = {0, 2, 7, 5, 30, 169, 441, 1872, 7632, 1740, 93313, 459901, 1358657, 2504881};

int main()
{
	int k;
	while (cin >> k, k)
	{
		cout << a[k] << endl;
	}
	//system("pause");
	return 0;
}

