class TimeMap
{
public:
    /** Initialize your data structure here. */
    map<string, map<int, string>> mp;
    TimeMap()
    {
        
    }
    
    void set(string key, string value, int timestamp)
    {
        if (!mp.count(key)) mp[key] = map<int, string>();
        mp[key][timestamp] = value;
    }
    
    string get(string key, int timestamp)
    {
        if (!mp.count(key)) return "";
        auto it = mp[key].lower_bound(timestamp);
        if (it == mp[key].end()) return mp[key].rbegin()->second;
        else if (it->first == timestamp) return it->second;
        else if (it == mp[key].begin()) return "";
        else return (--it)->second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */