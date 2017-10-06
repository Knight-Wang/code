#include <bits/stdc++.h>
using namespace std;
int t[200005], a[200005], vis[200005], n;
int main()
{
	while (cin >> n)
	{
		memset(t, 0, sizeof t); memset(vis, 0, sizeof vis);
		int cnt = 0;
		for (int i = 0; i < n; i++) 
		{
			cin >> a[i]; t[a[i]]++;
			if (t[a[i]] > 1) cnt++;
		}
		cout << cnt << endl;
		queue<int> q;
		for (int i = 1; i <= n; i++) if (!t[i]) q.push(i);
		for (int i = 0; i < n; i++)
		{
			if (!t[a[i]]) continue;
			else if (t[a[i]] == 1 && !vis[a[i]]) 
			{
				cout << a[i] << " "; t[a[i]]--;
			}
			else 
			{
				if (vis[a[i]]) 
				{	
					cout << q.front() << " "; q.pop(); 
				}
				else if (q.front() < a[i])
				{
					cout << q.front() << " "; q.pop(); 
				}
				else 
				{
					cout << a[i] << " "; vis[a[i]] = 1;
				}
				t[a[i]]--;
			}
		}
		cout << endl;
	}
	return 0;
}