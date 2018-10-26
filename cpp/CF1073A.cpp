#include <iostream>
using namespace std;
int main()
{
	int n;
	string s;
	while (cin >> n)
	{
		cin >> s;
		string ans = "";
		for (int i = 0; i < n - 1; i++)
		{
			if (s[i] != s[i + 1]) { ans = s.substr(i, 2); break; }
		}
		if (ans == "") cout << "NO" << endl;
		else cout << "YES\n" << ans << endl;
	}
	return 0;
}
