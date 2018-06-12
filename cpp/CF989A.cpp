#include <bits/stdc++.h>
using namespace std;
bool check(string s, int pos)
{
	set<char> st;
	if (s[pos] != '.') st.insert(s[pos]);
	if (s[pos + 1] != '.') st.insert(s[pos + 1]);
	if (s[pos + 2] != '.') st.insert(s[pos + 2]);
	return st.size() == 3;
}
int main()
{
	string s;
	while (cin >> s)
	{
		int n = s.length();
		bool flg = false;
		for (int i = 0; i < n - 2; i++)
		{
			if (check(s, i))
			{
				flg = true; break;
			}
		}
		cout << (flg ? "Yes" : "No") << endl;
	}
	return 0;
}