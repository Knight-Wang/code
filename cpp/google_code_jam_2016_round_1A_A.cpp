#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
int main()
{
	string s;
	int T;
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		cin >> s;
		int n = s.length();
		string res = "";
		res += s[0];
		for (int i = 1; i < n; i++)
		{
			if (s[i] >= res[0])
			{
				res = s[i] + res;
			}
			else
			{
				res += s[i];
			}
		}
		cout << "Case #" << t + 1 << ": ";
		cout << res << endl;
	}
	return 0;
}