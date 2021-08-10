class Solution {
public:
    int minFlipsMonoIncr(string s) 
    {
        vector<int> left(s.length(),0);
        vector<int> right(s.length(),0);
        
        int ones = 0;
        
        for(int i=0;i<s.length();i++)
        {
            if(s[i] == '1')
            {
                ones++;
            }
            
            if(s[i] == '1' and ones != 0)
            {
                left[i] = ones - 1;
            }
            else if(s[i] == '1' and ones == 0)
            {
                left[i] = 0;
            }
            else if(s[i] == '0' and ones != 0)
            {
                left[i] = left[i-1];
            }
            else if(s[i] == '0' and ones == 0)
            {
                left[i] = 0;       
            }
                  
        }
        
        int zeros = 0;
        
        for(int i=s.length()-1;i>=0;i--)
        {
            if(s[i] == '0')
            {
                zeros++;
            }
            
            right[i] = zeros;
        }
        
        int ans = 0;
  
        
        for(int i=0;i<s.length();i++)
        {
            if(i == 0)
            {
                ans = right[i];
            }
            else
            {
                ans = min(ans,(left[i]+right[i]));
            }
        }
        
        return ans;
        
    }
};