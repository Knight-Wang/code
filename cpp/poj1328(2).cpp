#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
const int MAXN = 1005;
pair<double, double> p[MAXN];
int square(int x)
{
	return x * x;
}
bool comp(const pair<double, double> & a, const pair<double, double> & b)
{
	if (a.second != b.second) return a.second < b.second;
	return a.first < b.first; 
}
int main()
{
	int n, d, Kase = 1;
	while (cin >> n >> d, n || d)
	{
		bool flg = true;
		for (int i = 0; i < n; i++)
		{
			cin >> p[i].first >> p[i].second;
			if (p[i].second > d) flg = false;
			double tmp = sqrt(square(d) - square(p[i].second));
			double l = p[i].first - tmp, r = p[i].first + tmp;
			p[i].first = l; p[i].second = r;
		}
		if (!flg) { cout << "Case " << Kase++ << ": -1" << endl; continue; }
		sort(p, p + n, comp);
		int ans = 1, i = 1;
		double now = p[0].second;
		while (i < n)
		{
			if (p[i].first > now) { ans++; now = p[i].second; }
			i++;
		}
		cout << "Case " << Kase++ << ": " << ans << endl;
	}	
	return 0;
}