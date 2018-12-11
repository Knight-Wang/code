// CF_round386_B.cpp : 定义控制台应用程序的入口点。
//

#//include "stdafx.h"
#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

int n;
string s;
char a[2005];
int main()
{
	cin >> n >> s;
	int now = n - 1;
	for (int i = 0; i < n; i++)
		a[i] = 'A';
	for (int i = 0; i < n; i++)
	{
		char tmp = s[i];
		int pos = (now - i) / 2;
		int cnt = 0;
		int index = 0;
		for (int j = 0; j < n; j++)
		{
			if (a[j] == 'A')
				cnt++;
			if (cnt == pos + 1)
			{
				index = j;
				break;
			}
		}
		a[index] = tmp;
	}
	for (int i = 0; i < n; i++)
	{
		cout << a[i];
	}
	cout << endl;
	//system("pause");
	return 0;
}

