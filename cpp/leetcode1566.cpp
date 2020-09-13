class Solution
{
public:
    bool containsPattern(vector<int>& arr, int m, int k)
    {
        int n = arr.size();
        for (int i = 0; i + k * m <= n; i++)
        {
            bool ok = true;
            for (int r = 0; r < m; r++)
            {
                if (!ok) break;
                for (int j = i + r + m; j < i + k * m; j += m)
                {
                    if (arr[j] != arr[j - m]) { ok = false; break; }
                }
            }
            if (ok) return true;
        }
        return false;
    }
};