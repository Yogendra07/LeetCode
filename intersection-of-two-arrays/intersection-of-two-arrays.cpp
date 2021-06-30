class Solution 
{
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) 
    {
        vector<int> ans;
        
        set<int> s1;
        set<int> s2;
        
        for(auto x : nums1)
        {
            s1.insert(x);
        }
        
        for(auto x : nums2)
        {
            s2.insert(x);
        }
        
        if(nums1.size() < nums2.size())
        {
            for(auto x : s2)
            {
                if(s1.find(x) != s1.end())
                {
                    ans.push_back(x);
                }
            }
        }
        else
        {
            for(auto x : s1)
            {
                if(s2.find(x) != s2.end())
                {
                    ans.push_back(x);
                }
            }
        }

        return ans;        
        
    }
};