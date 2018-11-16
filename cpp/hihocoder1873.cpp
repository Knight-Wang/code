#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[61];
int main()
{
	a[1] = 1, a[2] = 2;
	for (int i = 3; i <= 60; i++) a[i] = a[i - 1] + a[i - 2];
	ll m;
	while (cin >> m)
	{
		if (m == 0) { cout << "2\n1 1\n2 1\n"; continue; }
		vector<int> v;
		while (m > 0)
		{
			int pos = upper_bound(a + 1, a + 50, m) - 1 - a;
			m -= a[pos];
			v.push_back(pos);
		}
		cout << v.size() + 1 << endl;
		for (int i = 0; i < v.size(); i++)
		{
			cout << 2 * i + 1 << " " << 199 - v[i] + 1 << endl;
		}
		cout << 2 * v.size() << " " << 2 * v.size() << endl;
	}
	return 0;
}