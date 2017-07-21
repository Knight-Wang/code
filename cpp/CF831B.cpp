#include <iostream>
#include <cstdio>
using namespace std;
bool check(char a)
{
	return ('a' <= a && a <= 'z') || ('A' <= a && a <= 'Z');
}
int main()
{
	string a, b, c;
	cin >> a >> b >> c;
	for (int i = 0; i < c.length(); i++)
	{
		if (!check(c[i])) { cout << c[i]; continue; }
		bool flg = false;
		if ('A' <= c[i] && c[i] <= 'Z') { c[i] -= 'A' - 'a'; flg = true; }
		for (int j = 0; j < a.length(); j++)
		{
			if (a[j] == c[i]) cout << (flg ? char(b[j] + 'A' - 'a') : b[j]);
		}
	}
	return 0;
}