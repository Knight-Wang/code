class Solution 
{
public:
    vector<int> buf;
    void dfs(int cur, int n, vector<int>& nums, vector<vector<int>>& ans)
    {
        if (cur == n) { ans.push_back(buf); return; }
        buf.push_back(nums[cur]);
        dfs(cur + 1, n, nums, ans);
        buf.pop_back();
        dfs(cur + 1, n, nums, ans);
    }
    vector<vector<int>> subsets(vector<int>& nums) 
    {
        vector<vector<int>> ans;
        int n = nums.size();
        dfs(0, n, nums, ans);
        return ans;
    }
};