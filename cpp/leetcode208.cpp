class Node
{
public:
    int cnt = 0;
    Node * son[26];
    Node()
    {
        for (int i = 0; i < 26; i++) son[i] = NULL;
    }
};
class Trie 
{
public:
    /** Initialize your data structure here. */
    Node * root = NULL;
    Trie() 
    {
        root = new Node();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) 
    {
        int n = (int)word.length();
        Node * tmp = root;
        for (int i = 0; i < n; i++)
        {
            int x = word[i] - 'a';
            if (tmp->son[x] == NULL) tmp->son[x] = new Node();
            tmp->son[x]->cnt++;
            tmp = tmp->son[x];
        }
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) 
    {
        int n = (int)word.length();
        Node * tmp = root;
        int last = 0;
        for (int i = 0; i < n; i++)
        {
            int x = word[i] - 'a';
            if (tmp->son[x] == NULL) return false;
            tmp = tmp->son[x];
            if (i == n - 1) last = tmp->cnt;
        }
        int tot = 0;
        for (int i = 0; i < 26; i++)
        {
            if (tmp->son[i] != NULL) tot += tmp->son[i]->cnt;
        }
        return last - tot > 0;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) 
    {
        int n = (int)prefix.length();
        Node * tmp = root;
        for (int i = 0; i < n; i++)
        {
            int x = prefix[i] - 'a';
            if (tmp->son[x] == NULL) return false;
            tmp = tmp->son[x];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */