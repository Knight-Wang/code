#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
int b[1000005];
int main()
{
	ios::sync_with_stdio(false);
	int T, n;
	cin >> T;
	while (T--)
	{
		cin >> n;
		for (int i = 0; i < n; i++) cin >> b[i];
		sort(b, b + n);
		vector<int> a;
		int now = 0, cnt = 1, ans = -1;
		while (now < n)
		{
			while (now + 1 < n && b[now] == b[now + 1])
			{
				cnt++;
				now++;
			}
			if (cnt >= 4) { ans = b[now]; break; }
			else if (cnt >= 2) a.push_back(b[now]);
			cnt = 1;
			now++;
		}
		if (ans != -1)
		{
			cout << ans << " " << ans << " " << ans << " " << ans << endl;
			continue;
		}
		int m = a.size(), x, y;
		double minn = INF;
		for (int i = 0; i + 1 < m; i++)
		{
			int tmp = (a[i] + a[i + 1]) * 2;
			double t = (double)tmp * tmp / (a[i] * a[i + 1]);
			if (t < minn)
			{
				x = a[i];
				y = a[i + 1];
				minn = t;
			}
		}
		cout << x << " " << x << " " << y << " " << y << endl;
	}
	return 0;
}