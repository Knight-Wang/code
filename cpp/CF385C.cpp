#include <bits/stdc++.h>
using namespace std;

bool is_prime[10000005];
vector<int> prime;
int num[10000005], ans[10000005];
void sieve(int n)
{
	for (int i = 0; i <= n; i++) is_prime[i] = true;
	is_prime[0] = is_prime[1] = false;
	for (int i = 2; i <= n; i++)
	{
		if (is_prime[i])
		{
			prime.push_back(i);
			for (int j = 2 * i; j <= n; j += i) is_prime[j] = false;
		}
	}
}
int main()
{
	sieve(10000000);
	int n, m, x, a, b;
	while (scanf("%d", &n) != EOF)
	{
		memset(num, 0, sizeof num);
		memset(ans, 0, sizeof ans);
		int l = prime.size();
		for (int i = 0; i < n; i++) { scanf("%d", &x); num[x]++; }
		for (int i = 0; i < l; i++)
		{
			int now = prime[i];
			for (int j = now; j <= 10000000; j += now)
			{
				if (num[j]) ans[now] += num[j];
			}
		}
		for (int i = 1; i <= 10000000; i++) ans[i] += ans[i - 1];
		scanf("%d", &m);
		for (int i = 0; i < m; i++)
		{
			scanf("%d %d", &a, &b);
			if (a > b) { puts("0"); continue; }
			a = min(a, 10000000); b = min(b, 10000000);
			printf("%d\n", ans[b] - ans[a - 1]);
		}
	}
	return 0;
}