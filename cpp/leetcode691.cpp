#include <bits/stdc++.h>
using namespace std;
class Solution 
{
public:
    int minStickers(vector<string>& stickers, string target) 
    {
		vector<vector<int>> v(stickers.size(), vector<int>(26, 0));
		for (int i = 0; i < stickers.size(); i++)
		{
			for (int j = 0; j < stickers[i].size(); j++)
			{
				v[i][stickers[i][j] - 'a']++;
			}
		}
		vector<int> dp(1 << target.size(), -1);
		int ret = dfs(0, v, target, dp);
		if (ret < 0x3f3f3f3f) return ret;
		return -1;
    }
	int dfs(int now, vector<vector<int>>& v, string target, vector<int>& dp)
	{
		if (now == (1 << target.size()) - 1) return 0;
		if (dp[now] != -1) return dp[now];
		int minn = 0x3f3f3f3f;
		
		for (int i = 0; i < v.size(); i++)
		{
			vector<int> tmp = v[i];
			int s = now;
			for (int j = 0; j < target.size(); j++)
			{
				if (!(s & (1 << j)) && tmp[target[j] - 'a'])
				{
					s |= (1 << j); tmp[target[j] - 'a']--;
				}
			}
			if (s != now) { minn = min(minn, dfs(s, v, target, dp) + 1); }
		}
		return dp[now] = minn;
	}
};