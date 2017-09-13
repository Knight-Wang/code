class Solution 
{
public:
	void getPath(string now, string beginWord, string endWord, vector<string>& buf, unordered_map<string, unordered_set<string>>& par, vector<vector<string>>& ret)
	{
		if (now == beginWord)
		{
			vector<string> tmp(1, endWord);
			for (auto it : buf) tmp.push_back(it);
			ret.push_back(tmp);
			reverse(ret.back().begin(), ret.back().end());
			return;
		}
		for (auto it : par[now])
		{
			buf.push_back(it);
			getPath(it, beginWord, endWord, buf, par, ret);
			buf.pop_back();
		}
	}
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) 
    {
		unordered_set<string> tmp;
		for (auto it : wordList) tmp.insert(it);
		unordered_map<string, unordered_set<string>> par;
		unordered_set<string> q;
		q.insert(beginWord);
		bool flg = false;
		while (!q.empty())
		{
			unordered_set<string> next;
			for (auto it : q)
			{
 				for (int i = 0; i < it.length(); i++)
				{
					for (char c = 'a'; c <= 'z'; c++)
					{
						string buf = it;
						if (buf[i] == c) continue;
						buf[i] = c;
						if (!tmp.count(buf)) continue;
						if (!q.count(buf)) 
						{
							next.insert(buf);
							par[buf].insert(it);
						}
						if (buf == endWord) flg = true;
					}	
				} 
			}
			for (auto it : q) { tmp.erase(it); }
			q = next;
			if (flg) break;
		}
		vector<vector<string>> ret;
		if (flg) 
		{
			vector<string> buf;
			getPath(endWord, beginWord, endWord, buf, par, ret);
		}
		return ret;
    }
};