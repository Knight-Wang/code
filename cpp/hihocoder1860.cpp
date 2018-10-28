#include <iostream>
using namespace std;

const int INF = 0x3f3f3f3f;
const int N = 100005;
int a[N], cnt = 0;

struct trieNode
{
	trieNode * next[2];
}; 

trieNode pool[N * 32];

trieNode * createTrie()
{
	trieNode * root = &pool[cnt++];
	for (int i = 0; i < 2; i++)
	{
		root->next[i] = NULL;	
	}
	return root;
} 

void insert(trieNode * root, int x)
{
	trieNode * tmp = root;
	int index;
	for (int i = 31; i >= 0; i--)
	{
		int msk = (1 << i);
		if (msk & x) index = 1;
		else index = 0;
		if (tmp->next[index] == NULL)
		{
			tmp->next[index] = createTrie();
		}
		tmp = tmp->next[index];
	}
}

int search(trieNode * root, int x)
{
	trieNode * tmp = root;
	int res = 0;
	for (int i = 31; i >= 0; i--)
	{
		int msk = 1 << i;
		int need;
		if (msk & x) need = 0;
		else need = 1;
		if (i == 31) need = 1 - need;
		if (tmp->next[need])
		{
			res += (need << i);
			tmp = tmp->next[need];
		}
		else
		{
			res += (1 - need << i);
			tmp = tmp->next[1 - need];
		}
	}
	return x ^ res;
}

int main()
{
	int n;
	while (cin >> n)
	{
		cnt = 0;
		trieNode * root = createTrie();
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i];
			a[i] = a[i - 1] ^ a[i];
			insert(root, a[i]);
		}
		insert(root, 0);
		int ans = -INF;
		for (int i = 1; i <= n; i++)
		{
			ans = max(ans, search(root, a[i]));
		}
		cout << ans << endl;
	}
	return 0;
}