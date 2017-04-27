// poj1011.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int a[65], n, last;
bool used[65];

bool cmp(const int & a, const int & b)
{
	return a > b;
}

bool dfs(int r, int m, int l)
{
	if (m == 0)
	{
		if (r == 0)
			return true;
		return dfs(r, l, l);
	}     
	int start = 0; //剪枝4。拼每一根棍子的时候，应该确保已经拼好的部分，长度是从长到短排列的.排除办法：每次找一根木棒的时候，只要这不是一根棍子的第一条木棒，就不应该从下标为0的木棒开始找，而应该从刚刚(最近）接上去的那条木棒的下一条开始找。
	if (m != l)
		start = last + 1;
	for (int i = start; i < n; i++)
	{
		if (!used[i] && m >= a[i])
		{
			if (i != 0 && used[i - 1] == false && a[i] == a[i - 1]) //剪枝1。不在同一位置多次尝试使用长度相同的木棒
				continue;
			used[i] = true;
			last = i;
			if (r > 0 && dfs(r - 1, m - a[i], l))
				return true;
			used[i] = false;
			if (m == l || a[i] == m) // 剪枝2。不用交换拼木棒的顺序（即替换第i木棒的第一个棒子是没有用的）剪枝3。不要希望通过仅仅替换已拼好棍子的最后一根木棒就能够改变失败的局面
				return false;
		}
	}
	return false;
}

int main()
{
	while (cin >> n, n)
	{
		int sum = 0;
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &a[i]);
			sum += a[i];
		}
		sort(a, a + n, cmp);
		bool flag = false;
		for (int i = 1; i <= sum / 2; i++)
		{
			if (sum % i)
				continue;
			memset(used, 0, sizeof(used));
			if (dfs(n, i, i))
			{
				flag = true;
				cout << i << endl;
				break;
			}
		}
		if (!flag)
			cout << sum << endl;
	}
	//system("pause");
	return 0;
}

