#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost)
    {
        int n = gas.size(), sum = 0, start = 0, ans = -1;
        for (int i = 0; i < 2 * n; i++)
        {
            sum += gas[i % n];
            sum -= cost[i % n];
            if (sum < 0) { sum = 0; start = i + 1; }
            if (i - start == n) { ans = start; break; }
        }
        return ans;
    }
};
int main()
{
    // int g[] = {1, 2, 3, 4, 5};
    // int c[] = {3, 4, 5, 1, 2};
    // int g[] = {2, 3, 4};
    // int c[] = {3, 4, 3};
    int g[] = {5, 1, 2, 3, 4};
    int c[] = {4, 4, 1, 5, 1};
    vector<int> gas(begin(g), end(g));
    vector<int> cost(begin(c), end(c));
    cout << Solution().canCompleteCircuit(gas, cost) << endl;
    return 0;
}