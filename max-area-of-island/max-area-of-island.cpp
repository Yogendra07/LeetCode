class Solution 
{
public:
    int ans = 0;
    int var = 0;
    void dfs(vector<vector<int>> grid,int i,int j,int m,int n,vector<vector<int>> &visited)
    {
        if(i < 0 || j < 0 || j >= n || i >= m)
        {
            return;
        }
        
        if(visited[i][j] == 1)
        {
            return;
        }
        
        if(grid[i][j] == 0)
        {
            ans = max(ans,var);
            return;
        }
        
        visited[i][j] = 1;
        var++;

        dfs(grid,i+1,j,m,n,visited);
        dfs(grid,i,j+1,m,n,visited);    
        dfs(grid,i-1,j,m,n,visited);    
        dfs(grid,i,j-1,m,n,visited);    
        
    
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) 
    {
        int m = grid.size();
        int n = grid[0].size();
            
        vector<vector<int>> visited(m,vector<int> (n,0));
        
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j] == 1 and visited[i][j] != 1)
                {
                    dfs(grid,i,j,m,n,visited);
                }
                
                ans = max(var,ans);
                var = 0;
            }
        }
        
        return ans;
    }
};