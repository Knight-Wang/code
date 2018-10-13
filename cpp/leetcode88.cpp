class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> v;
        int i = 0, j = 0;
        while (i < m && j < n)
        {
            if (nums1[i] < nums2[j]) v.push_back(nums1[i++]);
            else v.push_back(nums2[j++]);
        }
        while (i < m) v.push_back(nums1[i++]);
        while (j < n) v.push_back(nums2[j++]);
        for (int i = 0; i < v.size(); i++)
            nums1[i] = v[i];
    }
};
