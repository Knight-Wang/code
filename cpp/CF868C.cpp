#include <bits/stdc++.h>
using namespace std;
int a[20], b[4], n, k;
int main()
{
	while (cin >> n >> k)
	{
		memset(a, 0, sizeof a);
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < k; j++)
			{
				cin >> b[j];
			}
			a[b[0] + b[1] * 2 + b[2] * 4 + b[3] * 8]++;
		}
		bool flg = false;
		for (int i = 0; i < (1 << k); i++)
		{
			if (flg) break;
			for (int j = 0; j < (1 << k); j++)
			{
				if (!(i & j) && a[i] && a[j])
				{
					flg = true; break;
				}
			}
		}
		cout << (flg ? "YES" : "NO") << endl;
	}
	return 0;
}