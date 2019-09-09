class Solution
{
public:
    int sumSubarrayMins(vector<int>& A)
    {
        int res = 0;
        stack<int> st;
        int n = A.size();
        const int MOD = 1e9 + 7;
        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && A[i] < A[st.top()])
            {
                int tmp = st.top(); st.pop();
                int last = st.empty() ? -1 : st.top();
                res = (res + (i - tmp) * (tmp - last) % MOD * A[tmp] % MOD) % MOD;
            }
            st.push(i);
        }
        while (!st.empty())
        {
            int tmp = st.top(); st.pop();
            int last = st.empty() ? -1 : st.top();
            res = (res + (n - tmp) * (tmp - last) % MOD * A[tmp] % MOD) % MOD;
        }
        return res;
    }
};