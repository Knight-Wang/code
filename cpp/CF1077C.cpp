#include<bits/stdc++.h>
using namespace std;
int a[200005], l[200005], r[200005];
int main()
{
	int n;
	while (cin >> n)
	{
		long long sum = 0;
		for (int i = 1; i <= n; i++) { cin >> a[i]; sum += a[i]; }
		for (int i = 1; i <= n; i++) l[i] = max(l[i - 1], a[i]);
		for (int i = n; i >= 1; i--) r[i] = max(r[i + 1], a[i]);
		vector<int> ans;
		for (int i = 1; i <= n; i++)
		{
			int tmp = max(l[i - 1], r[i + 1]);
			if (sum - tmp - a[i] == tmp) ans.push_back(i);
		}
		cout << ans.size() << endl;
		for (auto it: ans) cout << it << " ";
		cout << endl;
	}
	return 0;
}