#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, k, A, B;
ll dfs(ll l, ll r, vector<ll>& K, vector<ll>& V, vector<ll>& S)
{
	if (l == r)
	{
		if (binary_search(K.begin(), K.end(), l))
		{
			int p = lower_bound(K.begin(), K.end(), l) - K.begin();
			return B * V[p];
		}
		return A;
	}
	int p1 = lower_bound(K.begin(), K.end(), l) - K.begin();
	int p2 = upper_bound(K.begin(), K.end(), r) - K.begin() - 1;
	if (p1 > p2) return A;
	ll minn = B * (S[p2] - S[p1 - 1]) * (r - l + 1);
	ll m = l + r >> 1;
	minn = min(minn, dfs(l, m, K, V, S) + dfs(m + 1, r, K, V, S));
	return minn;
}
int main()
{
	while (cin >> n >> k >> A >> B)
	{
		map<ll, ll> mp;
		int x;
		for (int i = 1; i <= k; i++)
		{
			cin >> x;
			if (!mp.count(x)) mp[x] = 0;
			mp[x]++;
		}
		vector<ll> K, V, S;
		K.push_back(0); V.push_back(0); S.push_back(0);
		for (auto it: mp) { K.push_back(it.first); V.push_back(it.second); }
		for (int i = 1; i < V.size(); i++) S.push_back(S.back() + V[i]);
		cout << dfs(1, 1 << n, K, V, S) << endl;		
	}	
	return 0;
}