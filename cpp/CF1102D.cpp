#include <bits/stdc++.h>
using namespace std;

int c[3];
int main()
{
	int n; string s;
	while (cin >> n >> s)
	{
		memset(c, 0, sizeof c);
		for (int i = 0; i < n; i++) c[s[i] - '0']++;
		for (int i = 0; i < 3; i++) c[i] -= n / 3;
		for (int i = n - 1; i >= 0; i--)
		{
			bool flg = false;
			for (int j = 0; j < 3; j++)
			{
				for (int k = 2; k >= j + 1; k--)
				{
					if (s[i] == char('0' + j) && c[k] < 0 && c[j] > 0)
					{
						s[i] = char('0' + k); c[k]++; c[j]--; flg = true; break;
					}
				}
				if (flg) break;
			}
		}
		for (int i = 0; i < n; i++)
		{
			bool flg = false;
			for (int j = 2; j >= 0; j--)
			{
				for (int k = 0; k <= j - 1; k++)
				{
					if (s[i] == char('0' + j) && c[k] < 0 && c[j] > 0)
					{
						s[i] = char('0' + k); c[k]++; c[j]--; flg = true; break;
					}
				}
				if (flg) break;
			}
		}
		cout << s << endl;
	}
	return 0;
}