// 举手之劳.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> p;
int gcd(int a, int b)
{
	if (b == 0)
		return a;
	return gcd(b, a % b);
}
int main()
{
	int a, b, n;
	cin >> a >> b;
	cin >> n;
	int tmp = gcd(b, a % b);
	for (int i = 1; i * i <= tmp; i++)
	{
		if (tmp % i == 0)
		{
			p.push_back(i);
			if (tmp / i != i)
			{
				p.push_back(tmp / i);
			}
		}
	}
	sort(p.begin(), p.end());
	while (n--)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		int res = lower_bound(p.begin(), p.end(), y) - p.begin();
		if (res == p.size())
		{
			if (p[p.size() - 1] >= x)
				cout << p[p.size() - 1] << endl;
			else
				cout << "-1" << endl;
		}
		else if (p[res] > y)
		{
			if (p[res - 1] >= x)
				cout << p[res - 1] << endl;
			else
				cout << "-1" << endl;
		}
		else
		{
			cout << p[res] << endl;
		}
	}
	//system("pause");
	return 0;
}

