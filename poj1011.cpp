// poj1011.cpp : �������̨Ӧ�ó������ڵ㡣
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
	int start = 0; //��֦4��ƴÿһ�����ӵ�ʱ��Ӧ��ȷ���Ѿ�ƴ�õĲ��֣������Ǵӳ��������е�.�ų��취��ÿ����һ��ľ����ʱ��ֻҪ�ⲻ��һ�����ӵĵ�һ��ľ�����Ͳ�Ӧ�ô��±�Ϊ0��ľ����ʼ�ң���Ӧ�ôӸո�(���������ȥ������ľ������һ����ʼ�ҡ�
	if (m != l)
		start = last + 1;
	for (int i = start; i < n; i++)
	{
		if (!used[i] && m >= a[i])
		{
			if (i != 0 && used[i - 1] == false && a[i] == a[i - 1]) //��֦1������ͬһλ�ö�γ���ʹ�ó�����ͬ��ľ��
				continue;
			used[i] = true;
			last = i;
			if (r > 0 && dfs(r - 1, m - a[i], l))
				return true;
			used[i] = false;
			if (m == l || a[i] == m) // ��֦2�����ý���ƴľ����˳�򣨼��滻��iľ���ĵ�һ��������û���õģ���֦3����Ҫϣ��ͨ�������滻��ƴ�ù��ӵ����һ��ľ�����ܹ��ı�ʧ�ܵľ���
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

