class Solution {
public:
    string longestPalindrome(string s) 
    {
        if(s.length() == 1)
        {
            return s;
        }
        
        char ch = s[0];
        
        int val = 1;
        for(int i=1;i<s.length();i++)
        {
            if(s[i] == ch)
            {
                val++;
            }
        }
        
        if(val == s.length())
        {
            return s;
        }
        
        if(s.length() == 2)
        {
            if(s[0] == s[1])
            {
                return s;
            }
            else
            {
                string p = "";
                p += s[0];
                
                return p;
            }
        }
        
        string ans = "";
        ans += s[0];
            
        for(int i=1;i<s.length();i++)
        {
            int left = i-1;
            int right = i+1;
            
            int len = 1;
            
            while(left >= 0 and right < s.length() and s[left] == s[right])
            {
                left--;
                right++;
                len += 2;
            }
            
            if(len > ans.length())
            {
                ans = s.substr(left+1,right-left-1);
            }
            
            left = i-1;
            right = i;
            
            len = 0;
            
            while(left >=0 and right < s.length() and s[left] == s[right])
            {
                left--;
                right++;
                len += 2;
            }
            
            if(len > ans.length())
            {
                ans = s.substr(left+1,right-left-1);
                
            }
            
        }
        
        return ans;
    }
};