class Solution 
{
public:
    vector<int> constructArray(int n, int k) 
    {
        vector<int> ret(n, 1);
        for (int i = 1; i < n - k; i++) ret[i] = ret[i - 1] + 1;
        int now = k, sign = 1;
        for (int i = n - k; i < n; i++)
        {
            ret[i] = ret[i - 1] + sign * now;
            now--;
            sign *= -1;
        }
        return ret;
    }
};