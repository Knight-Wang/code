// five.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <iostream>
#include <cstdio>
using namespace std;

int m, n, tmp;

int main()
{
	cin >> m >> n;
	int cnt = 0;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> tmp;
			if (tmp)
				cnt++;
		}
	}
	cout << cnt << endl;
	//system("pause");
	return 0;
}

