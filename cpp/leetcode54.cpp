class Solution 
{
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) 
    {
        vector<int> ret;
        if (!matrix.size()) return ret;
        int m = matrix.size(), n = matrix[0].size(), p = 0, q = 1;
        int x = 0, y = 0;
        while (true)
        {
            if (y >= n) break;
            while (y < n) { ret.push_back(matrix[x][y++]); }
            y--; x++;
            if (x >= m) break;
            while (x < m) { ret.push_back(matrix[x++][y]); }
            x--; y--;
            if (y < p) break;
            while (y >= p) { ret.push_back(matrix[x][y--]); }
            y++; x--;
            if (x < q) break;
            while (x >= q) { ret.push_back(matrix[x--][y]); }
            x++; y++;
            n--; m--; p++; q++;
        }
        return ret;
    }
};