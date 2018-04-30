#include <bits/stdc++.h>
using namespace std;
int a[105];
int main()
{
	int n, s, h, m;
	while (cin >> n >> s)
	{
		for (int i = 0; i < n; i++)
		{
			cin >> h >> m;
			a[i + 1] = h * 60 + m;
		}
		int ans = 0;
		if (a[1] < s + 1)
		{
			int i = 2;
			for (; i <= n; i++)
			{
				if (a[i] - a[i - 1] - 2 >= 2 * s) break;
			}
			ans = a[i - 1] + 1 + s;
		}
		cout << ans / 60 << " " << ans % 60 << endl;
	}
	return 0;
}