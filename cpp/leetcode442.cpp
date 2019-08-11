class Solution
{
public:
    vector<int> findDuplicates(vector<int>& nums)
    {
        int n = nums.size();
        vector<int> res;
        for (int i = 0; i < n; i++)
        {
            int x = abs(nums[i]) - 1;
            if (nums[x] < 0) res.push_back(abs(nums[i]));
            else nums[x] *= -1;
        }
        return res;
    }
};