// poj3292.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN = 1000001;
bool is_prime[MAXN + 5];
int x;
vector<int> res;
void init()
{
	vector<int> prime;
	memset(is_prime, 1, sizeof(is_prime));
	for (int i = 5; i <= MAXN; i += 4)
	{
		if (is_prime[i])
		{
			prime.push_back(i);
			for (int j = 5; i * j <= MAXN; j += 4)
			{
				is_prime[i * j] = false;
			}
		}
	}
	for (int i = 25; i <= MAXN; i += 4)
	{
		if (is_prime[i])
			continue;
		int tmp = i;
		int cnt = 0;
		for (int j = 0; prime[j] * prime[j] <= tmp; j++)
		{
			if (cnt > 2)
				break;
			while (tmp % prime[j] == 0)
			{
				cnt++;
				tmp /= prime[j];
			}
		}
		if (tmp != 1)
			cnt++;
		if (cnt <= 2)
			res.push_back(i);
	}
}

int main()
{
	init();
	while (scanf("%d", &x), x)
	{
		printf("%d %d\n", x, upper_bound(res.begin(), res.end(), x) - res.begin());
	}
	system("pause");
	return 0;
}

