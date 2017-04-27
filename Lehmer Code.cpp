// Lehmer Code.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;

int a[10005], ans[10005];
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for (int i = n - 2; i >= 0; i--)
	{
		int cnt = 0;
		for (int j = n - 1; j > i; j--)
		{
			if (a[j] < a[i])
			{
				cnt++;
			}
		}
		ans[i] = cnt;
	}
	for (int i = 0; i < n; i++)
	{
		cout << ans[i] << " ";
	}
	cout << endl;
	//system("pause");
	return 0;
}

