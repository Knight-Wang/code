#include <bits/stdc++.h>
using namespace std;
const int MAXN = 105;
int a[MAXN], b[MAXN], cnt;
bool check()
{
	int ans = 0;
	for (int i = 0; i < cnt - 1; i += 2) ans ^= b[i];
	return ans == 0;
}
int main()
{
	string s;
	getline(cin, s);
	stringstream ss(s);
	while (ss >> a[cnt]) cnt++;
	for (int i = 0; i < cnt - 1; i++) b[i] = a[i + 1] - a[i] - 1;
	if (check()) { cout << -1 << endl; return 0; }
	for (int i = 0; i < cnt - 1; i++)
	{
		for (int j = 1; j < a[i + 1] - a[i]; j++)
		{
			if (i & 1) b[i - 1] += j;
			else b[i] -= j;
			if (check()) { cout << a[i] << " " << a[i] + j << endl; return 0; }
			if (i & 1) b[i - 1] -= j;
			else b[i] += j;
		}
	}
	return 0;
}