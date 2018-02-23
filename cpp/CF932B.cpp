#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> num[9];
int res[1000005];

int cal(int x)
{
	if (res[x] != -1) return res[x];
	if (x < 10) return x;
	int ans = 1;
	while (x) { ans *= x % 10 ? x % 10 : 1; x /= 10; }
	return res[x] = cal(ans);
}

int main()
{
	memset(res, -1, sizeof res);
	for (int i = 1; i <= 1000000; i++) num[cal(i) - 1].push_back(i);
	int q, x, y, k;
	cin >> q;
	while (q--)
	{
		cin >> x >> y >> k;
		k--;
		cout << upper_bound(num[k].begin(), num[k].end(), y) - lower_bound(num[k].begin(), num[k].end(), x) << endl;
	}
	return 0;
}