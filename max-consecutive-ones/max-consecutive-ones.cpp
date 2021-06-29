class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) 
    {
        int len = 0;
        int max_len = INT_MIN;

        for(int i=0;i<nums.size();i++)
        {
            
            if(nums[i] == 1)
            {
                while((i < nums.size()) and (nums[i] == 1))
                {
                    len++;
                    i++;
                }
                
                if(len > max_len)
                {
                    max_len = len;
                    len = 0;
                }
                
                len = 0;
           
            }
            
        }
 
        return max(len,max_len);
    }
};