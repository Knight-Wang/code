#include <bits/stdc++.h>
using namespace std;
class Solution 
{
public:
    int longestSubstring(string s, int k) 
    {
        int n = s.length();
		if (k == 1) return n;
		int ans = 0;
		vector<int> num(26, 0);
		for (int i = 1; i <= 26; i++)
		{
			fill(num.begin(), num.end(), 0);
			int slow = 0, fast = 0, cnt = 0;
			set<char> st;
			while (fast < n)
			{
				while (fast < n)
				{
					if (num[s[fast] - 'a'] == 0) cnt++;
					num[s[fast] - 'a']++;
					st.insert(s[fast]);
					fast++;
					if (cnt == i && fast < n && num[s[fast] - 'a'] == 0)
						break;
				}
				bool flg = true;
				for (auto it: st)
					if (num[it - 'a'] < k) { flg = false; break; }
				if (flg) ans = max(ans, fast - slow);
				if (fast == n) break;
				while (slow < fast && cnt == i)
				{
					num[s[slow] - 'a']--;
					if (num[s[slow] - 'a'] == 0) { cnt--; st.erase(s[slow]); }
					slow++;
				}
			}
		}
		return ans;
    }
};
int main()
{
	string s = "aabbccdcccde"; int k = 2;
	cout << Solution().longestSubstring(s, k) << endl;
	return 0;
}