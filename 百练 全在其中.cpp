// ���� ȫ������.cpp : �������̨Ӧ�ó������ڵ㡣
//

//#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
bool isSUB(string str1, string str2)
{
	int l1 = str1.length();
	int l2 = str2.length();
	int k = 0;
	for (int i = 0; i < l2; i++)
	{
		if (k < l1 && str2[i] == str1[k])
			k++;
	}
	if (k == l1)
		return true;
	else
		return false;
}
int main()
{
	string str1, str2;
	while (cin >> str1 >> str2)
	{
		if (isSUB(str1, str2))
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	//system("pause");
	return 0;
}