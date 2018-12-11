#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
const int INF = 0x3f3f3f3f;
int sta[MAXN], ele[MAXN];
int main()
{
	int n, m, l, e, v, q, x1, y1, x2, y2;
	while (cin >> n >> m >> l >> e >> v)
	{
		for (int i = 0; i < l; i++) cin >> sta[i];
		sort(sta, sta + l);
		for (int i = 0; i < e; i++) cin >> ele[i];
		sort(ele, ele + e);
		cin >> q;
		for (int i = 0; i < q; i++) 
		{
			cin >> x1 >> y1 >> x2 >> y2;
			if (x1 == x2) { cout << abs(y1 - y2) << endl; continue; }
			int ans = INF;
			if (l)
			{
				int pos = lower_bound(sta, sta + l, y1) - sta;
				if (pos == l) pos = l - 1;
				else if (y1 != sta[pos] && pos >= 1 && (sta[pos] - y1 + abs(sta[pos] - y2) > y1 - sta[pos - 1] + abs(sta[pos - 1] - y2)))
				{
					pos--;
				}
				int minn = abs(y1 - sta[pos]) + abs(y2 - sta[pos]) + abs(x2 - x1);
				ans = min(ans, minn);
			}
			if (e)
			{
				int pos = lower_bound(ele, ele + e, y1) - ele;
				if (pos == e) pos = e - 1;
				else if (y1 != ele[pos] && pos >= 1 && (ele[pos] - y1 + abs(ele[pos] - y2) > y1 - ele[pos - 1] + abs(ele[pos - 1] - y2)))
				{
					pos--;
				}
				int minn = abs(y1 - ele[pos]) + abs(y2 - ele[pos]) + (v >= abs(x2 - x1) ? 1 : ((abs(x2 - x1) + v - 1) / v));
				ans = min(ans, minn);
			}
			cout << ans << endl;
		}
	}
	return 0;
}