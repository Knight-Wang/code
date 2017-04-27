// hdu1013.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;

char a[1005];

int main()
{
	int n;
	while (true)
	{
		scanf("%s", a);
		if (a[0] == '0')
			break;
		int l = strlen(a);
		int ans = 0;
		for (int i = 0; i < l; i++)
		{
			ans += (a[i] - '0');
			ans %= 9;
		}
		printf("%d\n", !ans ? 9 : ans);
	}
	//system("pause");
	return 0;
}