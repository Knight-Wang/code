// CF_round387_A.cpp : �������̨Ӧ�ó������ڵ㡣
//

//#include "stdafx.h"
#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int a = 1, b = n;
	for (int i = 1; i * i <= n; i++)
	{
		int tmp = n / i;
		if (i * tmp == n)
		{
			a = i;
			b = tmp;
		}
	}
	cout << a << " " << b << endl;
	//system("pause");
	return 0;
}

