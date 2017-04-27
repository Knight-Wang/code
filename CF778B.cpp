// CF778B.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <bitset>
#include <map>
using namespace std;

int n, m, res[1005][2];
bitset<1005> bs[5005][2];
map<string, int> mp;
int main()
{
	mp["?"] = 0;
	bs[0][1].set();
	cin >> n >> m; 
	for (int i = 0; i < n; i++)
	{
		string x, tmp, y, op, z;
		cin >> x >> tmp >> y;
		mp[x] = i + 1;
		if (y[0] == '0' || y[0] == '1')
		{
			for (int j = 0; j < m; j++)
			{
				bs[i + 1][0].set(j, y[j] - '0');
				bs[i + 1][1].set(j, y[j] - '0');
			}
		}
		else
		{
			cin >> op >> z;
			for (int j = 0; j <= 1; j++)
			{
				if (op == "AND")
				{
					bs[i + 1][j] = bs[mp[y]][j] & bs[mp[z]][j];
				}
				else if (op == "OR")
				{
					bs[i + 1][j] = bs[mp[y]][j] | bs[mp[z]][j];
				}
				else
				{
					bs[i + 1][j] = bs[mp[y]][j] ^ bs[mp[z]][j];
				}
			}
		}
		for (int j = 0; j < m; j++)
		{
			for (int k = 0; k <= 1; k++)
				res[j][k] += bs[i + 1][k][j];
		}
	}
	for (int i = 0; i < m; i++)
	{
		cout << (res[i][0] > res[i][1] ? 1 : 0);
	}
	puts("");
	for (int i = 0; i < m; i++)
	{
		cout << (res[i][0] >= res[i][1] ? 0 : 1);
	}
	//system("pause");
	return 0;
}

