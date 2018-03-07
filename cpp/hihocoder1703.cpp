#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
ll c[31], k;
int a[31], n;
void dfs(int l, int r, ll k)
{
	if (l > r) return;
	vector<pii> v;
	for (int i = l; i <= r; i++) v.push_back(pii(a[i], i));
	sort(v.begin(), v.end());
	ll tmp = 0, newk = 0;
	int i = 0;
	while (tmp < k) 
	{ 
		int pos = v[i++].second - l + 1;
		newk = k - tmp;
		tmp += c[pos - 1] * c[v.size() - pos];
	}
	int root = v[i - 1].second;
	cout << a[root] << endl;
	ll lc = c[root - l], rc = c[r - root];
	ll lk = (newk + rc - 1) / rc;
	ll rk = (newk % rc == 0 ? rc : newk % rc);
	dfs(l, root - 1, lk); dfs(root + 1, r, rk);
}
int main()
{
	c[0] = c[1] = 1;
	for (int i = 2; i <= 30; i++)
	{
		for (int j = 0; j < i; j++)
		{
			c[i] += c[j] * c[i - j - 1];
		}
	}
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> a[i];
	dfs(1, n, k);
	return 0;
}