#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 0x3f3f3f3f3f3f3f3f;

int main()
{
	int q;
	ll l, r, d;
	cin >> q;
	while (cin >> l >> r >> d)
	{
		if (d < l) cout << d << endl;
		else cout << (r / d + 1) * d << endl;
	}
	return 0;
}