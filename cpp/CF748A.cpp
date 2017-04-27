// CF748A.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <iostream>
#include <cstdio>
using namespace std;
int n, m, k, a, b, c;
int main()
{
	cin >> n >> m >> k;
	k--;
	a = k / (m * 2);
	b = k % (m * 2) / 2;
	c = k & 1;
	printf("%d %d %c\n", a + 1, b + 1, !c ? 'L' : 'R');

	//system("pause");
	return 0;
}

