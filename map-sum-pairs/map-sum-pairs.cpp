class MapSum 
{
public:
    /** Initialize your data structure here. */
    map<string,int> m;
    
    MapSum() 
    {
        
    }
    
    void insert(string key, int val) 
    {
        m[key] = val;   
    }
    
    int sum(string prefix) 
    {
        int sum = 0;
        
        for(auto x : m)
        {
            string s = x.first;
            
            int i = 0;
            
            while(i < prefix.length() and prefix[i] == s[i])
            {
                i++;
            }
            if(i == prefix.length())
            {
                sum += x.second;
            }
        }
        
        return sum;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */