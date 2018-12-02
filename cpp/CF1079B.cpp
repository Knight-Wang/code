#include <bits/stdc++.h>
using namespace std;

int main()
{
	string s;
	while (cin >> s)
	{
		int n = s.length();
		int r = (n + 19) / 20;
		int c = (n + r - 1) / r;
		int x = n % r;
		cout << r << " " << c << endl;
		int cnt = 0;
		for (int i = 0; i < x; i++)
		{
			for (int j = 0; j < c; j++)
			{
				cout << s[cnt++];
			}
			cout << endl;
		}
		vector<char> v;
		for (int i = x; i < r; i++)
		{
			for (int j = 0; j < n / r; j++)
			{
				cout << s[cnt++];
			}
			if (n % c) cout << "*";
			cout << endl;
		}

	}
	return 0;
}
