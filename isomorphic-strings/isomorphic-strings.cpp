class Solution 
{
public:
    bool isIsomorphic(string s, string t) 
    {
        unordered_map<char,int> m1;
        unordered_map<char,int> m2;
    
        unordered_map<char,char> u;
        
        for(int i=0;i<s.length();i++)
        {
            if(u.find(s[i]) == u.end())
            {
                u[s[i]] = t[i];
            }
            else
            {
                char ch = u[s[i]];
                
                if(ch != t[i])
                {
                    return false;
                }
            }
        }
        
        for(auto x : s)
        {
            m1[x]++;
        }
        
        for(auto x : t)
        {
            m2[x]++;
        }
        
        // cout<<s<<endl<<t;
        
        for(int i=0;i<s.length();i++)
        {
            if(m1[s[i]] != m2[t[i]])
            {
                return false;
            }
        }
        
        return true;
    }
};