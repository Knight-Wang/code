#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
	static bool cmp(string a, string b)
	{
		string x = a + b, y = b + a;
		return x > y;
	}
	string largestNumber(vector<int>& nums) 
	{
		int n = nums.size();
		if (!n) return "";
		vector<string> v;
		for (int i = 0; i < n; i++) v.push_back(to_string(nums[i]));
		sort(v.begin(), v.end(), cmp);
		if (v[0] == "0") return "0";
		string ans = "";
		for (auto it: v) ans += it;
		return ans;
	}
};

int main()
{
	int a[] = {3, 30, 34, 5, 9};
	vector<int> v(a, a + 5);
	cout << Solution().largestNumber(v) << endl;
	return 0;
}