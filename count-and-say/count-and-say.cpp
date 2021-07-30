class Solution 
{
public:
    string CS(string s)
    {
        int i = 0;
        string ans = "";
        
        if(s.length() == 1)
        {
            string res = "1";
            res += s[0];
            return res;
        }
        
        while(i < s.length())
        {
            char ch = s[i];
            int count = 1;

            while(i < s.length()-1 and s[i] == s[i+1])
            {
                count++;
                i++;
            }
            
            i++;
            
            char add = count + '0';
            ans += add;
            ans += ch;
        }
        
        return ans;
    }
    string countAndSay(int n) 
    {
        string dp[32];
        dp[0] = "";
        dp[1] = "1";
        
        for(int i=2;i<=n;i++)
        {
            string ans = CS(dp[i-1]);
            dp[i] = ans;
        }
        
        return dp[n];
    }
};