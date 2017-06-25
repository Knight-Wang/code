#include <iostream>
#include <cstdio>
using namespace std;

typedef long long ll;

const ll MAXN = 1e18;

ll n, s;

bool check(ll x)
{
	ll sum = 0;
	ll tmp = x;
	while (x)
	{
		sum += x % 10;
		x /= 10;
	}
	return tmp - sum >= s; 
}

int main()
{
	//freopen("c:\\users\\wangyiming\\desktop\\in.txt", "r", stdin);
	cin >> n >> s;
	ll l = 0, r = MAXN + 1, res = MAXN + 1;
	while (l <= r)
	{
		ll m = (l + r) >> 1;
		if (check(m)) r = m - 1, res = m;
		else l = m + 1;
	}
	cout << (n >= res ? n - res + 1 : 0) << endl;
	return 0;
}