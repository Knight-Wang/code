#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n, m;
	while (cin >> n >> m)
	{		
		map<string, string> mp;
		string a, b;
		for (int i = 0; i < n; i++) 
		{
			cin >> a >> b;
			mp[b] = a;
		}
		for (int i = 0; i < m; i++)
		{
			cin >> a >> b;
			cout << a << " " << b << " #"<< mp[b.substr(0, b.length() - 1)] << endl;
		}
	}
	return 0;
}