class Solution 
{
public:
    string longestCommonPrefix(vector<string> &v) 
    {
        if(v.size() == 0)
        {
            return "";
        }
        
        int len = v[0].length();
        for(int i=1;i<v.size();i++)
        {
            if(v[i].length() <= v[i-1].length())
            {
                len = v[i].length();
            }
        }
        
        string ans = "";
        int j = 0;
        for(int i=0;i<len;i++)
        {
            char ch = v[0][i];
            for(j=1;j<v.size();j++)
            {
                if(v[j][i] != v[j-1][i])
                {
                    return ans;
                }
            }
            
            ans += v[j-1][i];
            
        }
        
        return ans;
        
    }
};