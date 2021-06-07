class Solution {
public:
    int minCostClimbingStairs(vector<int>& nums) 
    {
        int dp[1002] = {0};
        
        if(nums.size() <= 2)
        {
            dp[0] = nums[0];
            dp[1] = min(nums[0],nums[1]);
        }
        else
        {
            dp[0] = nums[0] , dp[1] = nums[1];
            
            for(int i=2;i<nums.size();i++)
            {
                if(i != nums.size()-1)
                {
                    dp[i] = nums[i] + min(dp[i-1],dp[i-2]);
                }
                else
                {
                    int ans1 = dp[i-1];
                    int ans2 = nums[i] + dp[i-2];
                    dp[i] = min(ans1,ans2);
                }
            }
        }
    
        return dp[nums.size()-1];
    }
};