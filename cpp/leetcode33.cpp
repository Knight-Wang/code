#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int search(vector<int>& nums, int target)
    {
        int n = nums.size();
        int l = 0, r = n - 1, ans = -1;
        while (l <= r)
        {
            int m = l + r >> 1;
            if (nums[l] > nums[m])
            {
                if (target == nums[m]) { ans = m; break; }
                else if (target > nums[m])
                {
                    if (target > nums[r]) r = m - 1;
                    else l = m + 1;
                }
                else r = m - 1;
            }
            else
            {
                if (target == nums[m]) { ans = m; break; }
                else if (target > nums[m]) l = m + 1;
                else
                {
                    if (target >= nums[l]) r = m - 1;
                    else l = m + 1;
                }
            }
        }
        return ans;
    }
};

int main()
{
    int a[] = {4, 5, 6, 7, 0, 1, 2};
    int n = sizeof(a) / sizeof(int);
    int target = 5;
    vector<int> v(a, a + n);
    cout << Solution().search(v, target) << endl;
    return 0;
}