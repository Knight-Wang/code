// CF_round_387_C.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

struct node
{
	int t, k, d;
};
node a[100005];
int n, t, x, y, z, maxn = 0, s[105];
int max(int a, int b)
{
	return a > b ? a : b;
}
int main()
{
	cin >> n >> t;
	for (int i = 0; i < n; i++)
	{
		s[i] = 0;
	}
	for (int i = 0; i < t; i++)
	{
		scanf("%d %d %d", &a[i].t, &a[i].k, &a[i].d);
		maxn = max(maxn, a[i].t);
	}
	int now = 0;
	for (int i = 1; i <= maxn; i++)
	{
		for (int k = 0; k < n; k++)
		{
			if (s[k])
			{
				s[k]--;
			}

		}
		/*
		for (int k = 0; k < n; k++)
		{
			cout << s[k] << " ";
		}
		cout << endl;
		*/
		if (a[now].t == i)
		{
			int cnt = 0;
			vector<int> tmp;
			for (int j = 0; j < n; j++)
			{
				if (s[j] == 0 && cnt < a[now].k)
				{
					tmp.push_back(j);
					cnt++;
				}
			}
			/*
			cout << cnt << " " << now << endl;
			for (int i = 0; i < n; i++)
			{
				cout << s[i] << " ";
			}
			cout << endl;
			if (cnt == a[now].k)
			{
				for (int i = 0; i < cnt; i++)
				{
					cout << tmp[i] << " ";
				}
				cout << endl;
			}
			*/
			if (cnt == a[now].k)
			{
				int sum = 0;
				for (int k = 0; k < cnt; k++)
				{
					sum += tmp[k]+1;
					s[tmp[k]] = a[now].d;
				}
				cout << sum << endl;
			}
			else
			{
				cout << "-1" << endl;
			}
			
			now++;
		}
	}
	//system("pause");
	return 0;
}

