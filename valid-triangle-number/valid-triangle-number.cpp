class Solution 
{
public:
    int triangleNumber(vector<int>& nums) 
    {
        int ans = 0;
        
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<nums.size();i++)
        {
            for(int j=i+1;j<nums.size();j++)
            {
                int sum = nums[i] + nums[j];
                int it = lower_bound(nums.begin(),nums.end(),sum) - nums.begin();
                // cout<<it-j<<endl;
                if((it - j - 1) > 0)
                ans += it - j - 1;
            }
        }
        
        return ans;
    }
};