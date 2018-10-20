#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution 
{
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) 
    {
 		unordered_map<int, vector<string>> dp;
		return dfs(s, 0, wordDict, dp);
    }
	vector<string> dfs(string s, int cur, vector<string>& wordDict, unordered_map<int, vector<string>>& dp)
	{
		if (cur >= s.length())
		{
			vector<string> v;
			v.push_back("");
			return v;
		}
		if (dp.count(cur)) return dp[cur];
		vector<string> ans;
		for (auto it: wordDict)
		{
			int l = it.length();
			if (cur + l <= s.length() && s.substr(cur, l) == it)
			{
				if (cur + l == s.length())
					ans.push_back(it);
				else
				{
					vector<string> tmp = dfs(s, cur + l, wordDict, dp);
					for (auto it1: tmp)
					{
						ans.push_back(it + " " + it1);
					}
				}	
			}
		}
		return dp[cur] = ans;
	}
};

int main()
{
	string s = "catsanddog";
	vector<string> v;
	v.push_back("cat");
	v.push_back("cats");
	v.push_back("and");
	v.push_back("sand");
	v.push_back("dog");
	vector<string> ans = Solution().wordBreak(s, v);
	for (auto it: ans)
		cout << it << endl;
	return 0;
}
