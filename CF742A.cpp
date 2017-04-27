
// CF742A.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <cstdio>
#include <iostream>
using namespace std;

int a[4] = {8, 4, 2, 6};
int main()
{
	int n;
	cin >> n;
	if (n == 0)
		cout << "1" << endl;
	else
	    cout << a[(n - 1) % 4] << endl;
	//system("pause");
	return 0;
}

