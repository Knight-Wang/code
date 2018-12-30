#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 998244353;

int main()
{
	int n; string s;
	while (cin >> n >> s)
	{
		ll ans = 0; int i = 0, j = n - 1;
		while (i < n - 1 && s[i] == s[i + 1]) i++;
		while (j > 0 && s[j] == s[j - 1]) j--;
		ans = (ans + i + 1 + n - j) % MOD;
		if (s[i] == s[j]) ans = (ans + ((ll)n - j) * (i + 1) % MOD) % MOD;
		cout << (ans + 1) % MOD << endl;
	}
	return 0;
}