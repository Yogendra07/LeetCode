class Solution 
{
public:
    int findLength(vector<int>& text1, vector<int>& text2) 
    {
        int m = text1.size();
        int n = text2.size();
        
        int dp[m+1][n+1];
        
        int val = 0;
        
        for(int i=0;i<m+1;i++)
        {
            for(int j=0;j<n+1;j++)
            {
                dp[i][j] = 0;
            }
        }
        
        for(int i=1;i<m+1;i++)
        {
            for(int j=1;j<n+1;j++)
            {
                if(text1[i-1] == text2[j-1])
                {
                    dp[i][j] = 1 + dp[i-1][j-1];
                    
                    val = max(dp[i][j],val);
                }
            }
        }
        
      
        return val;
        
    }
};