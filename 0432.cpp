class AllOne
{
public:
    unordered_map<string,int> myMap;
    set<pair<int,string>> mySet;
    
    AllOne()
    {
        
    }
    
    void inc(string key)
    {
        if (myMap.count(key))
            mySet.erase({myMap[key], key});
        myMap[key]++;
        mySet.insert({myMap[key], key});
    }
    
    void dec(string key)
    {
        mySet.erase({myMap[key], key});
        myMap[key]--;
        if (myMap[key])
            mySet.insert({myMap[key], key});
    }
    
    string getMaxKey()
    {
        if (mySet.empty())
            return "";
        return mySet.rbegin()->second;
    }
    
    string getMinKey()
    {
        if (mySet.empty())
            return "";
        return mySet.begin()->second;
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */