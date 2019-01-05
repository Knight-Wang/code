#include <bits/stdc++.h>
using namespace std;

int main()
{
	string t, a;
	while (cin >> t)
	{
		bool flg = false;
		for (int i = 0; i < 5; i++) 
		{
			cin >> a;
			if (t[0] == a[0] || t[1] == a[1]) flg = true;
		}
		cout << (flg ? "YES" : "NO") << endl;
	}
	return 0;
}