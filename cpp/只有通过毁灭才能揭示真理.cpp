// 只有通过毁灭才能揭示真理.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <iostream>
using namespace std;

int t, a, b, c;
int main()
{
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d %d %d", &a, &b, &c);
		printf("%d\n", a * b + a / 30 * c);
	}
	//system("pause");
	return 0;
}

