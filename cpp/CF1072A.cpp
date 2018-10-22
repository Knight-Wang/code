#include <iostream>
using namespace std;
int main()
{
	int w, h, k;
	while (cin >> w >> h >> k)
	{
		int ans = 0;
		for (int i = 0; i < k; i++)
		{
			ans += (w + h) * 2 - 4;
			w -= 4;
			h -= 4;
		}
		cout << ans << endl;
	}
	return 0;
}
