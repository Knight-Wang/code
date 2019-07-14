class Solution
{
public:
    vector<vector<int>> work(vector<int>& a)
    {
        int n = a.size();
        vector<vector<int>> ans;
        if (n == 1)
        {
            vector<int> t(1, a[0]);
            ans.push_back(t);
            return ans;
        }
        for (int i = 0; i < n; i++)
        {
            vector<int> t(a.begin(), a.end());
            t.erase(t.begin() + i);
            vector<vector<int>> x = work(t);
            for (auto it: x)
            {
                vector<int> p(1, a[i]);
                p.insert(p.end(), it.begin(), it.end());
                ans.push_back(p);
            }
        }
        return ans;
    }
    vector<vector<int>> permute(vector<int>& nums)
    {
        return work(nums);
    }
};