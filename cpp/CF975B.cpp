#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[15], buf[15];
int main()
{
	for (int i = 0; i < 14; i++) cin >> a[i];
	ll ans = 0;
	for (int i = 0; i < 14; i++)
	{
		if (!a[i]) continue;
		for (int j = 0; j < 14; j++) buf[j] = a[j];
		int now = i + 1;
		ll cnt = buf[i];
		buf[i] = 0;
		while (now <= 13 && cnt) { buf[now]++; cnt--; now++; }
		if (cnt)
		{
			ll tmp = cnt / 14;
			for (int j = 0; j < 14; j++) buf[j] += tmp;
			cnt -= tmp * 14;
			now = 0;
			while (now <= 13 && cnt) { buf[now]++; cnt--; now++; }
		}
		ll sum = 0;
		for (int j = 0; j < 14; j++) if (buf[j] % 2 == 0) sum += buf[j];
		ans = max(ans, sum);
	}
	cout << ans << endl;
	return 0;
}