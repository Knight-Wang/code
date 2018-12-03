#include <bits/stdc++.h>
using namespace std;
pair<int, int> a[505];

bool cmp(pair<int, int> a, pair<int, int> b)
{
	return a.first > b.first;
}

int main()
{
	int n;
	while (cin >> n)
	{
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i].first;
			a[i].second = i;
		}
		sort(a + 1, a + n + 1, cmp);
		int i = n;
		for ( ; i >= 1; i--)
		{
			if (a[i].first > 1) break;
		}
		int sum = 0;
		if (i == 1) sum = a[1].first;
		else
		{
			for (int j = 1; j <= i; j++)
			{
				if (j == 1 || j == i) sum += a[j].first - 1;
				else sum += a[j].first - 2;
			}
		}
		if (sum >= n - i)
		{
			cout << "YES " << i - 1 + (n - i >= 2 ? 2 : n - i) << endl;
			cout << n - 1 << endl;
			if (a[n].first == 1) cout << a[n].second << " " << a[i].second << endl;
			for (int j = 1; j < i; j++)
			{
				cout << a[j].second << " " << a[j + 1].second << endl;
				if (j == 1) a[j].first--;
				else a[j].first -= 2;
			}
			if (i > 1) a[i].first--;
			int now = 1;
			for (int j = i + 1; j < n; j++)
			{
				if (a[now].first)
				{
					cout << a[j].second << " " << a[now].second << endl;
					a[now].first--;
				}
				else { now++; j--; }
			}
		}
		else cout << "NO" << endl;
	}
	return 0;
}