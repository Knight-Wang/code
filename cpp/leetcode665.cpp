class Solution
{
public:
    bool checkPossibility(vector<int>& nums)
    {
        int n = nums.size();
        if (n <= 2) return true;
        int cnt = 0;
        vector<int> a(nums.begin(), nums.end());
        for (int i = 0; i <= n - 2; i++)
        {
            if (a[i + 1] < a[i])
            {
                if (cnt) return false;
                if (i >= 1 && a[i - 1] > a[i + 1]) a[i + 1] = a[i];
                else a[i] = a[i + 1];
                cnt++;
            }
        }
        return true;
    }
};