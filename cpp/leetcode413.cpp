class Solution 
{
public:
    int numberOfArithmeticSlices(vector<int>& A) 
    {
        int n = A.size(), last = 0, pos = 0, sum = 0;
        for (int i = 0; i < n - 1; i++)
        {
            int d = A[i + 1] - A[i];
            if (i != 0 && d != last)
            {
                sum += (i - pos >= 2 ? (i - pos) * (i - pos - 1) / 2 : 0);
                pos = i;
            }
            last = d;
        }
        sum += (n - 1 - pos >= 2 ? (n - 1 - pos) * (n - 2 - pos) / 2 : 0);
        return sum;
    }
};