// GB2016A.cpp : �������̨Ӧ�ó������ڵ㡣
//

//#include "stdafx.h"
#include <iostream>
#include <cstdio>
using namespace std;

int n, k;
int main()
{
	cin >> n >> k;
	int t = 240 - k;
	int i = 5;
	int cnt = 0;
	while (t >= i && cnt < n)
	{
		t -= i;
		i += 5;
		cnt++;
	}
	cout << cnt << endl;
	//system("pause");
	return 0;
}

