class Solution 
{
    public int longestConsecutive(int[] nums) 
    {
        if(nums.length == 0)
        {
            return 0;
        }
        
        Set<Integer> s = new HashSet<Integer>();
        
        for(int x : nums)
        {
            s.add(x);
        }
        
         int max_len = 0;
        
        for(int num : s)
        {
            if(s.contains(num-1))
            {
                continue;
            }
            
            int len = 1;
            
            while(s.contains(num + len))
            {
                len++;
            }
            
            max_len = Math.max(max_len,len);
            
        }
        
        return max_len;
    }
}
