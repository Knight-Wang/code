#include <iostream>
#include <set>
#include <vector>
using namespace std;

typedef long long ll;

inline bool check(ll x, ll a, ll b)
{
	return x * (x + 1) / 2 <= a + b;
}

int main()
{
	ll a, b;
	while (cin >> a >> b)
	{
		ll l = 1, r = 200000, ans = -1;
		while (l <= r)
		{
			ll m = l + r >> 1;
			if (check(m, a, b))
			{
				l = m + 1;
				ans = m;
			}
			else
			{
				r = m - 1;
			}
		}
		set<int> st;
		int x = min(a, b);
		for (int i = ans; i >= 1; i--)
		{
			if (i > x) continue;
			st.insert(i);
			x -= i;
		}
		set<int> st2;
		for (int i = 1; i <= ans; i++)
		{
			if (!st.count(i)) st2.insert(i);
		}
		if (a > b) swap(st, st2);
		cout << st.size() << endl;
		for (auto it: st) cout << it << " ";
		cout << endl;
		cout << st2.size() << endl;
		for (auto it: st2) cout << it << " ";
		cout << endl;
	}
	return 0;
}
