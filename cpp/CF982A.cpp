#include <bits/stdc++.h>
using namespace std;
int main()
{
	int x; string s;
	while (cin >> x >> s)
	{
		if (x == 1) { cout << (s[0] == '0' ? "No" : "Yes") << endl; continue; }
		if (x == 2) { cout << (s[0] == s[1] ? "No" : "Yes") << endl; continue; }
		if ((s[0] == '0' && s[1] == '0') || (s[x - 2] == '0' && s[x - 1] == '0')) { cout << "No" << endl; continue; }
		bool flg = true;
		for (int i = 0; i < x - 1; i++) 
		{ 
			if (s[i] == '1' && s[i + 1] == '1') { flg = false; break; }
		}
		for (int i = 0; i < x - 2; i++)
		{
			if (s[i] == '0' && s[i + 1] == '0' && s[i + 2] == '0') { flg = false; break; }
		}
		cout << (flg ? "Yes" : "No") << endl;
	}
	return 0;
}