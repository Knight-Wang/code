#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll s[100005];
int main()
{
	int n; ll A, B;
	while (cin >> n >> A >> B)
	{
		ll sum = 0;
		for (int i = 0; i < n; i++) { cin >> s[i]; sum += s[i]; }
		sort(s + 1, s + n);
		ll now = 0; int p = n - 1;
		while (p >= 1 && s[0] * A / (sum - now) < B)
		{
			now += s[p]; p--;
		}
		cout << n - p - 1 << endl;
	}
	return 0;
}