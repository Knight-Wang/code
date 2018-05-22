#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
const int INF = 0x3f3f3f3f;

typedef pair<int, int> pii;

pii a[MAXN];

int main()
{
	int n;
	while (cin >> n)
	{
		for (int i = 1; i <= n; i++) { cin >> a[i].first; a[i].second = i; }
		sort(a + 1, a + n + 1);
		set<pii> st; st.insert(pii(1, n));
		map<int, int> mp; mp[n] = 1;
		int maxn = 0, ans = -1;
		for (int i = n; i >= 1; i--)
		{
			if ((int)mp.size() == 1 && mp.begin()->second >= maxn)
			{
				maxn = mp.begin()->second; ans = a[i].first + 1;
			}
			auto it = st.upper_bound(pii(a[i].second, INF));
			it--;
			if (it->first <= a[i].second - 1)
			{
				pii x(it->first, a[i].second - 1);
				st.insert(x);
				mp[x.second - x.first + 1]++;
			}
			if (a[i].second + 1 <= it->second)
			{
				pii y(a[i].second + 1, it->second);
				st.insert(y);
				mp[y.second - y.first + 1]++;
			}
			int l = it->second - it->first + 1;
			st.erase(it);
			mp[l]--; if (!mp[l]) mp.erase(l);
		}
		cout << ans << endl;
	}
	return 0;
}