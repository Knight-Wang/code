class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k)
    {
        int n = nums.size();
        deque<int> q;
        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            while (!q.empty() && nums[i] >= nums[q.back()]) q.pop_back();
            q.push_back(i);
            while (!q.empty() && q.front() < i - k + 1) q.pop_front(); 
            if (i >= k - 1) ans.push_back(nums[q.front()]);
        }
        return ans;
    }
};