class Solution {
public:
    bool backspaceCompare(string s, string t) 
    {
        stack<char> S;
        
        for(int i=0;i<s.length();i++)
        {
            if(s[i] != '#')
            {
                S.push(s[i]);
            }
            else
            {
                if(!S.empty())
                {
                    S.pop();
                }
            }
        }
        
        s = "";
        
        while(!S.empty())
        {
            s += S.top();
            S.pop();
        }
        
        for(int i=0;i<t.length();i++)
        {
            if(t[i] != '#')
            {
                S.push(t[i]);
            }
            else
            {
                if(!S.empty())
                {
                    S.pop();
                }
            }
        }
        
        t = "";
        
        while(!S.empty())
        {
            t += S.top();
            S.pop();
        }
        
        if(s == t)
        {
            return true;
        }
        else
        {
            return false;
        }
        
        return false;
    }
};