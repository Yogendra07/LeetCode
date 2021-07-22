class Solution 
{
public:
    int partitionDisjoint(vector<int>& nums)
    {
        vector<int> v = nums;
        vector<int> left(nums.size(),0);
        vector<int> right(nums.size(),0);
        
        int min_el = INT_MAX;
        int max_el = INT_MIN;
        
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i] > max_el)
            {
                max_el = nums[i];
                left[i] = max_el;
            }
            else
            {
                left[i] = left[i-1];
            }
        }

        reverse(v.begin(),v.end());
        
        for(int i=0;i<v.size();i++)
        {
            if(v[i] < min_el)
            {
                min_el = v[i];
                right[i] = min_el;
            }
            else
            {
                right[i] = right[i-1];
            }
        }
        
        reverse(right.begin(),right.end());
 
        int i = 0;
        
        while(i < nums.size() - 1)
        {
            if(left[i] <= right[i+1])
            {
                return i+1;
            }
            
            i++;
        }
        
        return i+1;
    }   
    
};