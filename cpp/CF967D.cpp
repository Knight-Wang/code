#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
pii c[300005];
int n, x1, x2;
vector<int> check(int a, int b)
{
	bool flg = false;
	int tmp, tmp2, l, l2, i = 0;
	for ( ; i < n; i++)
	{
		tmp = c[i].first; l = (a + tmp - 1) / tmp;
		if (i + l >= n) continue;
		tmp2 = c[i + l].first; l2 = (b + tmp2 - 1) / tmp2;
		if (i + l + l2 > n) continue;
		flg = true; break;
	}
	vector<int> ans;
	if (flg) { ans.push_back(i); ans.push_back(l); ans.push_back(l2); }
	return ans;
}
void show(vector<int> & v, bool rev)
{
	vector<int> v1, v2;
	for (int i = v[0]; i < v[0] + v[1]; i++) v1.push_back(c[i].second);
	for (int i = v[0] + v[1]; i < v[0] + v[1] + v[2]; i++) v2.push_back(c[i].second);
	cout << "Yes" << endl;
	if (rev)
	{
		cout << v[2] << " " << v[1] << endl;
		for (auto it: v2) cout << it << " ";
		cout << endl;
		for (auto it: v1) cout << it << " ";
		cout << endl;
	}
	else
	{
		cout << v[1] << " " << v[2] << endl;
		for (auto it: v1) cout << it << " ";
		cout << endl;
		for (auto it: v2) cout << it << " ";
		cout << endl;
	}
}
int main()
{
	while (cin >> n >> x1 >> x2)
	{
		for (int i = 0; i < n; i++) { cin >> c[i].first; c[i].second = i + 1; }
		sort(c, c + n);
		vector<int> ans = check(x1, x2);
		if (ans.size()) { show(ans, false); continue; }
		ans = check(x2, x1);
		if (ans.size()) { show(ans, true); continue; }
		cout << "No" << endl;
	}
	return 0;
}