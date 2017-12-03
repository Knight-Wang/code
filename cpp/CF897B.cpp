#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll digit(int x)
{
	ll res = 1;
	while (x) { x /= 10; res *= 10; }
	return res;
}
ll rev_int(ll x)
{
	string tmp = "";
	while (x)
	{
		tmp += (char)(x % 10 + '0');
		x /= 10;
	}
	ll ret = 0;
	for (int i = 0; i < tmp.size(); i++)
	{
		ret += tmp[i] - '0';
		if (i != tmp.size() - 1) ret *= 10;
	}
	return ret;
}
int main()
{
	ll k, p, sum = 0;
	cin >> k >> p;
	for (int i = 1; i <= k; i++)
	{
		sum = (sum + (ll)i * digit(i)) % p;
		sum = (sum + rev_int(i)) % p;
	}
	cout << sum << endl;
	return 0;
}