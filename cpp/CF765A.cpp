// CF_round397_A.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>

using namespace std;

int n;

int main()
{
	string home, tmp;
	cin >> n >> home;
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
	}
	if (n & 1)
		cout << "contest" << endl;
	else
		cout << "home" << endl;
	system("pause");
	return 0;
}

