#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int MAXN = 100005;
vector<int> tree[MAXN * 4], nums;
int n, m, a[MAXN];

void build(int num, int l, int r)
{
	if (l == r) { tree[num].push_back(a[l]); return; }
	int m = l + r >> 1, lc = num * 2, rc = num * 2 + 1;
	build(lc, l, m);
	build(rc, m + 1, r);
	tree[num].resize(r - l + 1);
	merge(tree[lc].begin(), tree[lc].end(), tree[rc].begin(), tree[rc].end(), tree[num].begin());
}

int query(int x, int y, int d, int num, int l, int r)
{
	if (y < l || x > r) return 0;
	if (x <= l && y >= r) return upper_bound(tree[num].begin(), tree[num].end(), d) - tree[num].begin();
	int m = l + r >> 1, ans = 0;
	if (x <= m) ans += query(x, y, d, num * 2, l, m);
	if (y >= m + 1) ans += query(x, y, d, num * 2 + 1, m + 1, r);
	return ans;
}

bool check(int x, int y, int d, int k)
{
	int ans = query(x, y, nums[d], 1, 1, n);
	return ans >= k;
}

int main()
{
	scanf("%d %d", &n, &m);
	nums.push_back(0);
	for (int i = 1; i <= n; i++) 
	{
		scanf("%d", &a[i]);
		nums.push_back(a[i]);
	}
	sort(nums.begin() + 1, nums.end());
	build(1, 1, n);	
	int x, y, k, ans = -1;
	for (int i = 0; i < m; i++)
	{
		scanf("%d %d %d", &x, &y, &k);
		int l = 1, r = n;
		while (l <= r)
		{
			int m = l + r >> 1;
			if (check(x, y, m, k)) r = m - 1, ans = m;
			else l = m + 1;
		}
		printf("%d\n", nums[ans]);
	}
	return 0;
}
