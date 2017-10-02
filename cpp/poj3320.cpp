#include <cstdio>
#include <iostream>
#include <map>
using namespace std;
const int INF = 0x3f3f3f3f;
int a[1000005];
map<int, int> mp;
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) { scanf("%d", &a[i]); mp[a[i]]++; }
	int i = 0, j = 0, ans = INF, tot = mp.size();
	mp.clear();
	while (true)
	{
		while (j < n && (int)mp.size() < tot) { mp[a[j]]++; j++; }
		if (j == n && i == j) break;
		if ((int)mp.size() == tot) ans = min(ans, j - i);
		mp[a[i]]--; if (!mp[a[i]]) mp.erase(a[i]);
		i++;
	}
	cout << ans << endl;
	return 0;
}