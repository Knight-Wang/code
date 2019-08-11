/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec
{
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root)
    {
        return dfs(root);
    }
    
    string dfs(TreeNode* root)
    {
        if (root == NULL) return "N,";
        string res = "";
        res += to_string(root->val); res += ",";
        res += dfs(root->left); res += dfs(root->right);
        return res;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data)
    {
        cout << data << endl;
        queue<string> q; vector<string> v;
        int n = data.length();
        int last = 0;
        for (int i = 0; i < n; i++)
        {
            if (data[i] == ',') 
            {
                q.push(data.substr(last, i - last));
                v.push_back(data.substr(last, i - last));
                last = i + 1;
            }
        }
        return dfs2(q);
    }
    
    TreeNode* dfs2(queue<string>& q)
    {
        if (q.empty()) return NULL;
        if (q.front() == "N") { q.pop(); return NULL; }
        TreeNode* root = new TreeNode(stoi(q.front())); q.pop();
        root->left = dfs2(q); root->right = dfs2(q);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));