class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& v) 
    {
        vector<vector<string>> ans;
        unordered_map<string,vector<string>> m;
        
        for(int i=0;i<v.size();i++)
        {
            string s = v[i];
            sort(s.begin(),s.end());
            
            m[s].push_back(v[i]);
        }
        
        for(auto x : m)
        {
            vector<string> helper;
            
            for(auto y : x.second)
            {
                helper.push_back(y);
            }
            
            ans.push_back(helper);
        }
        
        return ans;
    }
};