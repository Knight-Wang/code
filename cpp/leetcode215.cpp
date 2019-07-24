class Solution
{
public:
    int work(vector<int>& a, int L, int R, int k)
    {
        int l = L, r = R;
        while (l < r)
        {
            while (l < r && a[l] >= a[r]) r--;
            swap(a[l], a[r]);
            while (l < r && a[l] >= a[r]) l++;
            swap(a[l], a[r]);
        }
        if (l == L + k - 1) return a[l];
        else if (l < L + k - 1) return work(a, l + 1, R, k - (l - L + 1));
        else return work(a, L, l - 1, k);
    }
    int findKthLargest(vector<int>& nums, int k)
    {
        int n = nums.size();
        return work(nums, 0, n - 1, k);
    }
};