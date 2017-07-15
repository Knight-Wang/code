#include <iostream>
using namespace std;
const int mod = 1e9 + 7;
int main()
{
	string s;
	cin >> s;
	int n = s.length();
	int cnt = 1;
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		if (s[i] == 'a') cnt = cnt * 2 % mod;
		else sum = (sum + cnt - 1) % mod;
	}
	cout << sum << endl;
	return 0;
}