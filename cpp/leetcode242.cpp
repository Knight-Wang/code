class Solution 
{
public:
    bool isAnagram(string s, string t) 
    {
        if (s.length() != t.length()) return false;
        unordered_map<char, int> x, y;
        for (auto it: s) x[it]++;
        for (auto it: t) y[it]++;
        for (auto it: x)
        {
            if (!y.count(it.first) || y[it.first] != it.second) return false;
        }
        return true;
    }
};