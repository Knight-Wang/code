// hihocoder offer收割编程练习赛12（1）.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int MAX_N = 1000005;

int prime[MAX_N];
bool is_prime[MAX_N + 1];

int init(int n)
{
	int p = 0;
	for (int i = 0; i <= n; i++)
		is_prime[i] = true;
	is_prime[0] = is_prime[1] = false;
	for (int i = 2; i <= n; i++)
	{
		if (is_prime[i])
		{
			prime[p++] = i;
			for (int j = 2 * i; j <= n; j += i)
				is_prime[j] = false;
		}
	}
	return p;
}

int main()
{
	int num = init(1000000);
	int n;
	cin >> n;
	for (int i = 0; i < num; i++)
	{
		if (binary_search(prime + i, prime + num, n - prime[i]))
		{
			int index = lower_bound(prime + i, prime + num, n - prime[i]) - prime;
			cout << prime[i] << " " << prime[index] << endl;
			break;
		}
	}
	//system("pause");
	return 0;
}

