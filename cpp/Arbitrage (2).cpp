#include <iostream>
#include <map>
#include <string>
#include <cmath>
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAXN = 35;
double G[MAXN][MAXN];
int n, m;

int main()
{
	map<string, int> mp;
	string s, t;
	double x;
	int Kase = 1;
	while (cin >> n, n)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (i == j) G[i][j] = 0;
				else G[i][j] = INF;
			}
		}
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
		for (int k = 1; k <= n; k++)
		{
			for (int i = 1; i <= n; i++)
			{
				for (int j = 1; j <= n; j++)
				{
					if (G[i][k] + G[k][j] < G[i][j])
						G[i][j] = G[i][k] + G[k][j];
				}
			}
		}
		bool flg = false;
		for (int i = 1; i <= n; i++)
		{
			if (G[i][i] < 0) { flg = true; break; }
		}
		cout << "Case " << Kase++ << ": ";
		if (flg) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	return 0;
}