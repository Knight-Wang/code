#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n; string s;
	while (cin >> n >> s)
	{
		int i = 0;
		for ( ; i < n - 1; i++)
		{
			if (s[i + 1] < s[i]) break;
		}
		for (int j = 0; j < n; j++)
		{
			if (j == i) continue;
			cout << s[j];
		}
		cout << endl;
	}
	return 0;
}