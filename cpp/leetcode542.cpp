#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix)
    {
		int n = matrix.size(), m = matrix[0].size();
		vector<vector<int>> vis(n, vector<int>(m, 0));
		vector<vector<int>> d(n, vector<int>(m, 0x3f3f3f3f));
		queue<pair<int, int>> q;
		int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (matrix[i][j] == 0) 
				{
					q.push(pair<int, int>(i, j));
					vis[i][j] = 1;
					d[i][j] = 0;
				}
			}
		}
		while (!q.empty())
		{
			pair<int, int> tmp = q.front();
			q.pop();
			int x = tmp.first, y = tmp.second;
			for (int i = 0; i < 4; i++)
			{
				int nx = x + dx[i], ny = y + dy[i];
				if (nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny])
				{
					vis[nx][ny] = 1;
					d[nx][ny] = d[x][y] + 1;
					q.push(pair<int, int>(nx, ny));
				}
			}
		}
		return d;
	}
};
int main()
{
	vector<vector<int>> v(3, vector<int>(3, 1));
	v[0][0] = 0;
	vector<vector<int>> ans = Solution().updateMatrix(v);
	for (int i = 0; i < ans.size(); i++)
	{
		for (int j = 0; j < ans[0].size(); j++)
		{
			cout << ans[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
