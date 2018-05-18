#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200005;
pair<int, int> w[MAXN];
int n;
string s;
int main()
{
	while (cin >> n)
	{
		for (int i = 0; i < n; i++) { cin >> w[i].first; w[i].second = i + 1; }
		sort(w, w + n);
		cin >> s;
		stack<int> sta;
		int now = 0;
		for (int i = 0; i < 2 * n; i++)
		{
			if (s[i] == '0') { cout << w[now].second << " "; sta.push(w[now].second); now++; }
			else { cout << sta.top() << " "; sta.pop(); }
		}
		cout << endl;
	}
	return 0;
}