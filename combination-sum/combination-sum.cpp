class Solution 
{
public:
    vector<vector<int>> ans;
    
    void dfs(vector<int>& candidates,vector<int>& v,int i,int target)
    {
        if(target < 0)
        {
            return;
        }
        
        if(i == candidates.size())
        {
            return;
        }
        
        if(target == 0)
        {
            ans.push_back(v);   
        }
        
        for(int k=i;k<candidates.size();k++)
        {
            v.push_back(candidates[k]);
            dfs(candidates,v,k,target-candidates[k]);
            v.pop_back();
        }
           
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        vector<int> v;
        
        dfs(candidates,v,0,target);
        
        return ans;
    }
};