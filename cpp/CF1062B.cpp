#include <bits/stdc++.h>
using namespace std;
map<int, int> prime_factor(int n)
{
	map<int, int> res;
	for (int i = 2; i * i <= n; i++)
	{
		while (n % i == 0)
		{
			res[i]++;
			n /= i;
		}
	}
	if (n != 1) res[n] = 1;
	return res;
}
int main()
{
	int n;
	while (cin >> n)
	{
		map<int, int> mp = prime_factor(n);
		int maxn = 1, x = 1, ans = 0;
		for (auto it: mp) { maxn = max(maxn, it.second); x *= it.first; }
		int tmp = 1;
		while (tmp < maxn) { tmp <<= 1; ans++; }
		bool flg = true;
		for (auto it: mp)
		{
			if (it.second < tmp) { flg = false; break; }
		}
		if (!flg) ans++;
		cout << x << " " << ans << endl;
	}
	return 0;
}