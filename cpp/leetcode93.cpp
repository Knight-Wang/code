class Solution
{
public:
    vector<string> restoreIpAddresses(string s)
    {
        vector<string> ans;
        int n = s.length();
        if (n < 4 || n > 12) return ans;
        for (int i = 0; i < (1 << n - 1); i++)
        {
            if (__builtin_popcount(i) != 3) continue;
            int msk = i;
            msk |= (1 << n - 1);
            vector<int> v; int last = 0;
            bool flg = true;
            for (int j = 0; j < n; j++)
            {
                int t = 1 << j;
                if (t & msk)
                {
                    string str = s.substr(last, j + 1 - last);
                    if (str[0] == '0' && str.length() > 1) { flg = false; break; }
                    v.push_back(stoi(str));
                    last = j + 1;
                }
            }
            if (!flg) continue;
            for (auto it: v)
            {
                if (it > 255) { flg = false; break; }
            }
            if (!flg) continue;
            string s = "";
            for (int i = 0; i < v.size(); i++)
            {
                s += to_string(v[i]);
                if (i != v.size() - 1) s += ".";
            }
            ans.push_back(s);
        }
        return ans;
    }
};