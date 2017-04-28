#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution 
{
public:
    string longestCommonPrefix(vector<string>& strs) 
	{
        int n = strs.size();
        if (!n)
            return "";
        int minn = 0x3f3f3f3f;
        for (int i = 0; i < n; i++)
        {
            if(strs[i].length() < minn) minn = strs[i].length();
        }
        if (!minn) return "";
        int l = 0;
        for (; l < minn; l++)
        {
            char x = strs[0][l];
            for (int i = 1; i < n; i++)
            {
                if (strs[i][l] != x) return strs[0].substr(0, l);
            }
        }
        return strs[0].substr(0, minn);
    }
};

int main()
{
	Solution s;
	vector<string> x;
	x.push_back("xyz");
	x.push_back("xy");
	cout << s.longestCommonPrefix(x) << endl;
	return 0;
}