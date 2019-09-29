class Solution
{
public:
    vector<int> pathInZigZagTree(int label)
    {
        int x = 0;
        vector<int> res(1, label);
        int sum = 2, l = label;
        while (l)
        {
            l >>= 1; x++;
            sum += sum + 1;
        }
        sum >>= 1;
        while (x > 1)
        {
            label = (sum - label) / 2;
            res.push_back(label);
            x--;
            sum >>= 1;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};