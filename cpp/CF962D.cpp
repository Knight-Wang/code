#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 150005;
ll a[MAXN];
int main()
{
	int n;
	while (cin >> n)
	{
		map<ll, int> mp;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
			if (mp.count(a[i])) 
			{ 
				while (mp.count(a[i]))
				{
					a[mp[a[i]]] = -1;
					mp.erase(a[i]);
					a[i] <<= 1;
				}
			}
			mp[a[i]] = i;
		}
		vector<ll> v;
		for (int i = 0; i < n; i++)
		{
			if (a[i] != -1) v.push_back(a[i]);
		}
		cout << v.size() << endl;
		for (int i = 0; i < v.size(); i++) cout << v[i] << " ";
		cout << endl;
	}
	return 0;
}