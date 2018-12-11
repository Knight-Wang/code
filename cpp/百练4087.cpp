// 百练 数据筛选.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int a[1000005], n, k;
int main()
{
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	sort(a, a + n);
	printf("%d\n", a[k - 1]);
	//system("pause");
	return 0;
}

