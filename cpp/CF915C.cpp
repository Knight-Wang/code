#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int cnt[11], buf[11];

bool check(ll t, ll b)
{
	memcpy(buf, cnt, sizeof(int) * 11);
	for (int i = 0; i <= 9; i++)
	{
		while (buf[i]) { t *= 10; t += i; buf[i]--; }
	}
	return t <= b;
}

int main()
{
	string a, b;
	while (cin >> a >> b)
	{
		int x = a.length(), y = b.length();
		for (int i = 0; i < 11; i++) cnt[i] = 0;
		for (int i = 0; i < x; i++) cnt[a[i] - '0']++;
		ll ans = 0;
		bool flg = x < y ? true : false;
		for (int j = y - 1; j > y - x - 1; j--)
		{
			int k = flg ? 9 : b[y - 1 - j] - '0';
			for (; k >= 0; k--)
			{
				if (!cnt[k]) continue;
				cnt[k]--;
				if (check(ans + k, stoll(b)))
				{
					ans += k;
					if (k < b[y - 1 - j] - '0') flg = true; 
					if (j != y - x) ans *= 10; 
					break;
				}
				cnt[k]++;
			}	
		}
		cout << ans << endl;
	}
	return 0;
}