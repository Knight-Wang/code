class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        map<string, multiset<string>> m;
        int n = strs.size();
        for (int i = 0; i < n; i++)
        {
            string tmp = strs[i];
            sort(tmp.begin(), tmp.end());
            if (m.count(tmp))
                m[tmp].insert(strs[i]);
            else
            {
                m[tmp] = multiset<string>();
                m[tmp].insert(strs[i]);
            }
        }
        vector<vector<string>> res;
        map<string, multiset<string>>::iterator it = m.begin();
        for ( ; it != m.end(); it++)
        {
            multiset<string> mu = it->second;
            multiset<string>::iterator it1 = mu.begin();
            vector<string> tmp;
            for ( ; it1 != mu.end(); it1++)
            {
                tmp.push_back(*it1);
            }
            res.push_back(tmp);
        }
        return res;
    }
};