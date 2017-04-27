// hihocoder offer收割编程练习赛12（2）.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;

int n, x, tmp, num[100005];
map<int, int> mp;

int main()
{
	int cnt = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		int tot = 0;
		for (int j = 0; j < x; j++)
		{
			cin >> tmp;
			tot += tmp;
			if (!mp.count(tot))
			{
				mp[tot] = ++cnt;
				num[mp[tot]] = 1;
			}
			else
				num[mp[tot]]++;
		}
	}
	sort(num, num + cnt);
	cout << n - num[cnt - 2] << endl;
	//system("pause");
	return 0;
}

