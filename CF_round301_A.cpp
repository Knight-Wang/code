// CF_round301_A.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int n;
string a, b;
int min(int a, int b)
{
	return a < b ? a : b;
}
int main()
{
	cin >> n;
	cin >> a >> b;
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		cnt += min((a[i] - b[i] + 10) % 10, (b[i] - a[i] + 10) % 10);
	}
	cout << cnt << endl;
	//system("pause");
	return 0;
}

