#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int n, m, k;

struct cmp
{
	bool operator()(const pii & a, const pii & b)
	{
		if (a.first != b.first) return a.first < b.first;
		return a.second > b.second;
	}
};
int main()
{
	cin >> n >> m >> k;
	priority_queue<pii, vector<pii>, cmp> q;
	vector<int> v;
	int x;
	for (int i = 0; i < m; i++) { cin >> x; v.push_back(x); }
	v.push_back(0); v.push_back(n + 1);
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size() - 1; i++) q.push(pii(v[i + 1] - v[i] - 1, v[i] + 1));
	for (int i = 0; i < k; i++)
	{
		pii tmp = q.top(); q.pop();
		int pos = tmp.second + (tmp.first - 1) / 2;
		cout << pos << endl;
		q.push(pii(pos - tmp.second, tmp.second));
		int r = tmp.second + tmp.first;
		q.push(pii(r - pos - 1, pos + 1));
	}
	return 0;
}