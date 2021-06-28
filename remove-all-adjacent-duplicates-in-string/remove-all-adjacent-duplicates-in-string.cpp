class Solution {
public:
    string removeDuplicates(string s) 
    {
        int n = s.length()-1;
        
        for(int i=0;i<n;i++)
        {
            if(s[i] == s[i+1])
            {
                s.erase(i,2);                
                if(i == 0)
                {
                    i = i - 1;
                }
                else
                {
                    i = i - 2;
                }
            }
            
        }
        
        return s;
    }
};