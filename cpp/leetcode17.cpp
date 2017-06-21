class Solution 
{
public:
    vector<string> letterCombinations(string digits) 
    {
        if (!digits.length()) return vector<string>();
        string mapping[10] = {"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> res;
        res.push_back("");
        for (int i = 0; i < digits.length(); i++)
        {
            string tmp = mapping[digits[i] - '0'];
            vector<string> tmpres;
            for (int j = 0; j < tmp.length(); j++)
            {
                for (int k = 0; k < res.size(); k++)
                {
                    tmpres.push_back(res[k] + tmp[j]);
                }
            }
            res = tmpres;
        }
        return res;
    }
};