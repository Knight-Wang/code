class Solution 
{
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) 
    {
        vector<int> tmp(nums.begin(), nums.end());
        sort(tmp.begin(), tmp.end());
        
        set<vector<int>> s;
        int n = tmp.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                for (int k = j + 1; k < n; k++)
                {
                    if (binary_search(tmp.begin() + k + 1, tmp.begin() + n, target  - tmp[i] - tmp[j] - tmp[k]))
                    {
                        vector<int> t;
                        t.push_back(tmp[i]);
                        t.push_back(tmp[j]);
                        t.push_back(tmp[k]);
                        t.push_back(target - tmp[i] - tmp[j] - tmp[k]);
                        s.insert(t);
                    }
                }
            }
        }
        vector<vector<int>> ans;
        for (auto it : s)
            ans.push_back(it);
        return ans;
    }
};