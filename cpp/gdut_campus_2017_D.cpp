// ֻ��ͨ��������ܽ�ʾ����.cpp : �������̨Ӧ�ó������ڵ㡣
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

