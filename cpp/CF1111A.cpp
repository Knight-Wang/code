#include <bits/stdc++.h>
using namespace std;
int main()
{
	string s, t;
	set<char> st;
	st.insert('a'); st.insert('e'); st.insert('i'); st.insert('o'); st.insert('u');
	while (cin >> s >> t)
	{
		if (s.length() != t.length()) { cout << "No" << endl; continue; }
		int n = s.length(); bool flg = true;
		for (int i = 0; i < n; i++)
		{
			if (st.count(s[i]) && !st.count(t[i])) { flg = false; break; }
			else if (!st.count(s[i]) && st.count(t[i])) { flg = false; break; }
		}
		cout << (flg ? "Yes" : "No") << endl;
	}	
	return 0;
}