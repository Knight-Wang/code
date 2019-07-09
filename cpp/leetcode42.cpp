class Solution
{
public:
    int trap(vector<int>& height)
    {
        if (height.empty()) return 0;
        int n = height.size();
        vector<int> l(n, 0), r(n, 0), sl(n, 0), sr(n, 0);
        l[0] = sl[0] = height[0]; r[n - 1] = sr[n - 1] = height[n - 1];
        for (int i = 1; i < n; i++) { l[i] = max(l[i - 1], height[i]); sl[i] = sl[i - 1] + height[i]; }
        for (int i = n - 2; i >= 0; i--) { r[i] = max(r[i + 1], height[i]); sr[i] = sr[i + 1] + height[i]; }
        int max_id = max_element(height.begin(), height.end()) - height.begin(), id = max_id, ans = 0;
        for (int i = id - 1; i >= 0; i--)
        {
            if (l[i] == height[i])
            {
                if (id - i > 1) ans += height[i] * (id - i - 1) - (sl[id - 1] - sl[i]);
                id = i;
            }
        }
        id = max_id;
        for (int i = id + 1; i < n; i++)
        {
            if (r[i] == height[i])
            {
                if (i - id > 1) ans += height[i] * (i - id - 1) - (sr[id + 1] - sr[i]);
                id = i;
            }
        }
        return ans;
    }
};
