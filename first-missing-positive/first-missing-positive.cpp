class Solution 
{
public:
    
    int firstMissingPositive(vector<int>& nums) 
    {
        unordered_set<int> s;
        for(int i=0;i<nums.size();i++)
        {
            s.insert(nums[i]);
        }
        
        int k = s.size();
        int i = 1;
        while(i<=k)
        {
            if(s.find(i)==s.end())
            {
                return i;
            }
            else
            {
                
            }
            
            i++;
        }
        
        return i;
    }
    
};