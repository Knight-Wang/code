#include <bits/stdc++.h>
using namespace std;
int a[5], ans;
unordered_map<int, int> mp;
int main()
{
	while (cin >> a[0] >> a[1] >> a[2] >> a[3] >> a[4])
	{
		for (int i = -50; i <= 50; i++)
		{
			if (!i) continue;
			for (int j = -50; j <= 50; j++)
			{
				if (!j) continue;
				for (int k = -50; k <= 50; k++)
				{
					if (!k) continue;
					mp[a[0]*i*i*i + a[1]*j*j*j + a[2]*k*k*k]++;
				}
			}
		}
		int ans = 0;
		for (int i = -50; i <= 50; i++)
		{
			if (!i) continue;
			for (int j = -50; j <= 50; j++)
			{
				if (!j) continue;
				int tmp = a[3]*i*i*i + a[4]*j*j*j;
				if (mp.count(-tmp)) ans += mp[-tmp];
			}
		}
		cout << ans << endl;
	}
	return 0;
}