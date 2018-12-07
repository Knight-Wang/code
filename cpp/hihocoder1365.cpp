#include <bits/stdc++.h>
using namespace std;

int w[100005], h[100005], dp[100005], m, n;

void arrange(int w, int h, int& rw, int& rh)
{
	if (rw >= w) { rw -= w; rh = max(rh, h); }
	else { rh = max(rh, (rw * h + w - 1) / w); rw = 0; }
}

int solve()
{
	for (int i = n - 1; i >= 0; i--)
	{
		int rw = m, maxh = 0;
		int j = i;
		for ( ; j < n && rw; j++)
			arrange(w[j], h[j], rw, maxh);
		dp[i] = dp[j] + maxh;
	}
	int minn = dp[1], th = 0, rw = m, rh = 0;
	for (int i = 0; i < n; i++)
	{
		arrange(w[i], h[i], rw, rh);
		if (!rw) { th += rh; rw = m; rh = 0; }
		int j = i + 2, tmpw = rw, tmph = rh;
		for ( ; j < n && tmpw; j++)
		{
			arrange(w[j], h[j], tmpw, tmph);
		}
		minn = min(minn, th + tmph + (j < n ? dp[j] : 0));
	}
	return minn;
}

int main()
{
	cin >> m >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> w[i] >> h[i];
	}
	cout << solve() << endl;
	return 0;
}