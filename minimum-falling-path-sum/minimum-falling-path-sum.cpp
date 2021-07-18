class Solution 
{
public:
    int minFallingPathSum(vector<vector<int>>& v) 
    {
        int n = v.size();
        
        int dp[n][n];
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i == 0)
                {
                    dp[i][j] = v[i][j];
                }
                else if(j == 0 || j == n-1)
                {
                    if(j == 0)
                    {
                        dp[i][j] = v[i][j] + min(dp[i-1][j],dp[i-1][j+1]);
                    }
                    else if(j == n-1)
                    {
                        dp[i][j] = v[i][j] + min(dp[i-1][j],dp[i-1][j-1]);
                    }
                }
                else
                {
                    dp[i][j] = v[i][j] + min({dp[i-1][j],dp[i-1][j-1],dp[i-1][j+1]});
                }
            }
        }
        
        int val = INT_MAX;
        
        for(int i=0;i<n;i++)
        {
            if(dp[n-1][i] < val)
            {
                val = dp[n-1][i];
            }
        }
        
        return val;
    }
};