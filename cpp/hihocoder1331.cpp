// hihocoder ��չ��������.cpp : �������̨Ӧ�ó������ڵ㡣
//

//#include "stdafx.h"
#include <iostream>
#include <cstdio>
using namespace std;

int dfs(int x)
{
	if (x <= 1)
		return 1;
	if (x & 1)
		return dfs((x - 1) >> 1);
	return dfs(x >> 1) + dfs((x - 2) >> 1);
}

int main()
{
	int n;
	cin >> n;
	cout << dfs(n) << endl;
	//system("pause");
	return 0;
}

