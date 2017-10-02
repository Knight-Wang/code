#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int INF = 0x3f3f3f3f;
char a[5005];
int f[15555], sum[15555], n;
int solve(int k)
{
	memset(f, 0, sizeof f);
	memset(sum, 0, sizeof sum);
	for (int i = 5005; i <= 5005 + n - k; i++)
	{
		int tmp = sum[i - 1] - sum[i - k];
		if ((tmp % 2 == 0 && a[i - 5005] == 'B') || (tmp % 2 == 1 && a[i - 5005] == 'F'))
		{
			f[i] = 1;
		}
		sum[i] = sum[i - 1] + f[i];
	}
	for (int i = 5006 + n - k; i < 5005 + n; i++)
	{
		sum[i] = sum[i - 1] + f[i];
		int tmp = sum[i - 1] - sum[i - k];
		if ((tmp % 2 == 0 && a[i - 5005] == 'B') || (tmp % 2 == 1 && a[i - 5005] == 'F'))
		{
			return -1;
		}
	}
	return sum[5005 + n - k];
}
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	int minn = INF, res = 0;
	for (int k = 1; k <= n; k++)
	{
		int tmp = solve(k);
		if (tmp >= 0 && tmp < minn) { minn = tmp; res = k; }
	}
	cout << res << " " << minn << endl;
	return 0;
}