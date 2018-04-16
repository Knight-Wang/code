#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	string s;
	set<string> st;
	cin >> n;
	for (int i = 0; i < n; i++) 
	{
		cin >> s;
		st.insert(s);
	}
	int cnt = 0;
	for (auto it : st)
	{
		int l = it.length();
		for (int i = 0; i < l; i++)
		{
			for (int j = i + 1; j < l; j++)
			{
				if (it[i] == it[j]) continue;
				string tmp = it;
				char fuck = tmp[j];
				tmp[j] = tmp[i];
				tmp[i] = fuck;
				if (st.count(tmp)) cnt++; 
			}
		}
	}
	cout << cnt / 2 << endl;
	return 0;
}