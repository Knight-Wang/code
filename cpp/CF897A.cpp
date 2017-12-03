#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n, m, l, r;
	string s;
	char a, b;
	cin >> n >> m >> s;
	for (int i = 0; i < m; i++)
	{
		cin >> l >> r >> a >> b; 
		for (int j = l; j <= r; j++)
		{
			if (s[j - 1] == a) s[j - 1] = b;
		}
	}
	cout << s << endl;
}