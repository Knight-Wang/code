#include <bits/stdc++.h>
using namespace std;
bool ok[3005];
bool check(char x)
{
	return x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u'; 
}
int main()
{
	string s;
	cin >> s;
	int n = s.length();
	for (int i = 0; i <= n - 3; i++)
	{
		if (!check(s[i]) && !check(s[i + 1]) && !check(s[i + 2]) && 
		    !(s[i] == s[i + 1] && s[i + 1] == s[i + 2]))
		{
			ok[i + 2] = 1;
			i++;
		}
	}
	for (int i = 0; i < n; i++)
	{
		cout << s[i];
		if (ok[i + 1]) cout << " ";
	}
	return 0;
}