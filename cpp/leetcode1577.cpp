class Solution
{
public:
    int cal(vector<int>& nums1, vector<int>& nums2)
    {
        int n = nums1.size(), m = nums2.size(), res = 0;
        for (int i = 0; i < n; i++)
        {
            long long target = (long long)nums1[i] * nums1[i];
            int l = 0, r = m - 1;
            while (l <= r)
            {
                long long tmp = (long long)nums2[l] * nums2[r];
                if (tmp > target) r--;
                else if (tmp < target) l++;
                else
                {
                    int L = l;
                    while (L <= r && nums2[L] == nums2[l]) L++;
                    if (L > r)
                    {
                        int len = (r - l + 1);
                        res += len * (len - 1) / 2;
                        break;
                    }
                    int R = r;
                    while (R >= L && nums2[R] == nums2[r]) R--;
                    res += (L - l) * (r - R);
                    l = L; r = R;
                }
            }
        }
        return res;
    }
    int numTriplets(vector<int>& nums1, vector<int>& nums2)
    {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        return cal(nums1, nums2) + cal(nums2, nums1);
    }
};
