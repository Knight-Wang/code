class Solution 
{
public:
    int sum(int x)
    {
        int ans = 0;
        while (x) 
        {
            int tmp = x % 10;
            ans += tmp * tmp;
            x /= 10;
        }
        return ans;
    }
    bool isHappy(int n) 
    {
        set<int> st;
        int x = sum(n);
        while (x != 1)
        {
            if (st.count(x)) return false;
            st.insert(x);
            x = sum(x);
        }
        return true;
    }
};