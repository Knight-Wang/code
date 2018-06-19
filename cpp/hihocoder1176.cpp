#include <bits/stdc++.h>
using namespace std;
const int MAXN = 10005;
int in[MAXN];
int main()
{
	int n, m, a, b;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;
		in[a]++; in[b]++;
	}
	int cnt = 0;
	for (int i = 1; i <= n; i++)
		if (in[i] & 1) cnt++;
	cout << (cnt <= 2 ? "Full" : "Part") << endl;
	return 0;
}