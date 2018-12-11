#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int main()
{
    int n, x, y;
    cin >> n;
	priority_queue<pii, vector<pii>, greater<pii>> q;
	vector<pii> v;
    for (int i = 0; i < n; i++)
	{
		cin >> x >> y;
		v.push_back(pii(x, y));
	}
	sort(v.begin(), v.end());
	int room = 1;
	q.push(pii(0, 1));
	for (int i = 0; i < (int)v.size(); i++)
	{
		if (v[i].first >= q.top().first)
		{
			pii tmp = q.top(); q.pop();
			tmp.first = v[i].second; q.push(tmp);
		}
		else q.push(pii(v[i].second, ++room));
	}
	cout << room << endl;
    return 0;
}