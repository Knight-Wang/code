#include <iostream>
#include <map>
#include <string>
#include <cmath>
#include <queue>
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAXN = 35;
double G[MAXN][MAXN], d[MAXN];
bool in[MAXN];
int n, m, num[MAXN];
bool spfa(int s)
{
	queue<int> q;
	d[s] = 0;
	q.push(s);
	in[s] = true;
	while (!q.empty())
	{
		int tmp = q.front(); q.pop();
		in[tmp] = false;
		for (int i = 0; i <= n; i++)
		{
			if (d[tmp] + G[tmp][i] < d[i])
			{
				d[i] = d[tmp] + G[tmp][i];
				if (!in[i]) { in[i] = true; q.push(i); }
				num[i]++;
				if (num[i] > n) return true;
			}
		}
	}
	return false;
}
int main()
{
	map<string, int> mp;
	string s, t;
	double x;
	int Kase = 1;
	while (cin >> n, n)
	{
		for (int i = 0; i <= n; i++)
		{
			for (int j = 0; j <= n; j++)
			{
				G[i][j] = INF;
			}
		}
		fill(d, d + n + 1, INF);
		fill(in, in + n + 1, 0);
		fill(num, num + n + 1, 0);
		mp.clear();
		for (int i = 1; i <= n; i++)
		{
			cin >> s;
			mp[s] = i;
		}
		cin >> m;
		for (int i = 1; i <= m; i++)
		{
			cin >> s >> x >> t;
			G[mp[s]][mp[t]] = -log(x);
		}
		for (int i = 1; i <= n; i++) G[0][i] = 0;
		cout << "Case " << Kase++ << ": ";
		if (spfa(0)) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	return 0;
}