#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
const int MAXN = 100005;
const int B = 1000;
int n, m, a[MAXN], nums[MAXN];
vector<int> v[MAXN / B];
bool check(int x, int l, int r, int k)
{
	int ans = 0;
	while (l < r && l % B) if (a[l++] <= nums[x]) ans++;
	while (r > l && r % B) if (a[--r] <= nums[x]) ans++;
	for (int i = l / B; i < r / B; i++)
	{
		ans += upper_bound(v[i].begin(), v[i].end(), nums[x]) - v[i].begin();
	}
	return ans >= k; 
}
int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) 
	{
		scanf("%d", &a[i]);
		nums[i] = a[i];
		v[i / B].push_back(a[i]);
	}
	for (int i = 0; i <= n / B; i++) sort(v[i].begin(), v[i].end());
	sort(nums, nums + n);
	int x, y, k;
	for (int i = 0; i < m; i++)
	{
		scanf("%d %d %d", &x, &y, &k);
		x--;
		int l = 0, r = n - 1, ans = -1;
		while (l <= r)
		{
			int m = l + r >> 1;
			if (check(m, x, y, k)) { r = m - 1; ans = m; }
			else l = m + 1;
		}
		printf("%d\n", nums[ans]);
	}
	return 0;
}
