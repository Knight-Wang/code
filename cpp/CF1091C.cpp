#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ll n;
	while (cin >> n)
	{
		unordered_set<ll> st;
		for (ll i = 1; i * i <= n; i++)
		{
			if (n % i == 0)
			{
				ll tmp = n / i;
				st.insert((2 + (tmp - 1) * i) * tmp / 2);
				if (tmp != i)
				{
					st.insert((2 + (i - 1) * tmp) * i / 2);
				}
			}
		}
		vector<ll> v;
		for (auto it: st) v.push_back(it);
		sort(v.begin(), v.end());
		for (auto it: v) cout << it << " ";
		cout << endl;
	}
	return 0;
}