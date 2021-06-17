class Solution 
{
public:
    int count(vector<int> &nums,int bound)
    {
        int ans = 0;
        int cnts = 0;
        
        for(auto x : nums)
        {
            if(x <= bound)
            {
                cnts++;
                ans += cnts;
            }
            else
            {
                cnts = 0;
            }
        }
        
        return ans;
    }
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) 
    {
        return count(nums,right) - count(nums,left-1);
    }
};