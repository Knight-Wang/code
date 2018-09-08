#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAXN = 200005;
int a[MAXN], l[MAXN], r[MAXN];
int main()
{
	int n, q;
	while (cin >> n >> q)
	{
		for (int i = 1; i <= q; i++) { l[i] = INF; r[i] = -INF; }
		int c0 = 0, cq = 0;
		for (int i = 1; i <= n; i++) 
		{
			cin >> a[i];
			c0 += a[i] == 0;
			cq += a[i] == q;
			if (a[i] == 0) continue;
			l[a[i]] = min(l[a[i]], i);
			r[a[i]] = max(r[a[i]], i);
		}
		if (!c0 && !cq) { cout << "NO" << endl; continue; }
		set<int> st;
		bool flg = true;
		for (int i = 1; i <= n; i++)
		{
			if (i == l[a[i]]) st.insert(a[i]);
			if (a[i] && !st.empty() && *st.rbegin() != a[i]) { flg = false; break; }
			int tmp = -1;
			if (a[i] == 0)
			{
				if (cq == 0) { tmp = q; cq++; }
				else if (!st.empty()) tmp = *st.rbegin();
				else tmp = 1;
			}
			if (i == r[a[i]]) st.erase(st.find(a[i]));
			if (tmp != -1) a[i] = tmp;
		}
		if (!cq || !flg) { cout << "NO" << endl; continue; }
		cout << "YES" << endl;
		for (int i = 1; i <= n; i++) cout << a[i] << " ";
		cout << endl;
	}
	return 0;
}