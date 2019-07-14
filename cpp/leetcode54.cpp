class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix)
    {
        if (matrix.empty()) return vector<int>();
        int n = matrix.size() - 1, m = matrix[0].size() - 1, p = 1, q = 0;
        int x = 0, y = 0;
        vector<int> ans;
        while (true)
        {
            if (y > m) break;
            while (y <= m) ans.push_back(matrix[x][y++]);
            x++; y--;
            if (x > n) break;
            while (x <= n) ans.push_back(matrix[x++][y]);
            x--; y--;
            if (y < q) break;
            while (y >= q) ans.push_back(matrix[x][y--]);
            x--; y++;
            if (x < p) break;
            while (x >= p) ans.push_back(matrix[x--][y]);
            x++; y++;
            if (y > m) break;
            p++; q++; n--; m--;
        }
        return ans;
    }
};