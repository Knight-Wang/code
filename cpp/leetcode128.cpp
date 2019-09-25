class Solution
{
public:
    int longestConsecutive(vector<int>& nums)
    {
        unordered_map<int, int> mp;
        for (auto it: nums)
        {
            if (mp.count(it)) continue;
            int l = it, r = it;
            if (mp.count(it - 1)) 
            {
                if (mp[it - 1] <= it - 1) l = mp[it - 1];
                else { r = mp[it - 1]; l = it - 1; }
            }
            if (mp.count(it + 1))
            {
                if (mp[it + 1] >= it + 1) r = max(r, mp[it + 1]);
                else { l = min(l, mp[it + 1]); r = max(r, it + 1); }
            }
            if (l == r) mp[it] = r;
            else
            {
                if (mp.count(it - 1)) { mp.erase(mp[it - 1]); mp.erase(it - 1); }
                if (mp.count(it + 1)) { mp.erase(mp[it + 1]); mp.erase(it + 1); }
                mp[l] = r; mp[r] = l;
            }
        }
        int res = 0;
        for (auto it: mp) res = max(res, abs(it.first - it.second + 1));
        return res;
    }
};