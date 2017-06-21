class Solution 
{
public:
    int threeSumClosest(vector<int>& nums, int target) 
    {
        vector<int> x(nums);
        sort(x.begin(), x.end());
        int n = x.size();
        int ans = x[0] + x[1] + x[2];
        for (int i = 0; i < n - 2; i++)
        {
            int j = i + 1, k = n - 1;
            while (j < k)
            {
                int sum = x[i] + x[j] + x[k];
                if (abs(target - sum) < abs(target - ans))
                {
                    ans = sum;
                    if (sum == target) return target;
                }
                if (sum < target) j++;
                else k--;
            }
        }
        return ans;
    }
};