class Solution {
    public int longestConsecutive(int[] nums) 
    {
        if(nums.length == 0)
        {
            return 0;
        }
        
        Arrays.sort(nums);    
        
        int current_streak = 1;
        int longest_streak = 1;
        
        for(int i=1;i<nums.length;i++)
        {
            if(nums[i] != nums[i-1])
            {
                if(nums[i] == nums[i-1] + 1)
                {
                    current_streak +=1;
                }
                else
                {
                    longest_streak = Math.max(longest_streak,current_streak);
                    current_streak  = 1;
                }
            }
        }
        
        return Math.max(current_streak,longest_streak);
    }
    
}