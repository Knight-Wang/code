#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const string s = "What are you doing at the end of the world? Are you busy? Will you save us?";
const string t = "What are you doing while sending \"";
const string v = "\"? Are you busy? Will you send \"";
const ll len_s = s.length();
const ll len_t = t.length();
const ll len_v = v.length();
ll len[100005];
char dfs(ll n, ll k)
{
	if (n == 0) 
	{
		if (k >= 1 && k <= len_s) return s[k - 1];
		else return '.';
	}
	else if (n >= 54)
	{
		if (k <= len_t) return t[k - 1];
		return dfs(n - 1, k - len_t);
	}
	else 
	{
		if (k <= len_t) return t[k - 1];
		else if (k > len_t && k <= len_t + len[n - 1])
			return dfs(n - 1, k - len_t);
		else if (k > len_t + len[n - 1] && k <= len_t + len[n - 1] + len_v)
			return v[k - len_t - len[n - 1] - 1];
		else if (k > len_t + len[n - 1] + len_v && k <= len_t + 2 * len[n - 1] + len_v)
			return dfs(n - 1, k - len_t - len[n - 1] - len_v);
		else if (k == len_t + 2 * len[n - 1] + len_v + 1)
			return '\"';
		else if (k == len_t + 2 * len[n - 1] + len_v + 2)
			return '?';
		else return '.';
	}
}
int main()
{
	len[0] = (ll)len_s;
	for (int i = 1; i <= 53; i++)
	{
		len[i] = len[i - 1] * 2 + len_t + len_v + 2;
	}
	ll q, n, k;
	cin >> q;
	while (q--)
	{
		cin >> n >> k;
		cout << dfs(n, k);
	}
	return 0;
}