// ���� ����ɸѡ.cpp : �������̨Ӧ�ó������ڵ㡣
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

