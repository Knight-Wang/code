#include <bits/stdc++.h>
using namespace std;

class LRUCache
{
public:
    
    int c;
    list<int> l; // list of key
    unordered_map<int, pair<int, list<int>::iterator>> mp; // <key, <value, it>>

    LRUCache(int capacity) { c = capacity; }
    
    int get(int key)
    {
        if (!mp.count(key)) return -1;
        l.erase(mp[key].second);
        l.push_front(key);
        mp[key].second = l.begin();
        return mp[key].first;
    }
    
    void put(int key, int value)
    {
        if (mp.count(key))
        {
            l.erase(mp[key].second);
            mp.erase(key);
        }
        else if (l.size() == c)
        {
            mp.erase(l.back());
            l.pop_back();
        }
        l.push_front(key);
        mp[key] = make_pair(value, l.begin());
    }
};

int main()
{
    LRUCache* obj = new LRUCache(2);
    obj->put(1, 1);
    obj->put(2, 2);
    cout << obj->get(1) << endl;
    obj->put(3, 3);
    cout << obj->get(2) << endl;
    obj->put(4, 4);
    cout << obj->get(1) << endl;
    cout << obj->get(3) << endl;
    cout << obj->get(4) << endl;
    return 0;
}