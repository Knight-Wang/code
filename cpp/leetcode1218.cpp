class Solution
{
public:
    int longestSubsequence(vector<int>& arr, int difference)
    {
        unordered_map<int, int> mp;
        for (auto it: arr)
        {
            int ans = 1;
            if (mp.count(it - difference)) ans = mp[it - difference] + 1;
            if (!mp.count(it)) mp[it] = ans;
            else mp[it] = max(mp[it], ans);
        }
        int maxn = 0;
        for (auto it: mp) maxn = max(maxn, it.second);
        return maxn;
    }
};