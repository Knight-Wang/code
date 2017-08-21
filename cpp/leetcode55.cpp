class Solution 
{
public:
    bool canJump(vector<int>& nums) 
    {
        int i = 0, maxn = 0, n = nums.size();
        while (i < n && i <= maxn)
        {
            maxn = max(maxn, i + nums[i]); i++;
        }
        return i == n;
    }
};