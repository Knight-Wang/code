#include <iostream>
#include <cstring>
using namespace std;
int ne[100005][26];
int main()
{
	string s;
	while (cin >> s)
	{
		memset(ne, 0, sizeof ne);
		int n = s.length();
		for (int i = 0; i < 26; i++) ne[n][i] = n;
		for (int i = n - 1; i >= 0; i--)
		{
			for (int j = 0; j < 26; j++)
				ne[i][j] = ne[i + 1][j];
			ne[i][s[i] - 'a'] = i;
		}
		int ans = 1;
		for (int i = 1; i < n; i++)
		{
			int j = i, cur = 0;
			while (j < n)
			{
				if (ne[cur][s[j] - 'a'] < i)
				{
					cur = ne[cur][s[j] - 'a'];
					cur++;
					j++;
				}
				else break;
			}
			ans++;
			i = max(i, j - 1);
		}
		cout << ans << endl;
	}
	return 0;
}
