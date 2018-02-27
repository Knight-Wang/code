#include <bits/stdc++.h>
using namespace std;
int a[105], b[105], m, n, x;
int main()
{
	while (cin >> m >> n >> x)
	{
		memset(b, 0, sizeof b);
		for (int i = 0; i < n; i++) cin >> a[i];
		sort(a, a + n);
		int minn = min(m, n);
		for (int i = 0; i < minn; i++) { b[i] = 1; m--; }
		for (int i = 1; i <= x; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (i >= a[j] && i % a[j] == 0)
				{
					if (i == x || !m) b[j] = 0; 
					else m--;
				}
			}
		}
		int ans = 0;
		for (int i = 0; i < n; i++) 
		{
			if (b[i]) ans ++;
		}
		cout << m << " " << ans << endl;
	}
	return 0;
}