class Solution
{
public:
    vector<vector<int>> threeSum(vector<int>& nums)
    {
        vector<int> a(nums.begin(), nums.end());
        sort(a.begin(), a.end());
        vector<vector<int>> ans;
        int n = a.size();
        for (int i = 0; i < n; i++)
        {
            if (i >= 1 && a[i] == a[i - 1]) continue;
            int l = i + 1, r = n - 1;
            while (l < r)
            {
                if (a[i] + a[l] + a[r] < 0) l++;
                else if (a[i] + a[l] + a[r] > 0) r--;
                else
                {
                    vector<int> t;
                    t.push_back(a[i]);
                    t.push_back(a[l]);
                    t.push_back(a[r]);
                    ans.push_back(t);
                    l++; r--;
                    while (l < r && a[l] == a[l - 1] && a[r] == a[r + 1])
                    {
                        l++; r--;
                    }
                }
            }
        }
        return ans;
    }
};