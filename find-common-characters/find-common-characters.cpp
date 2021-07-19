class Solution {
public:
    vector<string> commonChars(vector<string>& words) 
    {
        vector<string> ans;
        vector<int> v(26,INT_MAX);
        
        for(auto x : words)
        {
            vector<int> v1(26,0);
            
            for(int i=0;i<x.length();i++)
            {
                v1[x[i] - 'a']++;
            }
            
            for(int i=0;i<26;i++)
            {
                v[i] = min(v1[i],v[i]);
            }
        }
        
        for(int i=0;i<26;i++)
        {
            if(v[i] != 0)
            {
                char ch = i + 'a';
                
                while(v[i]--)
                {
                    string p = "";
                    p += ch;
                    ans.push_back(p);
                }
            }
        }
        
        return ans;
    }
};