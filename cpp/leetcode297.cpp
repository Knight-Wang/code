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
        if (!root) return "x";
        return to_string(root->val) + ',' + serialize(root->left) + ',' + serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data)
    {
        data += ',';
        int l = data.length();
        queue<string> q; int last = 0;
        for (int i = 0; i < l; i++)
        {
            if (data[i] == ',')
            {
                q.push(data.substr(last, i - last));
                last = i + 1;
            }
        }
        return work(q);
    }
    
    TreeNode* work(queue<string>& q)
    {
        string t = q.front(); q.pop();
        if (t == "x") return NULL;
        TreeNode* res = new TreeNode(stoi(t));
        res->left = work(q);
        res->right = work(q);
        return res;
    }

};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));