#include <bits/stdc++.h>
using namespace std;
int a[105];
int main()
{
	int n, k, x;
	while (cin >> n >> k)
	{
		memset(a, 0, sizeof a);
		for (int i = 0; i < n; i++) { cin >> x; a[x]++; }
		int maxn = 0;
		for (int i = 0; i <= 100; i++) maxn = max(maxn, a[i]);
		while (maxn % k != 0) maxn++;
		int cnt = 0;
		for (int i = 0; i <= 100; i++)
		{
			if (a[i] != 0) cnt += maxn - a[i];
		}
		cout << cnt << endl;
	}
	return 0;
}
