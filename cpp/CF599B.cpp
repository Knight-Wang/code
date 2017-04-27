// CF599B.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <iostream>
#include <cstdio>
using namespace std;

int pos[100005], x[100005], y[100005], b[100005], n, m, tmp;
int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &tmp);
		x[tmp]++;
		pos[tmp] = i;
	}
	for (int i = 1; i <= m; i++)
	{
		scanf("%d", &b[i]);
		y[b[i]]++;
	}
	bool f1 = true, f2 = true;
	for (int i = 1; i <= n; i++)
	{
		if (y[i] && !x[i])
		{
			f1 = false;
			break;
		}
		if (x[i] > 1 && y[i])
		{
			f2 = false;
		}
	}
	if (!f1)
		cout << "Impossible" << endl;
	else if (!f2)
		cout << "Ambiguity" << endl;
	else
	{
		cout << "Possible" << endl;
		for (int i = 1; i <= m; i++)
		{
			printf("%d ", pos[b[i]]);
		}
		puts("");
	}
	//system("pause");
	return 0;
}

