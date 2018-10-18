#include <iostream>
#include <cassert>
using namespace std;

const int INF = 0x3f3f3f3f;

int a[1005], cov[1005];

int main()
{
	int n, r;
	while (cin >> n >> r)
	{
		fill(cov + 1, cov + n + 1, -1);
		for (int i = 1; i <= n; i++) cin >> a[i];
		for (int i = 1; i <= n; i++)
		{
			for (int j = max(1, i - r + 1); j <= min(n, i + r - 1); j++)
			{
				if (a[j] == 1) cov[i] = j; 
			}
		}
		int maxn = -INF, cnt = 0;
		bool flg = true;
		for (int i = 1; i <= n; i++)
		{
			if (maxn >= i - r + 1 && maxn <= i + r - 1) continue;
			else if (cov[i] == -1) { flg = false; break; }
			else	
			{
				maxn = cov[i];
				cnt++;
			}
		}
		cout << (flg ? cnt : -1) << endl;
	}
	return 0;
}
