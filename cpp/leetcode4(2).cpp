class Solution
{
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
    {
        int n = nums1.size(), m = nums2.size();
        if (n > m) return findMedianSortedArrays(nums2, nums1);
        int l = 0, r = 2 * n;
        long long l1, l2, r1, r2;
        while (l <= r)
        {
            int c1 = l + r >> 1, c2 = m + n - c1;
            l1 = c1 == 0 ? INT_MIN : nums1[c1 - 1 >> 1];
            r1 = c1 == 2 * n ? INT_MAX : nums1[c1 >> 1];
            l2 = c2 == 0 ? INT_MIN : nums2[c2 - 1 >> 1];
            r2 = c2 == 2 * m ? INT_MAX : nums2[c2 >> 1];
            if (l1 > r2) r = c1 - 1;
            else if (l2 > r1) l = c1 + 1;
            else break;
        }
        long long res = max(l1, l2) + min(r1, r2);
        return (double)res / 2.0;
    }
};