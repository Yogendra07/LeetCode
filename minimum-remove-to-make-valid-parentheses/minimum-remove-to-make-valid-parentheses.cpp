class Solution {
public:
    string minRemoveToMakeValid(string s) 
    {
        stack<pair<char,int>> st;
        
        for(int i=0;i<s.length();i++)
        {
            if(s[i] == '(')
            {
                st.push({s[i],i});
            }
            else
            {
                if(s[i] == ')')
                {
                    if(st.empty())
                    {
                        s.erase(s.begin() + i);
                        i--;

                    }
                    else if(!st.empty())
                    {
                        st.pop();
                    }
                }
            }
        }
        
        
        if(!st.empty())
        {
            while(!st.empty())
            {
                int val = st.top().second;
                s.erase(s.begin()+val);
                st.pop();
            }
        }
        
        return s;
    }
};