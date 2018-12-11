// CF_round_403_A.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <cstdio>
#include <iostream>
using namespace std;
int cnt[100005], tmp, n;
int main()
{
	cin >> n;
	int all = 0;
	int maxn = -1;
	for (int i = 0; i < 2 * n; i++)
	{
		cin >> tmp;
		cnt[tmp]++;
		if (cnt[tmp] == 2)
			all--;
		else
			all++;
		if (maxn < all)
			maxn = all;
	}
	cout << maxn << endl;
	//system("pause");
	return 0;
}

