class Solution 
{
public:
    vector<vector<int>> generate(int numRows) 
    {
        vector<vector<int>> ans;
        if (!numRows) return ans;
        vector<int> v(1, 1);
        ans.push_back(v);
        for (int i = 1; i < numRows; i++)
        {
            vector<int> v(i + 1, 1);
            for (int j = 1; j < v.size() - 1; j++)
            {
                v[j] = ans[i - 1][j - 1] + ans[i - 1][j];
            }
            ans.push_back(v);
        }
        return ans;
    }
};