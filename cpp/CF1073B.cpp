#include <iostream>
#include <cstring>
using namespace std;
int a[200005], pos[200005];
int main()
{
	ios::sync_with_stdio(false);
	int n, x;
	while (cin >> n)
	{
		memset(a, 0, sizeof a);
		for (int i = 1; i <= n; i++) { cin >> a[i]; pos[a[i]] = i; }
		int maxn = 0;
		for (int i = 1; i <= n; i++)
		{
			cin >> x;
			if (pos[x] < maxn) cout << 0 << endl;
			else
			{
				cout << pos[x] - maxn << endl;
				maxn = pos[x];
			}
		}
	}
	return 0;
}
