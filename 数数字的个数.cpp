// �����ֵĸ���.cpp : �������̨Ӧ�ó������ڵ㡣
//

//#include "stdafx.h"
#include <iostream>
#include <cstdio>
using namespace std;

int num(int x, int m)
{
	int cnt = 0;
	while (x)
	{
		if (x % 10 == m)
			cnt++;
		x /= 10;
	}
	return cnt;
}

int main()
{
	int n, m;
	cin >> n >> m;
	int cnt = 0;
	for (int i = 1; i <= n; i++)
	{
		cnt += num(i, m);
	}
	cout << cnt << endl;
	//system("pause");
	return 0;
}

