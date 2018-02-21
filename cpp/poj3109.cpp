#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int MAXN = 100005;
int x[MAXN], y[MAXN], bit[MAXN], cnt[MAXN], now[MAXN], n;
bool vis[MAXN];
vector<int> lines[MAXN];
int lowbit(int x) { return x & -x; }
void add(int i, int x)
{
	while (i <= MAXN) { bit[i] += x; i += lowbit(i); }
}
int sum(int i)
{
	int ans = 0;
	while (i) { ans += bit[i]; i -= lowbit(i); }
	return ans;
}
int compress(int * a)
{
	vector<int> v(a, a + n);
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	for (int i = 0; i < n; i++) a[i] = lower_bound(v.begin(), v.end(), a[i]) - v.begin() + 1;
	return v.size();
}
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d %d", x + i, y + i);
	int X = compress(x), Y = compress(y);
	for (int i = 0; i < n; i++) { lines[x[i]].push_back(y[i]); cnt[y[i]]++; }
	int ans = 0;
	for (int i = 1; i <= X; i++)
	{
		sort(lines[i].begin(), lines[i].end());
		for (int j = 0; j < lines[i].size() - 1; j++) ans += sum(lines[i][j + 1] - 1) - sum(lines[i][j]);
		for (int j = 0; j < lines[i].size(); j++)
		{
			int tmp = lines[i][j];
			if (!vis[tmp]) { vis[tmp] = true; add(tmp, 1); }
			now[tmp]++;
			if (now[tmp] == cnt[tmp]) add(tmp, -1); 
		}
	} 
	printf("%d\n", ans + n);
	return 0;
}