#include <bits/stdc++.h>
using namespace std;
int a[100005];
int main()
{
	int n, k;
	while (cin >> n >> k)
	{
		for (int i = 1; i <= n; i++) cin >> a[i];
		sort(a + 1, a + n + 1);
		vector<int> v;
		v.push_back(a[1]);
		for (int i = 2; i <= n; i++)
		{
			if (a[i] - a[i - 1]) v.push_back(a[i] - a[i - 1]);
		}
		for (int i = 0; i < min((int)v.size(), k); i++) cout << v[i] << endl;
		if (k > v.size())
		{
			for (int i = 0; i < k - v.size(); i++) cout << 0 << endl;
		}
	}
	return 0;
}