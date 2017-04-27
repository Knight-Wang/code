// CF_round_402_A.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

int n, tmp, ca[6], cb[6];
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &tmp);
		ca[tmp]++;
	}
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &tmp);
		cb[tmp]++;
	}
	int cnt = 0;
	bool flag = true;
	for (int i = 1; i <= 5; i++)
	{
		tmp = abs(cb[i] - ca[i]);
		if (tmp & 1)
		{
			flag = false;
			break;
		}
		cnt += tmp;
	}
	if (!flag)
		cout << "-1" << endl;
	else
		cout << cnt / 4 + cnt % 4 / 2 << endl;
	//system("pause");
	return 0;
}

