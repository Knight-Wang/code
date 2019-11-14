class Solution
{
public:
    int maximumSum(vector<int>& arr)
    {
        int n = arr.size();
        if (n == 1) return arr[0];
        vector<int> f(n), b(n);
        int minn = 0, sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += arr[i];
            f[i] = sum - minn;
            minn = min(minn, sum);
        }
        minn = sum = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            sum += arr[i];
            b[i] = sum - minn;
            minn = min(minn, sum);
        }
        int ans = *max_element(f.begin(), f.end());
        for (int i = 0; i < n; i++)
        {
            if (arr[i] > 0) continue;
            ans = max(ans, (i > 0 ? f[i - 1] : 0) + (i < n - 1 ? b[i + 1] : 0));
        }
        return ans;
    }
};