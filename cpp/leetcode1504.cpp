class Solution
{
public:
    int numSubmat(vector<vector<int>>& mat)
    {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> a(n, vector<int>(m));
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (mat[i][j] == 0) { a[i][j] = 0; continue; }
                else if (j == 0) a[i][j] = 1;
                else a[i][j] = a[i][j - 1] + 1;
                int minn = max(n, m) + 1;
                for (int k = i; k >= 0; k--)
                {
                    if (mat[k][j] == 0) break;
                    minn = min(minn, a[k][j]);
                    res += minn;
                }
            }
        }
        return res;
    }
};