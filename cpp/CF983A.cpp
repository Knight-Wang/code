#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ios::sync_with_stdio(false);
	int n; ll p, q, b;
	while (cin >> n)
	{
		for (int i = 0; i < n; i++)
		{
			cin >> p >> q >> b;
			q /= __gcd(p, q);
			ll tmp = __gcd(q, b);
			while (tmp != 1)
			{
				while (q % tmp == 0) q /= tmp;
				tmp = __gcd(q, b);
			}
			if (q == 1) cout << "Finite" << endl;
			else cout << "Infinite" << endl;
		}
	}
	return 0;
}