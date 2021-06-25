class Solution 
{
public:
    int find(int *parent,int i)
    {
        if(parent[i] == -1)
        {
            return i;
        }
        
        return find(parent,parent[i]);
    }
    
    void Union(int *parent,int x,int y)
    {
        parent[x] = y;
    }
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) 
    {
        vector<int> ans;
        int parent[1002];
        memset(parent,-1,sizeof(parent));
        
        for(vector<int> v : edges)
        {
            int x = v[0];
            int y = v[1];
            
            int val1 = find(parent,x);
            int val2 = find(parent,y);
            
            
            if(val1 == val2)
            {
                ans.push_back(x);
                ans.push_back(y);
                return ans;
            }
            
            Union(parent,val1,val2);
        
        }
        
        return ans;
    }
};