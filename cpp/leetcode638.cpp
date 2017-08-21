#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
	int dfs(int cur, vector<int> now, vector<int>& price, vector<vector<int>>& special, vector<int>& needs)
	{
		if (cur == special.size()) 
		{
			int sum = 0;
			for (int i = 0; i < needs.size(); i++)
				sum += (needs[i] - now[i]) * price[i];
			return sum;
		}
		int ans = 0x3f3f3f3f;
		bool flg = true;
		for (int k = 0; ; k++)
		{
			vector<int> tmp(now.begin(), now.end());
			for (int i = 0; i < now.size(); i++)
			{
				if (tmp[i] + k * special[cur][i] > needs[i]) { flg = false; break; }
				tmp[i] += k * special[cur][i];
			}
			if (!flg) break;
			ans = min(ans, dfs(cur + 1, tmp, price, special, needs) + k * special[cur][special[cur].size() - 1]);
		}
		return ans;
	}
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) 
    {
		vector<int> x(price.size(), 0);
        return dfs(0, x, price, special, needs);
    }
};
int main()
{
	Solution s;
	/*
	vector<int> price = {2, 3, 4}, needs = {1, 2, 1}, sp1 = {1, 1, 0, 4}, sp2 = {2, 2, 1, 9};
	vector<vector<int>> special; special.push_back(sp1); special.push_back(sp2);
	cout << s.shoppingOffers(price, special, needs) << endl;
	*/
	/*
	vector<int> price = {2, 5}, needs = {3, 2}, sp1 = {3, 0, 5}, sp2 = {1, 2, 10};
	vector<vector<int>> special; special.push_back(sp1); special.push_back(sp2);
	cout << s.shoppingOffers(price, special, needs) << endl;
	*/
	vector<int> price = {9, 9}, needs = {2, 2};
	vector<vector<int>> special; special.push_back(vector<int>{1, 1, 1});
	cout << s.shoppingOffers(price, special, needs) << endl;
	return 0;
}