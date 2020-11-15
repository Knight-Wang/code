class Solution
{
public:
    int findLatestStep(vector<int>& arr, int m)
    {
        int n = arr.size();
        vector<int> link(n + 2, -1);
        int cnt = 0, res = -1;
        for (int i = 0; i < n; i++)
        {
            int x = arr[i], l = x - 1, r = x + 1;
            int L = x, R = x;
            if (link[l] != -1) L = link[l];
            if (link[r] != -1) R = link[r];
            if (l - L + 1 == m) cnt--;
            if (R - r + 1 == m) cnt--;
            if (R - L + 1 == m) cnt++;
            link[L] = R; link[R] = L;
            if (cnt > 0) res = i + 1;
        }
        return res;
    }
};