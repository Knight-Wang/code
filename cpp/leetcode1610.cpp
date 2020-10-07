class Solution
{
public:
    const double PI = acos(-1);
    int visiblePoints(vector<vector<int>>& points, int angle, vector<int>& location)
    {
        int cnt = 0;
        vector<double> v;
        for (auto& it: points)
        {
            if (it[0] == location[0] && it[1] == location[1])
            {
                cnt++; continue;
            }
            double r = atan2(it[1] - location[1], it[0] - location[0]);
            if (r < 0) r += 2 * PI;
            r = r / PI * 180;
            v.push_back(r);
        }
        sort(v.begin(), v.end());
        int n = v.size();
        for (int i = 0; i < n; i++) v.push_back(v[i] + 360);
        int l = 0, r = 0, res = 0;
        while (r < 2 * n)
        {
            while (r < 2 * n && v[r] - v[l] <= angle) r++;
            res = max(res, r - l);
            while (r < 2 * n && l <= r && v[r] - v[l] > angle) l++;
            r++;
        }
        return res + cnt;
    }
};