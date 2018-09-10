class Solution 
{
public:
    void rotate(vector<int>& nums, int k) 
    {
        int n = (int)nums.size();
        int K = k % n;
        reverse(nums, 0, n - K - 1);
        reverse(nums, n - K, n - 1);
        reverse(nums, 0, n - 1);
    }
    void reverse(vector<int>& nums, int l, int r)
    {
        while (l < r)
        {
            swap(nums[l], nums[r]);
            l++; r--;
        }
    }
};