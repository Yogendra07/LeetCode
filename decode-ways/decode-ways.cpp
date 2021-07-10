class Solution {
public:
    int numDecodings(string s) 
    {
        if(s.length() == 0 or s[0] == '0')
        {
            return 0;
        }
        
        if(s.length() == 1)
        {
            return 1;
        }
        
        int count1 = 1;
        int count2 = 1;
        
        int n = s.length();
        
        int dp[n];
        
        dp[0] = 1;
        
        for(int i=1;i<s.length();i++)
        {
            int val1 = s[i] - '0';
            int val2 = stoi(s.substr(i-1,2));
            
            int ans = 0;
            
            if(val1 > 0)
            {
                ans += count2;    
            }
            
            if(val2 >= 10 and val2 <= 26)
            {
                ans += count1;   
            }
            
            dp[i] = ans;
            
            count1 = count2;
            count2 = ans;
        }
        
        
        return dp[n-1];
        
    }
};