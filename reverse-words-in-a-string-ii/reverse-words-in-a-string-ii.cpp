class Solution {
public:
    void reverseWords(vector<char>& s) 
    {
        vector<char> v;
        stack<char> st;
        
        for(int i=s.size()-1;i>=0;i--)
        {
            while(i >= 0 and s[i] != ' ')
            {
                st.push(s[i]);
                i--;
            }
            
            while(!st.empty())
            {
                char ch = st.top();
                v.push_back(ch);
                st.pop();
            }
            
            v.push_back(' ');
            
        }
        
        while(!st.empty())
        {
            char ch = st.top();
            v.push_back(ch);
            st.pop();
        }
        
        v.pop_back();
        
        s.clear();
        s = v;
        
    }
};