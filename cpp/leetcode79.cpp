class Solution
{
public:
    const int dx[4] = {0, -1, 0, 1};
    const int dy[4] = {1, 0, -1, 0};
    bool dfs(vector<vector<char>>& b, int x, int y, string w, int cur)
    {
        if (cur == w.length()) return true;
        int n = b.size(), m = b[0].size();
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i], ny = y + dy[i];
            pair<int, int> tmp(nx, ny);
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && b[nx][ny] == w[cur])
            {
                char tmp = b[nx][ny]; b[nx][ny] = ' ';
                if (dfs(b, nx, ny, w, cur + 1)) return true;
                b[nx][ny] = tmp;
            }
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word)
    {
        int l = word.length();
        if (l == 0) return true;
        int n = board.size();
        if (n == 0) return false;
        int m = board[0].size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (board[i][j] == word[0])
                {
                    char tmp = board[i][j];
                    board[i][j] = ' ';
                    if (dfs(board, i, j, word, 1)) return true;
                    board[i][j] = tmp;
                }
            }
        }
        return false;
    }
};