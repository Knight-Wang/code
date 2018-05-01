#include <bits/stdc++.h>
using namespace std;
int main()
{
	int x;
	string s;
	cin >> x >> s;
	int cnt0 = 0, cnt1 = 0;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == '0') cnt0++;
		else cnt1++;
	}
	if (cnt1) cout << 1;
	for (int i = 0; i < cnt0; i++) cout << 0;
	cout << endl;
	return 0;
}