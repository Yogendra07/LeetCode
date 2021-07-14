class Solution {
public:
    string customSortString(string order, string str) 
    {
        string ans =  "";
        
        unordered_map<char,int> m;
        unordered_map<char,int> u;
        
        for(auto x : order)
            m[x]++;
        
        for(auto x : str)
            u[x]++;
        
        
        for(auto x : order)
        {
            if(u.find(x) != u.end() and u[x] != 0)
            {
                while(u[x] != 0)
                {
                    ans += x;
                    u[x]--;
                }
            }
        }
        
        for(auto x : str)
        {
            if(m.find(x) == m.end())
            {
                ans += x;
            }
        }
        
        return ans;
    }
};