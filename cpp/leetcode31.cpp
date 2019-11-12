class Solution
{
public:
    void nextPermutation(vector<int>& nums)
    {
        int n = nums.size(); bool flg = false;
        for (int i = n - 2; i >= 0; i--)
        {
            if (nums[i] < nums[i + 1])
            {
                sort(nums.begin() + i + 1, nums.end());
                int p = upper_bound(nums.begin() + i + 1, nums.end(), nums[i]) - nums.begin();
                swap(nums[i], nums[p]);
                flg = true; break;
            }
        }
        if (!flg) sort(nums.begin(), nums.end());
    }
};