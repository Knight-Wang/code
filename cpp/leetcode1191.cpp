class Solution
{
public:
    int kConcatenationMaxSum(vector<int>& arr, int k)
    {
        if (arr.empty()) return 0;
        int n = arr.size();
        vector<int> dp(n, 0);
        int sum = 0, minn = INT_MAX, ans = 0;
        bool flg = false;
        for (int i = 0; i < min(2, k) * n; i++)
        {
            minn = min(minn, sum);
            sum += arr[i % n];
            if (sum - minn > ans)
            {
                ans = sum - minn;
                if (i >= n) flg = true;
            }
        }
        int mod = 1e9 + 7;
        if (!flg) return ans;
        int tmp = accumulate(arr.begin(), arr.end(), 0);
        if (tmp > 0) ans = (ans + (long long)tmp * (k - 2) % mod) % mod;
        return ans;
    }
};