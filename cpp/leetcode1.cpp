class Solution
{
public:
	/* O(nlog(n)) Solution
    vector<int> twoSum(vector<int>& nums, int target)
    {
        int n = nums.size();
        vector<pair<int, int>> v(n, make_pair(0, 0));
        for (int i = 0; i < n; i++) v[i] = make_pair(nums[i], i);
        sort(v.begin(), v.end());
        vector<int> v2(n, 0);
        for (int i = 0; i < n; i++) v2[i] = v[i].first;
        vector<int> res(2, 0);
        for (int i = 0; i < n; i++)
        {
        	int tmp = target - v2[i];
            if (binary_search(v2.begin() + i + 1, v2.end(), tmp))
            {
                int pos = lower_bound(v2.begin() + i + 1, v2.end(), tmp) - v2.begin();
                res[0] = v[i].second; res[1] = v[pos].second;
                break;
            }
        }
        return res;
    }*/
    // O(n) Solution
    vector<int> twoSum(vector<int>& nums, int target)
    {
        unordered_map<int, int> mp;
        vector<int> res(2, 0);
        for (int i = 0; i < nums.size(); i++)
        {
			int tmp = target - nums[i];
			if (mp.count(tmp)) { res[0] = mp[tmp]; res[1] = i; break; }
			mp[nums[i]] = i;
        }
        return res;
    }
};
