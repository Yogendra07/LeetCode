class Solution 
{
public:
    vector<string> ans;
    void brackets(int n,int open,int close,string s)
    {
        if(close > open)
        {
            return;
        }
        
        if(open > n || close > n)
        {
            return;
        }
        
        if(open == n and close == n)
        {
            ans.push_back(s);
        }
        
        brackets(n,open+1,close,s + '(');
        brackets(n,open,close+1,s + ')');
        
    }
    vector<string> generateParenthesis(int n) 
    {
        string s = "";
        brackets(n,0,0,s);
        return ans;
    }
};