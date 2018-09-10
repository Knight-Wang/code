#include <bits/stdc++.h>
using namespace std;
class Solution 
{
public:
    int largestRectangleArea(vector<int>& heights) 
    {
        int n = heights.size();
		vector<int> l(n, -1);
		stack<int> s;
		s.push(0);
		for (int i = 1; i < n; i++)
		{
			if (heights[s.top()] < heights[i])
			{
				l[i] = s.top();
				s.push(i);
			}
			else
			{
				while (!s.empty() && heights[s.top()] >= heights[i])
					s.pop();
				if (!s.empty()) l[i] = s.top();
				s.push(i);
			}
		}
		while (!s.empty()) s.pop();
		s.push(n - 1);
		vector<int> r(n, n);
		for (int i = n - 2; i >= 0; i--)
		{
			if (heights[s.top()] < heights[i])
			{
				r[i] = s.top();
				s.push(i);
			}
			else
			{
				while (!s.empty() && heights[s.top()] >= heights[i])
					s.pop();
				if (!s.empty()) r[i] = s.top();
				s.push(i);
			}
		}
		int ans = 0;
		for (int i = 0; i < n; i++)
		{
			ans = max(ans, heights[i] * (r[i] - l[i] - 1));
		}
		return ans;
    }
};
int main()
{
	int a[] = {2, 1, 5, 6, 2, 3};
	vector<int> v(a, a + 6);
	cout << Solution().largestRectangleArea(v) << endl;
	return 0;
}