class Solution
{
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int K)
    {
        if (mat.empty()) return vector<vector<int>>();
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> sum(n, vector<int>(m, 0)), res(n, vector<int>(m, 0));
        sum[0][0] = mat[0][0];
        for (int i = 1; i < n; i++) sum[i][0] = sum[i - 1][0] + mat[i][0];
        for (int i = 1; i < m; i++) sum[0][i] = sum[0][i - 1] + mat[0][i];
        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j < m; j++)
            {
                sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + mat[i][j];
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int l = min(i + K, n - 1), r = min(j + K, m - 1);
                int a = sum[l][r];
                int b = i - K - 1 < 0 ? 0 : sum[i - K - 1][r];
                int c = j - K - 1 < 0 ? 0 : sum[l][j - K - 1];
                int d = i - K - 1 < 0 || j - K - 1 < 0 ? 0 : sum[i - K - 1][j - K - 1];
                res[i][j] = a - b - c + d;
            }
        }
        return res;
    }
};