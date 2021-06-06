class Solution {
public:
    int longestConsecutive(vector<int>& nums) 
    {
        unordered_set<int> s(nums.begin(),nums.end());
        int max_len = 0;
        
        for(auto x : s)
        {
            if(s.find(x-1) != s.end())
            {
                continue;
            }
            
            int len = 1;
            
            while(s.find(x+len) != s.end())
            {
                len++;
            }
            
            max_len = max(max_len,len);
        }
        
        return max_len;
    }
};