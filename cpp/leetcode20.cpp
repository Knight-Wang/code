class Solution 
{
public:
    bool isValid(string s) 
    {
        stack<char> sta;
        set<char> st{'{', '(', '['};
        map<char, char> mp; mp['}'] = '{'; mp[')'] = '('; mp[']'] = '[';
        for (auto it: s)
        {
            if (st.count(it)) sta.push(it);
            else
            {
                char t = mp[it];
                if (sta.empty() || sta.top() != t) return false;
                sta.pop();
            }
        }
        return sta.empty();
    }
};