class Solution
{
public:
    int smallestFactorization(int a) 
    {
        if (a < 10) return a;
        map<int, int> mp;
        for (int i = 2; (long long)i * i <= a; i++)
        {
            while (a % i == 0)
            {
                if (!mp.count(i)) mp[i] = 0;
                mp[i]++;
                a /= i;
            }
        }
        if (a != 1)
        {
            if (!mp.count(a)) mp[a] = 0;
            mp[a]++;
        }
        vector<int> v;
        int c2 = 0, c3 = 0;
        if (mp.count(2)) c2 = mp[2];
        if (mp.count(3)) c3 = mp[3];
        for (int i = 0; i < c2 / 3; i++) v.push_back(8);
        c2 %= 3;
        for (int i = 0; i < c3 / 2; i++) v.push_back(9);
        c3 %= 2;
        if (c3)
        {
            if (c2 == 0) v.push_back(3);
            else
            {
                v.push_back(6);
                if (c2 == 2) v.push_back(2);
            }
        }
        else if (c2 == 1) v.push_back(2);
        else if (c2 == 2) v.push_back(4);
        for (auto it: mp)
        {
            if (it.first >= 11) return 0;
            else if (it.first >= 5)
            {
                for (int i = 0; i < it.second; i++) v.push_back(it.first);
            }
        }
        sort(v.begin(), v.end());
        long long res = 0;
        for (int i = 0; i < v.size(); i++)
        {
            res += v[i];
            if (i != v.size() - 1) res *= 10;
        }
        return res > INT_MAX ? 0 : res;
    }
};