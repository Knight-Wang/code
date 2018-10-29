#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 500005;
const ll INF = 0x3f3f3f3f3f3f3f3f;

ll s[MAXN], sum[MAXN];

int main()
{
	int T, n;
	ll o, d, a, b, c, m, l;
	cin >> T;
	for (int t = 1; t <= T; t++)
	{
		cin >> n >> o >> d;
		cin >> s[1] >> s[2] >> a >> b >> c >> m >> l;
		for (int i = 3; i <= n; i++)
			s[i] = (a * s[i - 1] + b * s[i - 2] + c) % m;
		for (int i = 1; i <= n; i++) s[i] += l;
		for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + s[i];
		ll maxn = -INF;
		int start = 1, odd = 0;
		multiset<ll> st;
		for (int i = 1; i <= n; i++)
		{
			odd += (s[i] & 1);
			st.insert(sum[i - 1]);
			while (start <= i && odd > o)
			{
				odd -= (s[start] & 1);
				st.erase(sum[start - 1]);
				start++;
			}
			if (start <= i)
			{
				auto it = st.lower_bound(sum[i] - d);
				if (it != st.end()) maxn = max(maxn, sum[i] - *it);
			}
		}
		cout << "Case #" << t << ": ";
		if (maxn == -INF) cout << "IMPOSSIBLE" << endl;
		else cout << maxn << endl;
	}
	return 0;
}
