#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 200005;
int t[MAXN], n;
char c[MAXN];
int get_sum(int i, vector<int> & v, char color)
{
	int maxn = 0, last = v[i];
	for (int j = v[i] + 1; j <= v[i + 1]; j++)
	{
		if (c[j] == color || c[j] == 'P')
		{
			if (t[j] - t[last] > maxn) maxn = t[j] - t[last];
			last = j;
		}
	}
	return last == v[i] ? 0 : t[v[i + 1]] - t[v[i]] - maxn;
}
int main()
{
	while (cin >> n)
	{
		int p_start = -1, p_end = -1, r_start = -1, r_end = -1, b_start = -1, b_end = -1;
		vector<int> v;
		for (int i = 0; i < n; i++) 
		{ 
			cin >> t[i] >> c[i];
			if (c[i] == 'P')
			{
				p_end = i;
				if (p_start == -1) p_start = i;
				v.push_back(i);
			}
			else if (c[i] == 'R')
			{
				r_end = i;
				if (r_start == -1) r_start = i;
			}
			else
			{
				b_end = i;
				if (b_start == -1) b_start = i;
			}
		}
		ll ans = 0;
		if (p_start == -1) 
		{ 
			if (r_start != -1) ans += t[r_end] - t[r_start];
			if (b_start != -1) ans += t[b_end] - t[b_start];
			cout << ans << endl;
			continue;
		}
		if (r_start != -1)
		{
			if (r_start < p_start) ans += t[p_start] - t[r_start];
			if (r_end > p_end) ans += t[r_end] - t[p_end];
		}
		if (b_start != -1)
		{
			if (b_start < p_start) ans += t[p_start] - t[b_start];
			if (b_end > p_end) ans += t[b_end] - t[p_end];
		}
		for (int i = 0; i < v.size() - 1; i++)
		{
			int tmp_R = get_sum(i, v, 'R'), tmp_B = get_sum(i, v, 'B');
			if (!tmp_R && !tmp_B) { ans += t[v[i + 1]] - t[v[i]]; continue; }
			int minn = 2 * (t[v[i + 1]] - t[v[i]]);
			int tmp = tmp_R + tmp_B + t[v[i + 1]] - t[v[i]];
			minn = min(minn, tmp);
			ans += minn;
		}
		cout << ans << endl;
	}
	return 0;
}