#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
const int INF = 0x3f3f3f3f;

int main()
{
	int n, m, t;
	set<int> p, q;
	cin >> n >> m;
	for (int i = 0; i < n; i++) { cin >> t; p.insert(t); }
	for (int i = 0; i < m; i++) { cin >> t; q.insert(t); }
	for (int i = 0; i <= 9; i++)
	{
		if (p.count(i) && q.count(i))
		{
			cout << i << endl; 
			return 0;
		}
	}
	int x = *p.begin(), y = *q.begin();
	int a = min(x, y), b= max(x, y);
	if (!a) cout << b << a << endl;
	else cout << a << b << endl;
	return 0;
}