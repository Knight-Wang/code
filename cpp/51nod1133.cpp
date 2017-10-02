#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int INF = 0x3f3f3f3f;

int main()
{
	int n, x, y;
	cin >> n;
	vector<pii> v;
	for (int i = 0; i < n; i++)
	{
		cin >> x >> y;
		v.push_back(pii(x, y));
	}
	sort(v.begin(), v.end());
	int s = INF, cnt = 0;
	for (int i = v.size() - 1; i >= 0; i--)
	{
		if (v[i].second <= s) { s = v[i].first; cnt++; }
	}
	cout << cnt << endl;
	return 0;
}