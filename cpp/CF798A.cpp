#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	string s;
	cin >> s;
	int n = s.length();
	int cnt = 0;
	for (int i = 0; i < n / 2; i++)
	{
		if (s[i] != s[n - 1 - i]) cnt++;
	}
	if (cnt == 1) puts("YES");
	else if (cnt == 0 && (n & 1)) puts("YES");
	else puts("NO");
	return 0;
}