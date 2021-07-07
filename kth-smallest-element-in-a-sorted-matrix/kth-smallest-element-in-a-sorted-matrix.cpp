class Solution 
{
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) 
    {
        int ans = 0;
        multimap<int,int> m;
        vector<int> v;
        
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix.size();j++)
            {
                m.insert({matrix[i][j],1});
            }
        }
        
        for(auto x : m)
        {
            v.push_back(x.first);
        }
        
        return v[k-1];
    }
};