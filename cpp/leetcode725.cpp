#include <iostream>
#include <vector>
using namespace std;

struct ListNode 
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
	vector<ListNode*> splitListToParts(ListNode* root, int k)
	{
		vector<ListNode*> ret;
		int n = 0;
		ListNode * t = root;
		while (t) { n++; t = t->next; }
		if (n < k)
		{
			t = root;
			while (t) 
			{ 
				ListNode * tmp = new ListNode(t->val); 
				ret.push_back(tmp); 
				t = t->next;
			}
			for (int i = 0; i < k - n; i++) ret.push_back(NULL);
			return ret;
		}
		t = root->next;
		int blk = (n + k - 1) / k, cnt = 0, i = 1;
		ListNode * now = new ListNode(root->val);
		ListNode * tail = now;
		while (t)
		{
			if (i % blk == 0)
			{
				ret.push_back(now);
				now = new ListNode(t->val);
				tail = now;
				cnt++;
				if (cnt == n % k) blk--;
				i = 0;
			}
			else
			{
				tail->next = new ListNode(t->val);
				tail = tail->next;
			}
			t = t->next;
			i++;
		}
		ret.push_back(now);
		return ret;
	}
};
int main()
{
	ListNode * root = new ListNode(1);
	ListNode * tail = root;
	for (int i = 1; i < 10; i++)
	{
		tail->next = new ListNode(i + 1);
		tail = tail->next;
	}
	vector<ListNode*> ans = Solution().splitListToParts(root, 6);
	for (int i = 0; i < ans.size(); i++)
	{
		ListNode * tmp = ans[i];
		while (tmp)
		{
			cout << tmp->val << " ";
			tmp = tmp->next;
		}
		cout << endl;
	}
	return 0;
}

