class Solution 
{
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) 
    {
        vector<vector<int>> G;
        for (int i = 0; i < numCourses; i++) G.push_back(vector<int>());
        vector<int> in(numCourses, 0);
        for (auto it: prerequisites) { G[it.second].push_back(it.first); in[it.first]++; }
        priority_queue<int> q;
        for (int i = 0; i < numCourses; i++)
        {
            if (in[i] == 0) q.push(i);
        }
        int cnt = 0;
        while (!q.empty())
        {
            int x = q.top(); q.pop(); cnt++;
            for (int i = 0; i < G[x].size(); i++)
            {
                int tmp = G[x][i];
                in[tmp]--;
                if (in[tmp] == 0) q.push(tmp);
            }
        }
        return cnt == numCourses;
    }
};