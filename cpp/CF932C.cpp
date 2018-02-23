#include <bits/stdc++.h>
using namespace std;
int res[1000005];
int main()
{
	int n, a, b;
	while (cin >> n >> a >> b)
	{
		int maxn = max(a, b), minn = min(a, b);
		bool flg = false;
		int i = 0;
		for (; i <= n; i += maxn)
		{
			if ((n - i) % minn == 0) { flg = true; break; }
		}
		if (!flg) { cout << -1 << endl; continue; }
		int x = i / maxn, y = (n - i) / minn;
		int cnt = 0, last = 0;
		for (int i = 0; i < x; i++)
		{
			int start = cnt;
			for (int j = 1 + i * maxn; j <= maxn + i * maxn; j++)
			{
				res[cnt++] = j;
			}
			int tmp = res[start];
			int j = start;
			for (; j < cnt - 1; j++)
			{
				res[j] = res[j + 1];
			}
			res[j] = tmp;
		}
		int fuck = cnt;
		for (int i = 0; i < y; i++)
		{
			int start = cnt;
			for (int j = fuck + 1 + i * minn; j <= fuck + minn + i * minn; j++)
			{
				res[cnt++] = j;	
			}
			int tmp = res[start];
			int j = start;
			for (; j < cnt - 1; j++)
			{
				res[j] = res[j + 1];
			}
			res[j] = tmp;
		}
		for (int i = 0; i < cnt; i++) cout << res[i] << " ";
		cout << endl;
	} 
	return 0;
}