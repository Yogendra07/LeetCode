class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) 
    {
        int m = mat.size();
        int n = mat[0].size();
        
        vector<vector<int>> ans(r,vector<int> (c,0));
                
        if((m*n != r*c))
        {
            return mat;
        }
        
        vector<int> v;
        
        for(auto x : mat)
        {
            for(auto y : x)
            {
                v.push_back(y);
            }
        }
        
        int val = 0;
        
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                ans[i][j] = v[val];
                val++;
            }
        }
        
        return ans;
        
    }
};