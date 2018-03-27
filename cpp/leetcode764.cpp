#include <bits/stdc++.h>
using namespace std;
class Solution 
{
public:
    int orderOfLargestPlusSign(int N, vector<vector<int>>& mines)
	{
		vector<vector<int>> left(N, vector<int>(N, 0)), right(N, vector<int>(N, 0));
		vector<vector<int>> up(N, vector<int>(N, 0)), down(N, vector<int>(N, 0));
		vector<vector<int>> a(N, vector<int>(N, 1));
		for (int i = 0; i < mines.size(); i++) 
			a[mines[i][0]][mines[i][1]] = 0;
		for (int i = 0; i < N; i++)
		{
			left[i][0] = (a[i][0] == 1 ? 1 : 0);
			right[i][N - 1] = (a[i][N - 1] == 1 ? 1 : 0);
			for (int j = 1; j < N; j++)
			{
				left[i][j] = a[i][j] == 0 ? 0 : left[i][j - 1] + 1;
				right[i][N - 1 - j] = a[i][N - 1 - j] == 0 ? 0 : right[i][N - j] + 1;
			}
		}
		for (int j = 0; j < N; j++)
		{
			up[0][j] = (a[0][j] == 1 ? 1 : 0);
			down[N - 1][j] = (a[N - 1][j] == 1 ? 1 : 0);
			for (int i = 1; i < N; i++)
			{
				up[i][j] = a[i][j] == 0 ? 0 : up[i - 1][j] + 1;
				down[N - 1 - i][j] = a[N - 1 - i][j] == 0 ? 0 : down[N - i][j] + 1;
			}
		}
		int maxn = 0;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				int tmp = min(min(min(up[i][j], down[i][j]), left[i][j]), right[i][j]);
				maxn = max(maxn, tmp);
			}
		}
		return maxn;
    }
};
int main()
{
	vector<int> x;
	x.push_back(4); x.push_back(2);
	vector<vector<int>> v;
	v.push_back(x);
	cout << Solution().orderOfLargestPlusSign(5, v) << endl;
	return 0;
}