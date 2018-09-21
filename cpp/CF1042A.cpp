#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, m, x;
	while (cin >> n >> m)
	{
		int maxn = 0;
		priority_queue<int, vector<int>, greater<int>> q;
		for (int i = 0; i < n; i++) 
		{
			cin >> x;
			maxn = max(maxn, x);
			q.push(x);
		}
		for (int i = 0; i < m; i++)
		{
			int tmp = q.top(); q.pop();
			q.push(tmp + 1);
		}
		int minn = 0;
		while (!q.empty()) { minn = max(minn, q.top()); q.pop(); }
		cout << minn << " " << maxn + m << endl;
	}
	return 0;
}