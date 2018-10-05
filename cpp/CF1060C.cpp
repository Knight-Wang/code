#include <iostream>
#include <cstring>
using namespace std;
typedef long long ll;
const int MAXN = 2005;
const int MAXM = 2005;
int a[MAXN], b[MAXM], n, m;
ll sum1[MAXN], sum2[MAXM], min1[MAXN], min2[MAXM], x;
int main()
{
	while (cin >> n >> m)
	{
		memset(sum1, 0, sizeof sum1);
		memset(sum2, 0, sizeof sum2);
		memset(min1, 0x3f, sizeof min1);
		memset(min2, 0x3f, sizeof min2);
		for (int i = 1; i <= n; i++) 
		{
			cin >> a[i];
			sum1[i] = sum1[i - 1] + a[i];
		}
		for (int i = 1; i <= m; i++)
		{
			cin >> b[i];
			sum2[i] = sum2[i - 1] + b[i];
		}
		cin >> x;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 0; j < n - i + 1; j++)
			{
				min1[i] = min(min1[i], sum1[i + j] - sum1[j]);
			}
		}
		for (int i = 1; i <= m; i++)
		{
			for (int j = 0; j < m - i + 1; j++)
			{
				min2[i] = min(min2[i], sum2[i + j] - sum2[j]);
			}
		}
		int ans = 0;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				if (min1[i] <= x && x / min1[i] >= min2[j])
				{
					ans = max(ans, i * j);
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}