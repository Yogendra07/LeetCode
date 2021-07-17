class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k)
    {   
        vector<vector<int>> ans;
        map<pair<int,int>,pair<int,int>> m;
        
        for(int i=0;i<points.size();i++)
        {
            int x = points[i][0];
            int y = points[i][1];
            
            int dis = x*x + y*y;            
            m[{dis,i}] = {x,y};
        }
        
        // for(auto x : m)
        // {
        //     cout<<x.first<<"--> {"<<x.second.first<<","<<x.second.second<<"}"<<endl;
        // }
        
        for(auto x : m)
        {
            if(k == 0)
            {
                break;
            }
            else
            {
                k--;
            }
            
            int val1 = x.second.first;
            int val2 = x.second.second;
            
            vector<int> v;
            
            v.push_back(val1);
            v.push_back(val2);
            
            ans.push_back(v);
            
        }
        
        return ans;
    }
};