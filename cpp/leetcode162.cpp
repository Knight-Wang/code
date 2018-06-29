class Solution 
{
public:
    int findPeakElement(vector<int>& nums) 
    {
		int n = nums.size();
        vector<int> a(n + 2, -INT_MAX-1);
		copy(nums.begin(), nums.end(), a.begin() + 1);
		int l = 1, r = n, ans = -1;
		while (l <= r)
		{
			int m = l + r >> 1;
			if (a[m - 1] <= a[m] && a[m + 1] <= a[m])
			{
				ans = m; break;
			}
			if (a[m - 1] >= a[m] && a[m + 1] <= a[m])
				r = m - 1;
			else
				l = m + 1;
		}
		return ans - 1;
    }
};