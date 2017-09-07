class Solution 
{
public:
    bool check(string a, string b)
    {
        int cnt = 0;
        int n = a.length();
        for (int i = 0; i < n; i++)
        {
            if (a[i] != b[i]) cnt++;
        }
        return cnt == 1;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) 
    {
        if (find(wordList.begin(), wordList.end(), endWord) == wordList.end()) 
            return 0;
        int n = wordList.size();
        unordered_map<int, unordered_set<int>> ok;
        ok[-1] = unordered_set<int>();
        for (int i = 0; i < n; i++) 
            if (check(beginWord, wordList[i])) ok[-1].insert(i);
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (i == j) continue;
                if (check(wordList[i], wordList[j]))
                {
                    if (!ok.count(i)) 
                        ok[i] = unordered_set<int>();
                    ok[i].insert(j);
                    if (!ok.count(j)) 
                        ok[j] = unordered_set<int>();
                    ok[j].insert(i);
                }
            }
        }
        vector<int> vis(n, 0);
        
        queue<pair<int, int>> q;
        q.push(pair<int, int>(-1, 1));
        while (!q.empty())
        {
            pair<int, int> tmp = q.front();
            q.pop();
            if (tmp.first != -1)
            { 
                if (vis[tmp.first]) continue; vis[tmp.first] = 1; 
                if (wordList[tmp.first] == endWord) return tmp.second;
            }
            for (auto it : ok[tmp.first])
            {
                q.push(pair<int, int>(it, tmp.second + 1));
            }
        }
        return 0;
    }
};