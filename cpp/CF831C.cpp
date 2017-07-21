#include <iostream>
#include <cstdio>
#include <set>
using namespace std;
const int MAXN = 2005;
int a[MAXN], b[MAXN], sum[MAXN];
int main()
{
	int k, n;
	set<int> ans;
	cin >> k >> n;
	for (int i = 1; i <= k; i++) 
	{
		cin >> a[i];
		sum[i] = sum[i - 1] + a[i];
	}
	for (int i = 1; i <= n; i++) cin >> b[i];
	for (int i = 1; i <= k; i++)
	{
		set<int> s;
		for (int j = 1; j <= k; j++)
		{
			if (i == j) continue;
			s.insert(b[1] - (sum[i] - sum[j]));
		}
		bool flg = true;
		for (int j = 2; j <= n; j++)
		{
			if (!s.count(b[j])) { flg = false; break; }
		}
		if (flg) ans.insert(b[1] - sum[i]);
	}
	cout << ans.size() << endl;
	return 0;
}