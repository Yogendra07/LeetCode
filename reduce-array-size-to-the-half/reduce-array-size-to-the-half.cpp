class Solution 
{
public:
    int minSetSize(vector<int>& v) 
    {
        int n = v.size();
        
        int ans = 0;
        
        unordered_map<int,int> m;
                
        for(auto x : v)
            m[x]++;
        
        vector<int> vec;
        
        for(auto x : m)
        {
            vec.push_back(x.second);
        }
        
        sort(vec.begin(),vec.end(),greater<int>());
        
        int sum = 0;
        
        int i = 0;
        
        while(sum < n/2)
        {
            ans++;
            sum += vec[i++];
        }
        
        return ans;
        
    }
};