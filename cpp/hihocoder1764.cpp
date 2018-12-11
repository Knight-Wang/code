#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[55];
int main()
{
	int n;
	while (cin >> n)
	{
		for (int i = 0; i < n; i++) cin >> a[i];
		if (n == 1) { cout << 0 << endl; continue; }
		ll ans = a[0];
		for (int i = 1; i < n; i++) ans ^= a[i];
		cout << (!ans ? (1LL << n) - 2 : 0) << endl; 
	}
	return 0;
}