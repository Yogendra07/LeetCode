class Solution {
public:
    int lengthOfLIS(vector<int>& nums) 
    {
        int n = nums.size();
        
        int dp[n];
        
        for(int i=0;i<n;i++)
        {
            dp[i] = 1;
        }
        
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[i] > nums[j] and dp[i] < 1 + dp[j])
                {
                    dp[i] = 1 + dp[j];
                }
            }
        }
    
        return *max_element(dp,dp+n);
    }
};