class Solution
{
public:
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2)
    {
        int n = arr1.size(), m = arr2.size();
        sort(arr2.begin(), arr2.end());
        vector<map<int, int>> v(1);
        v[0][arr1[0]] = 0;
        if (arr2[0] < arr1[0]) v[0][arr2[0]] = 1;
        for (int i = 1; i < n; i++)
        {
            map<int, int> mp;
            for (auto it: v[i - 1])
            {
                if (arr1[i] > it.first)
                {
                    if (!mp.count(arr1[i])) mp[arr1[i]] = INT_MAX;
                    mp[arr1[i]] = min(mp[arr1[i]], it.second);
                }
                int p = upper_bound(arr2.begin(), arr2.end(), it.first) - arr2.begin();
                if (p != m)
                {
                    if (!mp.count(arr2[p])) mp[arr2[p]] = INT_MAX;
                    mp[arr2[p]] = min(mp[arr2[p]], it.second + 1);
                }
            }
            map<int, int> mp2;
            int minn = INT_MAX;
            for (auto it: mp)
            {
                if (it.second >= minn) continue;
                minn = it.second;
                mp2[it.first] = it.second;
            }
            v.push_back(mp2);
        }
        int res = INT_MAX;
        for (auto it: v[n - 1]) res = min(res, it.second);
        return res == INT_MAX ? -1 : res;
    }
};