class Solution
{
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker)
    {
        vector<pair<int, int>> a;
        int n = difficulty.size(), m = worker.size();
        for (int i = 0; i < n; i++) a.push_back(make_pair(profit[i], difficulty[i]));
        sort(a.begin(), a.end());
        vector<int> b(worker.begin(), worker.end());
        sort(b.begin(), b.end());
        int i = n - 1, j = m - 1, ans = 0;
        while (i >= 0 && j >= 0)
        {
            while (i >= 0 && a[i].second > b[j]) i--;
            if (i < 0) break;
            ans += a[i].first;
            j--;
        }
        return ans;
    }
};