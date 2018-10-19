class Solution 
{
public:
    int findDuplicate(vector<int>& nums)
    {
        int p = nums[0], q = nums[0];
        while (true)
        {
            p = nums[nums[p]];
            q = nums[q];
            if (p == q) break;
        }
        p = nums[0];
        while (true)
        {
            if (p == q) break;
            p = nums[p];
            q = nums[q];
        }
        return p;
    }
};
