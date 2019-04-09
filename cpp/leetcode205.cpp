#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        map<char, char> mp;
        set<char> st;
        int n = s.length();
        for (int i = 0; i < n; i++)
        {
            if (mp.count(s[i]))
            {
                if (mp[s[i]] != t[i]) return false;
            }
            else
            {
                if (st.count(t[i])) return false;
                mp[s[i]] = t[i];
                st.insert(t[i]);
            }
        }
        return true;
    }
};
int main()
{
    cout << Solution().isIsomorphic("egg", "add") << endl;
    cout << Solution().isIsomorphic("foo", "bar") << endl;
    cout << Solution().isIsomorphic("paper", "title") << endl;
    cout << Solution().isIsomorphic("ab", "aa") << endl;
    return 0;
}