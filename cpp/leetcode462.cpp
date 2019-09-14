class Solution
{
public:
    int minMoves2(vector<int>& nums)
    {
        if (nums.empty()) return 0;
        sort(nums.begin(), nums.end());
        int n = nums.size(); long long res = 0;
        for (int i = 0; i < n; i++)
        {
            res += abs(nums[i] - nums[n/2]);
        }
        return res;
    }
};