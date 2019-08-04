class Solution
{
public:
    int minimumTotal(vector<vector<int>>& triangle)
    {
        int n = triangle.size();
        vector<int> v(n, 0);
        v[0] = triangle[0][0];
        for (int i = 1; i < n; i++)
        {
            int t1 = v[0] + triangle[i][0], t2 = 0;
            for (int j = 1; j < i + 1; j++)
            {
                if (j == i) t2 = v[j - 1] + triangle[i][j];
                else t2 = triangle[i][j] + min(v[j - 1], v[j]);
                v[j - 1] = t1;
                t1 = t2;
            }
            v[i] = t1;
        }
        return *min_element(v.begin(), v.end());
    }
};