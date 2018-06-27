class Solution 
{
public:
    void moveZeroes(vector<int>& nums) 
    {
        int n = nums.size(), zero = 0, non_zero = 0;
        while (zero < n && non_zero < n)
        {
            while (zero < n && nums[zero] != 0) zero++;
            if (zero == n) break;
            non_zero = max(zero + 1, non_zero + 1);
            while (non_zero < n && nums[non_zero] == 0) non_zero++;
            if (non_zero == n) break;
            swap(nums[zero], nums[non_zero]);
            zero++;
        }
    }
};