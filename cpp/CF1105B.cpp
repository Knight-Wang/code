#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, k; string s;
	while (cin >> n >> k >> s)
	{
		int ans = 0;
		for (char i = 'a'; i <= 'z'; i++)
		{
			int j = 0, len = 0, cnt = 0;
			while (j < s.length())
			{
				while (s[j] == i) { j++; len++; }
				cnt += len / k;
				len = 0;
				j++;
			}
			ans = max(ans, cnt);
		}
		cout << ans << endl;
	}
	return 0;
}