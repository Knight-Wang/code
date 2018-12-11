#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
int a[105];
int main()
{
	int n;
	while (cin >> n)
	{
		for (int i = 1; i <= n; i++) cin >> a[i];
		int ans = INF;
		for (int i = 1; i <= n; i++)
		{
			int sum = 0;
			for (int j = 1; j <= n; j++)
			{
				sum += (abs(i - j) + (j - 1) + (i - 1)) * a[j] * 2;
			}
			ans = min(ans, sum);
		}
		cout << ans << endl;
	}
	return 0;
}