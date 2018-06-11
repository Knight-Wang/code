#include <bits/stdc++.h>
using namespace std;
class Solution 
{
public:
	int sum(vector<int> & bit, int i)
	{
		int ans = 0;
		while (i) { ans += bit[i]; i -= i & -i; }
		return ans;
	}
	void add(vector<int> & bit, int i, int x)
	{
		int n = bit.size() - 1;
		while (i <= n) { bit[i] += x; i += i & -i; }
	}
    vector<int> countSmaller(vector<int>& nums) 
    {
		int n = nums.size();
		vector<int> a(nums.begin(), nums.end()), b(nums.begin(), nums.end());
		sort(a.begin(), a.end());
		a.erase(unique(a.begin(), a.end()), a.end());
		for (int i = 0; i < n; i++)
			b[i] = lower_bound(a.begin(), a.end(), b[i]) - a.begin() + 1;
		vector<int> bit(n + 1, 0), ans(n, 0);
		for (int i = n - 1; i >= 0; i--)
		{
			add(bit, b[i], 1);
			ans[i] = b[i] == 1 ? 0 : sum(bit, b[i] - 1);
		}
		return ans;
    }
};
int main()
{
	vector<int> v;
	v.push_back(5);
	v.push_back(-1);
	v.push_back(6);
	v.push_back(1);
	vector<int> ans = Solution().countSmaller(v);
	for (auto it: ans) cout << it << " ";
	cout << endl;
	return 0;
}