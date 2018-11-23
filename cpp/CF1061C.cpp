#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
int a[100005], sum[1000005], buf[1000005];
int main()
{
	int n;
	while (cin >> n)
	{
		for (int i = 1; i <= n; i++) cin >> a[i];
		memset(sum, 0, sizeof sum);
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j * j <= a[i]; j++)
			{
				if (a[i] % j == 0)
				{
					if (j == 1) buf[j] = 1;
					else buf[j] = sum[j - 1];
					int tmp = a[i] / j;
					if (tmp != j) buf[tmp] = sum[tmp - 1];
				}
			}
			for (int j = 1; j * j <= a[i]; j++)
			{
				if (a[i] % j == 0)
				{
					sum[j] = (sum[j] + buf[j]) % MOD;
					int tmp = a[i] / j;
					if (tmp != j)
						sum[tmp] = (sum[tmp] + buf[tmp]) % MOD;
				}
			}
		}
		int res = 0;
		for (int i = 1; i <= 1000000; i++) res = (res + sum[i]) % MOD;
		cout << res << endl;
	}
	return 0;
}