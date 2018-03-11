#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 100005;
const ll INF = 0x3f3f3f3f3f3f3f3f;
ll a[MAXN], x[MAXN], minx[MAXN];
int n;
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	minx[0] = INF;
	for (int i = 1; i <= n; i++) 
	{ 
		x[i] = x[i - 1] + a[i];
		minx[i] = min(minx[i - 1], x[i]); 
	}
	bool flg = false;
	ll now = INF;
	for (int i = n; i >= 1; i--)
	{
		now = min(a[i], a[i] + now);
		if (now > 0 && x[n] - x[i - 1] + minx[i - 1] > 0) { cout << i << endl; flg = true ; break; } 
	}
	if (!flg) cout << -1 << endl;
	return 0;
}