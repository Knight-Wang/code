class MapSum 
{
public:
    /** Initialize your data structure here. */
    map<string, int> mp;
    MapSum() {}
    
    void insert(string key, int val) 
    {
        mp[key] = val;
    }
    
    int sum(string prefix) 
    {
        int tot = 0, n = prefix.length();
        for (auto it = mp.lower_bound(prefix); 
             it != mp.end() && (it->first).substr(0, n) == prefix; 
             it++)
            tot += it->second;
        return tot;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum obj = new MapSum();
 * obj.insert(key,val);
 * int param_2 = obj.sum(prefix);
 */