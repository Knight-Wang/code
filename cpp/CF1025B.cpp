#include <bits/stdc++.h>
using namespace std;
const int MAXN = 150005;
int a[MAXN], b[MAXN];
set<int> factor(int x)
{
	set<int> res;
	for (int i = 2; i * i <= x; i++)
	{
		if (x % i == 0) 
		{
			res.insert(i);
			while (x % i == 0) x /= i;
		}
	}
	if (x != 1) res.insert(x);
	return res;
}
int main()
{
	int n;
	while (scanf("%d", &n) != EOF)
	{
		for (int i = 0; i < n; i++) scanf("%d %d", &a[i], &b[i]);
		set<int>s1 = factor(a[0]);
		set<int>s2 = factor(b[0]);
		set<int> st;
		for (auto it: s1) st.insert(it);
		for (auto it: s2) st.insert(it);
		for (int i = 1; i < n; i++)
		{
			set<int> tmp;
			for (auto it: st)
			{
				if (it > a[i] && it > b[i]) continue;
				else if (a[i] % it && b[i] % it) continue;
				tmp.insert(it);
			}
			st = tmp;
		}
		if (st.empty()) puts("-1");
		else printf("%d\n", *st.begin());
	}
	return 0;
}