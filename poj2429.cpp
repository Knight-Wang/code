// poj2429.cpp : 定义控制台应用程序的入口点。
// 不是自己写的

//#include "stdafx.h"
#include <cstdio>  
#include <cmath>  
#include <cstring>  
#include <algorithm>  
#define Times 11  
#define inf ((long long)1 << 61)  
#define C 201  
using namespace std;
long long jl[501], numfactor[501], mini, mina, minb;//jl里面存的是大数的所有质因子，mini为最小的质因数  
int ct, num[65];
long long key, gc;
int len;

long long random(long long n)//生成随机数  
{
	return (long long)((double)rand() / RAND_MAX*n + 0.5);
}

long long gcd(long long a, long long b)//最大公约数  
{
	return b == 0 ? a : gcd(b, a%b);
}

long long multi(long long a, long long b, long long m)//a*b%m  
{
	long long ret = 0;
	while (b > 0)
	{
		if (b & 1) ret = (ret + a) % m;
		b >>= 1;
		a = (a << 1) % m;
	}
	return ret;
}

long long quick_mod(long long a, long long b, long long m)//a^b%m  
{
	long long ans = 1;
	a %= m;
	while (b)
	{
		if (b & 1)
		{
			ans = multi(ans, a, m);
			b--;
		}
		b /= 2;
		a = multi(a, a, m);
	}
	return ans;
}

bool Witness(long long a, long long n)
{
	long long m = n - 1;
	int j = 0;
	while (!(m & 1))
	{
		j++;
		m >>= 1;
	}
	long long x = quick_mod(a, m, n);
	if (x == 1 || x == n - 1)return false;
	while (j--)
	{
		x = x*x%n;
		if (x == n - 1)return false;
	}
	return true;
}

bool miller_rabin(long long n)//素数测试  
{
	if (n<2)return false;
	if (n == 2)return true;
	if (!(n & 1))return false;
	for (int i = 1; i <= Times; i++)
	{
		long long a = random(n - 2) + 1;
		if (Witness(a, n))return false;
	}
	return true;
}

long long pollard_rho(long long n, int c)//整数n分解,c一般为201  
{
	long long x, y, d, i = 1, k = 2;
	x = random(n - 1) + 1;
	y = x;
	while (1)
	{
		i++;
		x = (multi(x, x, n) + c) % n;
		d = gcd(y - x, n);
		if (1<d&&d<n)return d;
		if (y == x)return n;
		if (i == k)
		{
			y = x;
			k <<= 1;
		}
	}
}

void find(long long n, int k)
{
	if (n == 1)return;
	if (miller_rabin(n))
	{
		jl[++ct] = n;
		return;
	}
	long long p = n;
	while (p >= n)p = pollard_rho(p, k--);
	find(p, k);
	find(n / p, k);
}

void dfs(int cur, long long value)
{
	long long s = 1, a, b;
	if (cur == len + 1)
	{
		a = value;
		b = key / value;
		if (gcd(a, b) == 1)
		{
			a *= gc;
			b *= gc;
			if (a + b<mini)
			{
				mini = a + b;
				mina = a<b ? a : b;
				minb = a<b ? b : a;
			}
		}
		return;
	}
	for (int i = 0; i <= num[cur]; i++)
	{
		if (value*s >= mini) return;
		dfs(cur + 1, value*s);
		s *= numfactor[cur];
	}
}

void solve(long long n)
{
	ct = 0;
	find(n, C);
	sort(jl + 1, jl + ct + 1);
	memset(num, 0, sizeof(num));
	len = 0;
	num[0] = 1;
	numfactor[0] = jl[1];
	for (int i = 2; i <= ct; i++)
	{
		if (numfactor[len] != jl[i])numfactor[++len] = jl[i];
		num[len]++;
	}
	dfs(0, 1);
	printf("%lld %lld\n", mina, minb);
}

int main()
{
	long long  lc;
	while (scanf("%lld%lld", &gc, &lc) != EOF)
	{
		if (gc == lc){ printf("%lld %lld\n", gc, lc); continue; }
		key = lc / gc;
		mini = inf;
		solve(key);
	}
	//system("pause");
	return 0;
}

