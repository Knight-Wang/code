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
        int id = max_element(height.begin(), height.end()) - height.begin();
        int maxn = height[id];
        vector<int> lp(1, id), rp(1, id);
        for (int i = id - 1; i >= 0; i--)
        {
            if (l[i] == height[i]) lp.push_back(i);
        }
        for (int i = id + 1; i < n; i++)
        {
            if (r[i] == height[i]) rp.push_back(i);
        }
        int ans = 0;
        for (int i = 1; i < lp.size(); i++)
        {
            if (lp[i - 1] - lp[i] == 1) continue;
            ans += height[lp[i]] * (lp[i - 1] - lp[i] - 1) - (sl[lp[i - 1] - 1] - sl[lp[i]]);
        }
        for (int i = 1; i < rp.size(); i++)
        {
            if (rp[i] - rp[i - 1] == 1) continue;
            ans += height[rp[i]] * (rp[i] - rp[i - 1] - 1) - (sr[rp[i - 1] + 1] - sr[rp[i]]);
        }
        return ans;
    }
};