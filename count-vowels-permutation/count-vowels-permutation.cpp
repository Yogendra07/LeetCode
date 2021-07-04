class Solution 
{
public:
    #define mod 1000000007
    int countVowelPermutation(int n) 
    {
        long long a = 1,e = 1,i = 1,o = 1,u = 1;
        
        long long ans = 0;
        
        long long prev_a = 0 , prev_e = 0 , prev_o = 0 ,prev_i = 0 , prev_u = 0;
        
        for(int k=1;k<=n;k++)
        {
            ans = (a%mod + e%mod + i%mod + o%mod + u%mod)%mod;
            
            prev_a = a;
            prev_e = e;
            prev_i = i;
            prev_o = o;
            prev_u = u;
            
            a = (prev_e%mod + prev_i%mod + prev_u%mod)%mod;
            e = (prev_a%mod + prev_i%mod)%mod;
            i = (prev_e%mod + prev_o%mod)%mod;
            o = prev_i%mod;
            u = (prev_i%mod + prev_o%mod)%mod;
            
        }
        
        return ans%mod;
    }
};