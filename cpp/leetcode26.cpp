class Solution
{
public:
    int removeDuplicates(vector<int>& nums)
    {
        if (nums.empty()) return 0;
        int n = nums.size();
        int i = 1, cur = 1;
        while (i < n)
        {
            while (i < n && nums[i] == nums[i - 1]) i++;
            if (i < n) { nums[cur] = nums[i]; i++; cur++; }
        }
        return cur;
    }
};