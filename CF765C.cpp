// CF765C.cpp : �������̨Ӧ�ó������ڵ㡣
//

//#include "stdafx.h"
#include <iostream>
#include <cstdio>
using namespace std;

int k, a, b;
int main()
{
	cin >> k >> a >> b;
	if (a < k && b % k || b < k && a % k)
		puts("-1");
	else
		cout << a / k + b / k << endl;
	//system("pause");
	return 0;
}

