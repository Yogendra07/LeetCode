class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        unordered_map<char,int> m;
        
        int len = 0;
        int max_len = 0;
        
        for(int i=0;i<s.length();i++)
        {
            if(m.find(s[i]) == m.end())
            {
                len++;
                m[s[i]] = i;
            }
            else
            {
                if(len > max_len)
                {
                    max_len = len;
                }
                
                i = m[s[i]];
                
                len = 0;
                m.clear();
            }
        }
      
        if(len > max_len)
        {
            return len;
        }
        
        return max_len;
    }
};