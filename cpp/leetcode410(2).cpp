#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool check(vector<int>& v, long long x, int m)
    {
        long long cur = 0;
        int cnt = 1;
        for (int i = 0; i < v.size(); i++)
        {
            if (cur + v[i] <= x)
            {
                cur += v[i];
            }
            else { cur = v[i]; cnt++; }
        }
        return cnt <= m;
    }
    int splitArray(vector<int>& nums, int m)
    {
        long long l = *max_element(nums.begin(), nums.end());
        long long r = accumulate(nums.begin(), nums.end(), 0ll);
        long long ans = r;
        while (l <= r)
        {
            long long mi = l + r >> 1;
            if (check(nums, mi, m))
            {
                ans = mi; r = mi - 1;
            }
            else l = mi + 1;
        }
        return (int)ans;
    }
};

int main()
{
    int a[] = {7, 2, 5, 10, 8};
    vector<int> v(a, a + 5);
    cout << Solution().splitArray(v, 2) << endl;
    return 0;
}