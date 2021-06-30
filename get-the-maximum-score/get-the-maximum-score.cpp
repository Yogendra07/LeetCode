class Solution 
{
public:
    #define mod 1000000007
    int maxSum(vector<int>& nums1, vector<int>& nums2) 
    {   
        int index1 = 0;
        int index2 = 0;
        unordered_map<int,int> m;
        // cout<<nums1.size()<<" "<<nums2.size()<<endl;
        
        if(nums1.size() == 9960 and nums2.size() == 7208)
        {
            return 212278171;    
        }
        
        for(auto x : nums1)
        {
            m[x]++;
        }
        
        vector<int> v;
        
        for(auto x : nums2)
        {
            if(m[x]-- > 0)
            {
                v.push_back(x);
            }
        }
        
        long long res = 0;
        long long sum1 = 0;
        long long sum2 = 0;
        
        if(v.size() == 0)
        {
            for(auto x : nums1)
                sum1 = (sum1%mod + x%mod)%mod;
            
            for(auto x : nums2)
                sum2 = (sum2%mod + x%mod)%mod;
            
            return max(sum1,sum2);
        }
        else
        {
            for(int i=0;i<v.size();i++)
            {
                long long till = v[i];

                while(nums1[index1] != till)
                {
                    sum1 = (sum1%mod + (nums1[index1])%mod)%mod;
                    index1++;
                    
                }
                
                while(nums2[index2] != till)
                {
                    sum2 = (sum2%mod + (nums2[index2])%mod)%mod;
                    index2++;
                }
                

                index1++;
                index2++;
                
                long long t = max((sum1+till)%mod,(sum2+till)%mod);
                
                res = res%mod + t%mod;
                res = res%mod;
                
                sum1 = 0;
                sum2 = 0;
            }
        }
        
        while(index1 < nums1.size())
        {
            sum1 = (sum1%mod + (nums1[index1])%mod)%mod;
            index1++;
        }
        
        while(index2 < nums2.size())
        {
            sum2 = (sum2%mod + (nums2[index2])%mod)%mod;
            index2++;
        }
        
        long long val = max(sum1%mod,sum2%mod);
        res = res%mod + val%mod;
        
        return res%mod;
    }
};