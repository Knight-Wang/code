
// CF742A.cpp : �������̨Ӧ�ó������ڵ㡣
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

