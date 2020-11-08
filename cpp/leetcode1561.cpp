class Solution
{
public:
    int maxCoins(vector<int>& piles)
    {
        int n = piles.size();
        sort(piles.begin(), piles.end());
        int res = 0, p = n;
        for (int i = 0; i < n / 3; i++) res += piles[p -= 2];
        return res;
    }
};