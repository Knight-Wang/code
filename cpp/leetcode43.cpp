class Solution 
{
public:
    string multiply(string num1, string num2) 
    {
        int m = num1.length(), n = num2.length();
        int ans[m + n];
        for (int i = 0; i < m + n; i++) ans[i] = 0;
        for (int i = m - 1; i >= 0; i--)
        {
            for (int j = n - 1; j >= 0; j--)
            {
                int x = i + j;
                int tmp = (num1[i] - '0') * (num2[j] - '0') + ans[x + 1];
                ans[x + 1] = tmp % 10;
                ans[x] += tmp / 10;
            }
        }
        string ret = "";
        int i = 0;
        while (i < m + n && ans[i] == 0) i++;
        if (i == m + n) return "0";
        for (int j = i; j < m + n; j++) ret += to_string(ans[j]);
        return ret;
    }
};