#include <iostream>
#include <cstring>
using namespace std;
int p[2000005];
string init(string s)
{
	string res = "$#";
	for (int i = 0; i < s.length(); i++)
	{
		res += s[i]; res += '#';
	}
	return res;
}
int main()
{
	int n;
	cin >> n;
	string s;
	while (n--)
	{
		cin >> s;
		memset(p, 0, sizeof p);
		s = init(s);
		int r = 0, id = 0, maxn = 0;
		for (int i = 1; i < s.length(); i++)
		{
			if (i < r) p[i] = min(r - i, p[2 * id - i]);
			else p[i] = 1;
			int j = p[i];
			while (s[i + j] == s[i - j]) { j++; p[i]++; }
			if (i + p[i] - 1 > r) { r = i + p[i] - 1; id = i; }
			maxn = max(maxn, p[i] - 1);
		}
		cout << maxn << endl;
	}
	return 0;
}