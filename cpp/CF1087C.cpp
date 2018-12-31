#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int dis(pii & a, pii & b)
{
	return abs(a.first - b.first) + abs(a.second - b.second);
}
int main()
{
	vector<pii> v(3);
	for (int i = 0; i < 3; i++) cin >> v[i].first >> v[i].second;
	sort(v.begin(), v.end());
	set<pii> p;
	for (int i = v[0].first; i <= v[1].first; i++) p.insert(make_pair(i, v[0].second));
	for (int i = v[2].first; i >= v[1].first; i--) p.insert(make_pair(i, v[2].second));
	int minn = min(v[0].second, min(v[1].second, v[2].second));
	int maxn = max(v[0].second, max(v[1].second, v[2].second));
	for (int j = minn; j <= maxn; j++) p.insert(make_pair(v[1].first, j));
	cout << p.size() << endl;
	for (auto it: p) cout << it.first << " " << it.second << endl;
	return 0;
}