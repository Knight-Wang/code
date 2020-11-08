class Solution
{
public:
    vector<int> mostVisited(int n, vector<int>& rounds)
    {
        int m = rounds.size();
        vector<int> res;
        int b = rounds[0], e = rounds[m - 1];
        if (b <= e)
        {
            for (int i = b; i <= e; i++) res.push_back(i);
        }
        else
        {
            for (int i = 1; i <= e; i++) res.push_back(i);
            for (int i = b; i <= n; i++) res.push_back(i);
        }
        return res;
    }
};