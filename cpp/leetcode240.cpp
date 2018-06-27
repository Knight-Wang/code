class Solution 
{
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        int n = (int)matrix.size();
        if (!n) return false;
        int m = matrix[0].size();
        int x = 0, y = m - 1;
        while (x >= 0 && x < n && y >= 0 & y < m)
        {
            if (matrix[x][y] == target) return true;
            else if (matrix[x][y] > target) y--;
            else x++;
        }
        return false;
    }
};