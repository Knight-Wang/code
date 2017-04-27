// CF749C.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <iostream>
#include <string>
#include <cstdio>
#include <queue>
using namespace std;

int n;
string s;

int main()
{
	cin >> n >> s;
	queue<int> qd, qr;
	for (int i = 0; i < n; i++)
	{
		if (s[i] == 'D')
		{
			qd.push(i);
		}
		else
		{
			qr.push(i);
		}
	}
	while (!qd.empty() && !qr.empty())
	{
		if (qd.front() < qr.front())
		{
			qr.pop();
			qd.push(qd.front() + n);
			qd.pop();
		}
		else
		{
			qd.pop();
			qr.push(qr.front() + n);
			qr.pop();
		}
	}
	if (qd.empty())
	{
		cout << "R" << endl;
	}
	else
	{
		cout << "D" << endl;
	}
	//system("pause");
	return 0;
}

