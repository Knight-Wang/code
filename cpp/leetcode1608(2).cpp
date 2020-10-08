class Solution
{
public:
    int specialArray(vector<int>& nums)
    {
        int n = nums.size();
        vector<int> v(n + 1, 0);
        for (int i = 0; i < n; i++)
        {
            if (nums[i] > n) v[n]++;
            else v[nums[i]]++;
        }
        for (int i = n; i >= 0; i--)
        {
            if (i < n) v[i] += v[i + 1];
            if (v[i] == i) return i;
        }
        return -1;
    }
};
