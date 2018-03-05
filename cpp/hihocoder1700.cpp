#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
long hex2long(string s)
{
	char * tmp;
	return strtol(s.c_str(), &tmp, 16);
}
int sqr(int x) { return x * x; }
char trans(int x) { return x < 10 ? '0' + x : 'a' + x - 10; }
int main()
{
	string t;
	cin >> t;
	int minn = INF;
	string res = "";
	for (int i = 0; i < 16; i++)
	{
		for (int j = 0; j < 16; j++)
		{
			for (int k = 0; k < 16; k++)
			{
				int ans = 0;
				char x = trans(i), y = trans(j), z = trans(k);
				ans += sqr(hex2long(string(2, x)) - hex2long(t.substr(1, 2)));
				ans += sqr(hex2long(string(2, y)) - hex2long(t.substr(3, 2)));
				ans += sqr(hex2long(string(2, z)) - hex2long(t.substr(5, 2)));
				string tmp = "#"; tmp += x; tmp += y; tmp += z;
				if (ans < minn) { minn = ans; res = tmp; }
			}
		}
	}
	cout << res << endl;
	return 0;
}