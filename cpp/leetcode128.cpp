class Solution
{
public:
    int longestConsecutive(vector<int>& nums) 
    {
        unordered_map<int, int> mp;
        int ans = 0;
        for (auto it: nums)
        {
            if (mp.count(it)) continue;
            int l = mp.count(it - 1) ? mp[it - 1] : 0;
            int r = mp.count(it + 1) ? mp[it + 1] : 0;
            int sum = l + r + 1;
            ans = max(ans, sum);
            mp[it] = sum;
            mp[it - l] = sum;
            mp[it + r] = sum;
        }
        return ans;
    }
};