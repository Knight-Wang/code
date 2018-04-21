#include <bits/stdc++.h>
using namespace std;
const int N = 100;
void find_top_k(int * a, int l, int r, int k)
{
	if (l >= r) return;
	int lp = l, rp = r;
	while (lp < rp)
	{
		while (rp > lp && a[rp] <= a[lp]) rp--;
		swap(a[lp], a[rp]);
		while (lp < rp && a[lp] >= a[rp]) lp++;
		swap(a[lp], a[rp]);
	}
	if (lp > k) find_top_k(a, l, lp - 1, k);
	else if (lp < k) find_top_k(a, lp + 1, r, k - lp - 1);
	else return;
}
int main()
{
	int * a = new int[N];
	int K = 6;
	for (int i = 0; i < N; i++) a[i] = rand() % 1000;
	for (int i = 0; i < N; i++) cout << a[i] << " ";
	cout << endl;
	cout << "+++" << endl; 
	find_top_k(a, 0, N - 1, K);
	for (int i = 0; i < N; i++) cout << a[i] << " ";
	cout << endl;
	return 0;
}