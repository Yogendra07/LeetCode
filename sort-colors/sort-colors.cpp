class Solution 
{
public:
    void sortColors(vector<int>& nums) 
    {
        int ones = 0;
        int twos = 0;
        int zeros = 0;
        
        for(auto x : nums)
        {
            if(x == 1)ones++;
            if(x == 2)twos++;
            if(x == 0)zeros++;
        }
        
        int i = 0;
        while(zeros--)
        {
            nums[i++] = 0;
        }
        
        while(ones--)
        {
            nums[i++] = 1;
        }
        
        while(twos--)
        {
            nums[i++] = 2;
        }
        
    }
};