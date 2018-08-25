#include <bits/stdc++.h>
using namespace std;
bool check(string s, int x)
{
	int n = s.length();
	for (int i = 0; i < x; i++)
	{
		if (s[i] != s[i + n - x]) return false;
	}
	return true;
}
int main()
{
	int n, t;
	string s;
	while (cin >> n >> t >> s)
	{
		int ans = 0;
		for (int i = 1; i <= n - 1; i++)
		{
			if (check(s, i)) ans = i;
		}
		for (int i = 0; i < t; i++)
		{
			int end = n - ans;
			if (i == t - 1) end += ans;
			for (int j = 0; j < end; j++)
				cout << s[j];
		}
		cout << endl;
	}
	return 0;
}