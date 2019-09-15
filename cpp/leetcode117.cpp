/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() {}

    Node(int _val, Node* _left, Node* _right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/
class Solution
{
public:
    Node* connect(Node* root)
    {
        if (root == NULL) return NULL;
        Node* head = new Node(0, NULL, NULL, NULL);
        Node* tail = head, *cur = root;
        while (cur != NULL)
        {
            if (cur->left != NULL)
            {
                tail->next = cur->left; tail = tail->next;
            }
            if (cur->right != NULL)
            {
                tail->next = cur->right; tail = tail->next;
            }
            if (cur->next != NULL) cur = cur->next;
            else
            {
                cur = head->next;
                head->next = NULL;
                tail = head;
            }
        }
        return root;
    }
};