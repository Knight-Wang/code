class Solution 
{
public:
    bool checkSubarraySum(vector<int>& nums, int k) 
    {
        if (nums.size() < 2) return false;
        int n = nums.size();
        for (int i = 0; i < n - 1; i++)
            if (nums[i] == 0 && nums[i + 1] == 0)
                return true;
        if (k == 0) return false;
        int sum = 0;
        unordered_map<int, int> m;
        m[0] = -1;
        for (int i = 0; i < n; i++)
        {
            sum = (sum + nums[i]) % k;
            if (m.count(sum))
            {
                if (i - m[sum] > 1)
                    return true;
            }
            else m[sum] = i;
        }
        return false;
    }
};