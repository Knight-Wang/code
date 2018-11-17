#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	long long a, b, k;
	cin >> n;
	while (n--)
	{
		cin >> a >> b >> k;
		long long ans = (a - b) * (k / 2);
		if (k & 1) ans += a;
		cout << ans << endl;
	}

	return 0;
}