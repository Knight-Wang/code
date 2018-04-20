#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1005;
int t[MAXN];
int main()
{
	int n, A, B, C, T;
	while (cin >> n >> A >> B >> C >> T)
	{
		for (int i = 0; i < n; i++) cin >> t[i];
		int ans = n * A;
		if (B < C)
		{
			for (int i = 0; i < n; i++)
			{
				ans += (T - t[i]) * (C - B);
			}
		}
		cout << ans << endl;
	}
	return 0;
}