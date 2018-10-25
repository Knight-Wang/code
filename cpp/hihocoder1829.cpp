#include <iostream>
#include <set>
#include <vector>
using namespace std;

void get_subseq(string s, string x, int cur, set<string>& st)
{
	if (cur == s.length()) { if (x != "") st.insert(x); return; }
	get_subseq(s, x + s[cur], cur + 1, st);
	get_subseq(s, x, cur + 1, st);
}

bool is_subseq(string s, string t)
{
	int i = 0, j = 0;
	while (i < s.length() && j < t.length())
	{
		if (t[j] != s[i]) j++;
		else i++;
	}
	return i == s.length();
}

bool check(string s, vector<string> v)
{
	for (int i = 1; i < v.size(); i++)
	{
		bool flg = false;
		int l = v[i].length();
		for (int j = 0; j < l; j++)
		{
			string tmp = v[i].substr(j, l - j) + v[i].substr(0, j);
			if (is_subseq(s, tmp)) { flg = true; break; }
		}
		if (!flg) return false;
	}
	return true;
}

int main()
{
	int n;
	string s;
	while (cin >> n)
	{
		vector<string> v;
		for (int i = 0; i < n; i++) { cin >> s; v.push_back(s); }
		set<string> st;
		vector<string> buf;
		get_subseq(v[0], "", 0, st);
		for (auto it: st)
		{
			int l = it.length();
			for (int i = 1; i < l; i++)
			{
				string tmp = it.substr(i, l - i) + it.substr(0, i);
				buf.push_back(tmp);
			}
		}
		for (auto it: buf) st.insert(it);
		int maxn = 0; string ans = "zzzzzzzzzz";
		for (auto it: st)
		{
			if (check(it, v) && (it.length() > maxn || (it.length() == maxn && it < ans)))
			{
				ans = it;
				maxn = it.length();
			}
		}
		if (ans == "zzzzzzzzzz") cout << 0 << endl;
		else cout << ans << endl;
	}
	return 0;
}
