#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int INF = 0x3f3f3f3f;

int a[100005], l[100005], r[100005];
int main()
{
	int n, k, x, minn = INF, maxn = -INF;
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i]; 
		minn = min(minn, a[i]);
		maxn = max(maxn, a[i]);
	}
	if (k == 1) cout << minn << endl;
	else if (k >= 3) cout << maxn << endl;
	else
	{
		memset(l, 0x3f, sizeof l);
		memset(r, 0x3f, sizeof r);
		l[0] = a[0];
		for (int i = 1; i < n - 1; i++)
			l[i] = min(l[i - 1], a[i]);
		r[n - 1] = a[n - 1];
		for (int i = n - 2; i >= 1; i--)
			r[i] = min(r[i + 1], a[i]);
		int ans = -INF;
		for (int i = 0; i <= n - 2; i++)
		{
			ans = max(ans, max(l[i], r[i + 1]));
		}
		cout << ans << endl;
	}
	return 0;
}

