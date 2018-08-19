#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n, k;
	string s;
	while (cin >> n >> k >> s)
	{
		int x = n - k >> 1;
		stack<char> sta;
		int i = 0;
		for ( ; i < n; i++)
		{
			if (x == 0) break;
			if (s[i] == '(') sta.push(s[i]);
			else { sta.pop(); x--; }
		}
		for (int j = 0; j < sta.size(); j++) cout << '(';
		for (int j = i; j < n; j++) cout << s[j];
		cout << endl;
	}
	return 0;
}