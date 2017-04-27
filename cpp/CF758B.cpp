// CF758B.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

string s;
int a[4]; //R, G, B, Y
int main()
{
	cin >> s;
	int n = s.length();
	for (int j = 0; j < 4; j++)
	{
		int tmp = 0;
		int index = -1;
		for (int i = j; i < n; i += 4)
		{
			if (s[i] == '!')
				tmp++;
			else if (s[i] == 'R')
			{
				index = 0;
			}
			else if (s[i] == 'G')
			{
				index = 1;
			}
			else if (s[i] == 'B')
			{
				index = 2;
			}
			else
			{
				index = 3;
			}
		}
		a[index] = tmp;
	}
	cout << a[0] << " " << a[2] << " " << a[3] << " " << a[1] << endl;
	//system("pause");
	return 0;
}

