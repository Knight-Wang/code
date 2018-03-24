#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ll n, q, x;
	cin >> n >> q;
	while (q--)
	{
		cin >> x;
		while (!(x & 1)) x += n - x / 2;
		cout << (x + 1 >> 1) << endl;
	}
	return 0;
}
