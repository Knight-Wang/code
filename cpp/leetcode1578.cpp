class Solution
{
public:
    int minCost(string s, vector<int>& cost)
    {
        int n = s.length(), sum = 0;
        for (int i = 0; i < n; i++)
        {
            int j = i + 1;
            while (j < n && s[j] == s[i]) j++;
            int maxn = 0, pos = -1;;
            for (int k = i; k <= j - 1; k++)
            {
                if (cost[k] > maxn) { maxn = cost[k]; pos = k; }
            }
            for (int k = i; k <= j - 1; k++)
            {
                if (k != pos) sum += cost[k];
            }
            i = j - 1;
        }
        return sum;
    }
};