#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int MAXN = 100005;
pii a[MAXN];
int bit[MAXN];
int lowbit(int i) { return i & -i; }
void add(int i, int x)
{
	while (i <= 100000) { bit[i] += x; i += lowbit(i); }
}
int sum(int i)
{
	int ans = 0;
	while (i) { ans += bit[i]; i -= lowbit(i); }
	return ans;
}
bool check(int x, int k)
{
	int num = sum(100000) - sum(x - 1);
	return num >= k;
}
int main()
{
	int n;
	scanf("%d", &n);
	vector<int> v;
	for (int i = 0; i < n; i++) 
	{
		scanf("%d%d", &a[i].first, &a[i].second);
		if (a[i].first == 0) v.push_back(a[i].second);
	}
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	for (int i = 0; i < n; i++)
	{
		if (a[i].first == 2) continue;
		a[i].second = lower_bound(v.begin(), v.end(), a[i].second) - v.begin() + 1;
	}
	set<int> st;
	for (int i = 0; i < n; i++)
	{
		if (a[i].first == 0) 
		{
			if (!st.count(a[i].second)) 
			{ 
				st.insert(a[i].second); 
				add(a[i].second, 1);
			}
		}
		else if (a[i].first == 1) 
		{
			if (st.count(a[i].second)) 
			{
				st.erase(a[i].second);
				add(a[i].second, -1);
			}
		}
		else
		{
			int ans = -1;
			int l = 1, r = 100000;
			while (l <= r)
			{
				int m = l + r >> 1;
				if (check(m, a[i].second))
				{
					l = m + 1;
					ans = m;
				}
				else r = m - 1;
			}
			printf("%d\n", v[ans - 1]);
		}
	}
	return 0;
}