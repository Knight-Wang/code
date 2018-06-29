class Solution 
{
public:
    int majorityElement(vector<int>& nums) 
    {
        int nown = 1, nowi = nums[0], n = nums.size();
        for (int i = 1; i < n; i++)
        {
            if (nums[i] == nowi) nown++;
            else if (nown == 1) nowi = nums[i];
            else nown--;
        }
        return nowi;
    }
};