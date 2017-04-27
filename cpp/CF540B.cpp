// CF540B.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int n, p, k, x, y;
vector<int> a;
int main()
{
	cin >> n >> k >> p >> x >> y;
	int sum = 0, tmp = 0;
	for (int i = 0; i < k; i++)
	{
		cin >> tmp;
		a.push_back(tmp);
		sum += a[i];
	}
	if (x - sum < n - k)
	{
		puts("-1");
	}
	else
	{
		bool flag = true;
		vector<int> res;
		sort(a.begin(), a.begin() + k);
		int now = k;
		sum = x - sum;
		while (now < n)
		{
			int pos = lower_bound(a.begin(), a.begin() + now, y) - a.begin();
			if (pos < now / 2)
			{
				a.insert(a.begin(), 1);
				res.push_back(1);
				sum--;
			}
			else
			{
				a.insert(a.begin() + pos, y);
				res.push_back(y);
				sum -= y;
			}
			if (sum < 0)
			{
				puts("-1");
				flag = false;
				break;
			}
			now++;
		}
		if (flag)
		{
			if (a[n >> 1] >= y)
			{
				for (int i = 0; i < n - k; i++)
				{
					cout << res[i] << " ";
				}
				puts("");
			}
			else
			{
				puts("-1");
			}
		}
	}
	//system("pause");
	return 0;
}

