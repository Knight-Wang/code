#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    string getPermutation(int n, int k) 
    {
        vector<int> f; f.push_back(1);
        int x = 1;
        for (int i = 1; i <= n; i++)
        {
            x *= i;
            f.push_back(x);
        }
        string ret = "";
        int tmp, vis[10];
        memset(vis, 0, sizeof vis);
        for (int i = n - 1; i >= 0; i--)
        {
            tmp = (k + f[i] - 1) / f[i];
            k -= (tmp - 1) * f[i];
            int now = 0, j = 1;
            for (; j <= n; j++)
            {
                if (!vis[j]) now++;
                if (now == tmp) break;
            }
            vis[j] = 1;
            ret += (char)(j + '0');
        }
        return ret;
    }
};
int main()
{
	Solution s;
	cout << s.getPermutation(9, 54454) << endl;
	return 0;
}