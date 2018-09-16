#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 100005;
ll a[MAXN];
int main()
{
	int n;
	while (cin >> n)
	{
		ll sum = 0;
		map<ll, ll> mp;
		for (int i = 1; i <= n; i++) 
		{ 
			cin >> a[i]; 
			sum += a[i]; 
			if (!mp.count(a[i])) mp[a[i]] = 1;
			else mp[a[i]] += 1;
		}
		while (!mp.empty())
		{
			sum -= mp.begin()->first * mp.begin()->second;
			n -= mp.begin()->second;
			cout << sum - n * mp.begin()->first << endl;
			mp.erase(mp.begin());
		}
		
	}
	return 0;
}