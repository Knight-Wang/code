#include <bits/stdc++.h>
using namespace std;
int a[1005];
int main()
{
	int n;
	while (cin >> n)
	{
		for (int i = 1; i <= n; i++) cin >> a[i];
		int ans = 0x3f3f3f3f, id = -1;
		for (int k = 1; k <= 100; k++)
		{
			int sum = 0;
			for (int j = 1; j <= n; j++)
			{
				if (abs(a[j] - k) <= 1) continue;
				if (a[j] > k + 1) sum += a[j] - (k + 1);
				else sum += k - 1 - a[j];
			}
			if (sum < ans) { ans = sum; id = k; }
		}
		cout << id << " " << ans << endl;
	}
	return 0;
}