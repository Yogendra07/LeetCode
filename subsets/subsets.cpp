class Solution 
{
public:
    vector<vector<int>> ans;
    void filterChars(int n,vector<int> &nums)
    {
        vector<int> v;
        int j = 0;
        while(n>0)
        {
            int last_bit = (n&1);
            if(last_bit==1)
            {
                v.push_back(nums[j]);
            }
            j++;
            n=n>>1; 
        }
    
        ans.push_back(v);
    }
    
    vector<vector<int>> subsets(vector<int>& nums) 
    {
        int n = nums.size();
        for(int i=0;i<(1<<n);i++)
        {
            filterChars(i,nums);
        }
        return ans;
    }
};