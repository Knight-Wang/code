#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int n = s.length(), i = 0, ans = 0;
        unordered_set<char> st;
        for (int j = 0; j < n; j++)
        {
            if (st.count(s[j]))
            {
                while (s[i] != s[j]) st.erase(s[i++]);
                st.erase(s[i++]);
            }
            ans = max(ans, j - i + 1);
            st.insert(s[j]);
        }
        return ans;
    }
};
int main()
{
    cout << Solution().lengthOfLongestSubstring("abcabcbb") << endl;
    return 0;   
}