class Solution 
{
public:
    string minWindow(string s, string t) 
    {
        unordered_map<char,int> m;
        
        for(auto x : t)
            m[x]++;
        
        int start = 0;
        int end = 0;
        
        int min_start = 0;
        int size = s.length();
        int min_len = INT_MAX;
        
        int counter = t.size();
        
        while(end < size)
        {
            if(m[s[end]] > 0)
            {
                counter--;
            }
            
            m[s[end]]--;
            end++;
            
            while(counter == 0)
            {
                if(end - start < min_len)
                {
                    min_start = start;
                    min_len = end - start;
                }
                
                m[s[start]]++;
                  
                if(m[s[start]] > 0)
                {
                    counter++;    
                }
                  
                start++;
            }
        }
                  
        if(min_len == INT_MAX)
            return "";
                  
        return s.substr(min_start,min_len);

        
    }
};