#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
const long long INF = 0x3f3f3f3f3f3f3f3f;
struct node
{
	double x, y;
	int type, id;
};
node a[200005], py[200005];
bool cmp(const node & a, const node & b)
{
	return a.x < b.x;
}
bool cmp2(const node & a, const node & b)
{
	return a.y < b.y;
}
double dis(pii x)
{
	int p = x.first, q = x.second;
	if (p == -1 || q == -1) return INF;
	if (a[p].type == a[q].type) return INF;
	return sqrt(pow(a[p].x - a[q].x, 2) + pow(a[p].y - a[q].y, 2));
}
pii solve(int l, int r, vector<int> s)
{
	if (l == r) return pair<int, int>(-1, -1);
	if (r - l == 1) return pair<int, int>(l, r);
	int m = l + r >> 1;
	vector<int> ls(m - l + 1), rs(r - m);
	int i = 0, j = 0;
	for (auto it : s) 
	{ 
		if (it <= m) ls[i++] = it; 
		else rs[j++] = it;
	}
	pii lc = solve(l, m, ls);
	pii rc = solve(m + 1, r, rs);
	double dta = min(dis(lc), dis(rc));
	double L = a[ls.back()].x;
	vector<int> sy;
	for (int i = 0; i < s.size(); i++)
	{
		if (a[s[i]].x >= L - dta && a[s[i]].x <= L + dta)
		{
			sy.push_back(s[i]);
		}
	}
	pii ans(-1, -1);
	for (int i = 0; i < sy.size(); i++)
	{
		for (int j = i + 1; j <= i + 11 && j < sy.size(); j++)
		{
			double tmp = dis(pii(sy[i], sy[j]));
			if (tmp < dta)
			{
				dta = tmp; ans = pii(sy[i], sy[j]);
			}
		}
	}
	if (ans != pii(-1, -1)) return ans;
	if (dis(lc) < dis(rc)) return lc;
	return rc;
}
int main()
{
	ios::sync_with_stdio(false);
	int t, n;
	cin >> t;
	while (t--)
	{
		cin >> n;
		for (int i = 0; i < 2 * n; i++)
		{
			cin >> a[i].x >> a[i].y;
			a[i].type = i >= n ? 1 : 0;
		}
		sort(a, a + 2 * n, cmp);
		for (int i = 0; i < 2 * n; i++) a[i].id = i;
		memcpy(py, a, 2 * n * sizeof(node));
		sort(py, py + 2 * n, cmp2);
		vector<int> s;
		for (int i = 0; i < 2 * n; i++) s.push_back(py[i].id);
		pii ret = solve(0, 2 * n - 1, s);
		printf("%.3f\n", dis(ret));
	}
	return 0;
}