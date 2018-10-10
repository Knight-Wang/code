class Solution 
{
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D)
    {
        int n = A.size();
        vector<int> x, y;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                x.push_back(A[i] + B[j]);
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                y.push_back(C[i] + D[j]);
            }
        }
        sort(y.begin(), y.end());
        int ans = 0;
        for (auto it: x)
        {
            if (binary_search(y.begin(), y.end(), -it))
            {
                int l = lower_bound(y.begin(), y.end(), -it) - y.begin();
                int r = upper_bound(y.begin(), y.end(), -it) - y.begin();
                ans += r - l;
            }
        }
        return ans;
    }
};
